#include <iostream>
#include <stack>
#include <boost/thread.hpp>
#include <ctime>

using namespace std;
using namespace boost;

mutex io_mu;

class buffer
{
private:
  mutex mu;
  condition_variable_any cond_put;
  condition_variable_any cond_get;
  stack<int> stk;
  int un_read, capacity;
  bool is_full()
  {
    return un_read == capacity;
  }
  bool is_empty()
  {
    return un_read == 0;
  }
public:
  buffer(size_t n):un_read(0),capacity(n){}
  void put(int x)
  {
    {
      mutex::scoped_lock lock(mu);
      while(is_full())
      {
        {
          mutex::scoped_lock lock(io_mu);
          cout << "full waiting..." << endl;
        }
        cond_put.wait(mu);
      }
      stk.push(x);
      ++un_read;
    }
    cond_get.notify_one();
  }
  void get(int *x)
  {
    {
      mutex::scoped_lock lock(mu);
      while(is_empty())
      {
        {
          mutex::scoped_lock lock(io_mu);
          cout << "empty waiting..." << endl;
        }
        cond_get.wait(mu);
      }
      --un_read;
      *x = stk.top();
      stk.pop();
    }
    cond_put.notify_one();
  }
};

buffer buf(5);
void producer(int n)
{
  for(int i = 0; i < n; ++i)
  {
    {
      mutex::scoped_lock lock(io_mu);
      cout << "put" << i << endl;
    }
    buf.put(i);
  }
}

void consumer(int n)
{
  int x;
  for(int i = 0;i < n; ++i)
  {
    buf.get(&x);
    mutex::scoped_lock lock(io_mu);
    cout << "get" << x << endl;
  }
}

int main(int argc, char **argv) {
  thread t1(producer, 20);
  thread t2(consumer, 10);
  thread t3(consumer, 10);
  
  t1.join();
  t2.join();
  t3.join();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
