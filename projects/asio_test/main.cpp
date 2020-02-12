#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <boost/system/error_code.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::asio;


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

void print1()
{
  cout << "hello asio" << endl;
}

void print2()
{
  cout << "hello boost" << endl;
}
int main(int argc, char **argv) {
  io_service ios;
  a_timer at1(ios, 5, print1);
  a_timer at2(ios, 5, print2);
  ios.run();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
