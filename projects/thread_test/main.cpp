#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_guard.hpp>

boost::mutex mutex;
boost::mutex io_mutex;

int count = 0;

void Counter(){
  int i;
  {
    boost::unique_lock<boost::mutex> lock(mutex);
    i = ++count;
  }
  
  {
    boost::unique_lock<boost::mutex> lock(io_mutex);
    std::cout << "cout = " << i << std::endl;
  }
}

int main(int argc, char **argv) {
  boost::thread_group threads;
  for(int i = 0; i < 4; ++i)
  {
    threads.create_thread<void>(&Counter);
  }
  threads.join_all();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
