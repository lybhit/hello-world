#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <unistd.h>

using namespace std;

boost::mutex lock;
int num = 100;

void helloA()
{
  cout << "I am thread A!" << boost::this_thread::get_id() << "---Start" << endl;
  lock.lock();
  num++;
  cout << num << endl;
  sleep(3);
  lock.unlock();
  cout << "I am thread A! ---OVER" << endl;
}
void helloB()
{
  cout << "I am thread B!" << boost::this_thread::get_id() << "---Start" << endl;
  lock.lock();
  num++;
  cout << num << endl;
  sleep(3);
  lock.unlock();
  cout << "I am thread B! ---OVER" << endl;
}
int main(int argc, char **argv) {
  cout << boost::thread::hardware_concurrency() << endl; 
  boost::thread thrdA(&helloA);
  boost::thread thrdB(&helloB);
  
  thrdA.join();
  thrdB.join();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
