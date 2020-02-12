#include <iostream>
#include <boost/circular_buffer.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign.hpp>
#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost;

template<typename T>
void print(T& cb)
{
  for(BOOST_AUTO(pos, cb.begin()); pos != cb.end(); ++pos)
  {
    cout << *pos << ",";
  }
  cout << endl;
}

int main(int argc, char **argv) {
  
  circular_buffer<int> cb(5);
  assert(cb.empty());
  
  cb.push_back(1);
  cb.push_front(2);
  assert(cb.front() == 2);
  cb.insert(cb.begin(), 3);
  
  print(cb);
  
  cb.pop_front();
  assert(cb.size() == 2);
  print(cb);
  cb.push_back();
  assert(cb[0] == 2);
  print(cb);
  cb.push_front(3);
  print(cb);
  
  using namespace boost::assign;
  circular_buffer<int> cb1 = (list_of(1), 2, 3);
  circular_buffer<int> cb2 = (list_of(3),4,5);
  circular_buffer<int> cb3 = cb1;
  
  assert(cb1 < cb2);
  assert(cb1 == cb3);
  
  //7.5.3环形缓冲区
  circular_buffer<int> cb4 = (assign::list_of(1),2,3,4,5);
  assert(cb4.full());
  print(cb4);
  
  int *p = cb4.linearize();
  assert(p[0] == 1 && p[3] == 4);
  
  cb4.rotate(cb4.begin() + 2);
  print(cb4);
      
  
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
