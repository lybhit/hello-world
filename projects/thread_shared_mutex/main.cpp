#include <iostream>
#include <boost/thread.hpp>
#include <boost/core/ref.hpp>
#include <ctime>

using namespace std;
using namespace boost;

mutex io_mu;

class rw_data
{
private:
  int m_x;
  shared_mutex rw_mu;
public:
  rw_data():m_x(0){}
  void write()
  {
    unique_lock<shared_mutex> ul(rw_mu);
    ++ m_x;
  }
  void read(int *x)
  {
    shared_lock<shared_mutex> sl(rw_mu);
    *x = m_x;
  }
};

void writer(rw_data &d)
{
  for(int i = 0; i < 20; ++i)
  {
    this_thread::sleep(posix_time::millisec(10));
    d.write();
  }
}

void reader(rw_data &d)
{
  int x;
  for(int i = 0; i < 10; ++i)
  {
    this_thread::sleep(posix_time::millisec(5));
    d.read(&x);
    mutex::scoped_lock lock(io_mu);
    cout << "reader:" << x << endl;
  }
}

int main(int argc, char **argv) {
  rw_data d;
  thread_group pool;
  
  pool.create_thread(bind(reader, boost::ref(d)));
  pool.create_thread(bind(reader, boost::ref(d)));
  pool.create_thread(bind(reader, boost::ref(d)));
  pool.create_thread(bind(reader, boost::ref(d)));
  pool.create_thread(bind(writer, boost::ref(d)));
  pool.create_thread(bind(writer, boost::ref(d)));
  
  pool.join_all();
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
