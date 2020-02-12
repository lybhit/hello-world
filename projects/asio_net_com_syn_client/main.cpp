#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace boost::asio;
using namespace std;

class a_timer
{
private:
  int count, count_max;
  boost::function<void()> f;
  deadline_timer t;
public:
  template<typename F>
  a_timer(io_service& ios, int x, F func):f(func),count(0),count_max(x),
    t(ios, boost::posix_time::millisec(500))//启动计时器
    {
      //异步等待计时器，注册回调函数
      t.async_wait(bind(&a_timer::call_func,this,boost::asio::placeholders::error));
    }
    
  void call_func(const boost::system::error_code&)
  {
    if(count >= count_max)
    { return; }
    ++count;
    f();
    //设置定时器的终止时间为0秒之后
    t.expires_at(t.expires_at() + boost::posix_time::millisec(500));
    //再次启动定时器，异步等待
    t.async_wait(bind(&a_timer::call_func, this, boost::asio::placeholders::error));
  }
};

void client(io_service& ios)
{
  try
  {
    cout << "client start." << endl;
    
    ip::tcp::socket sock(ios);
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"),6688);
    
    sock.connect(ep);
    
    vector<char> str(100, 0);
    sock.read_some(buffer(str));
    cout << "receive from" << sock.remote_endpoint().address();
    cout << &str[0] << endl;
  }
  catch(std::exception& e)
  {
    cout << e.what() << endl;
  }
}

int main(int argc, char **argv) {
  io_service ios;
  a_timer at(ios, 5, bind(client, ref(ios)));
  ios.run();
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
