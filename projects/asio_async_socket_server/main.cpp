#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace boost::asio;
using namespace std;

class server
{
private:
  io_service &ios;
  ip::tcp::acceptor acceptor;
  typedef shared_ptr<ip::tcp::socket> sock_pt;
  
public:
  server(io_service& io): ios(io),
    acceptor(ios, ip::tcp::endpoint(ip::tcp::v4(),6688))
  {
    start();
  }
  
  void start()
  {
    sock_pt sock(new ip::tcp::socket(ios));
    
    acceptor.async_accept(*sock, bind(&server::accept_hander, this, boost::asio::placeholders::error, sock));
  }
  
  void accept_hander(const boost::system::error_code& ec, sock_pt sock)
  {
    if(ec)
    { return; }
    
    cout << "client:";
    cout << sock->remote_endpoint().address() << endl;
    sock->async_write_some(buffer("hello asio"),
      bind(&server::write_handler, this, boost::asio::placeholders::error));
    
    start();
  }
  
  void write_handler(const boost::system::error_code&)
  {
    cout << "send msg complete." << endl;
  }
  
};

int main(int argc, char **argv) {
  try
  {
    cout << "server start." << endl;
    io_service ios;
    
    server serv(ios);
    ios.run();
  }
  catch(std::exception& e)
  {
    cout << e.what() << endl;
  }
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
