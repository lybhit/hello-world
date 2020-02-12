#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <assert.h>

using namespace std;
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;
my_tuple func()
{
  return boost::make_tuple(1, 2.0, "string");
}

int main(int argc, char **argv) {
  my_tuple t1(1, 100., "abc");
  my_tuple t2(1, 200., "def");
  
  assert(t1 < t2);
  
  my_tuple t3(t2);
  assert(t2 == t3);
  
  cout << t1.get<0>() << endl;
  cout << t1.get<1>() << endl;
  cout << t1.get<2>() << endl;
  
  //7.6.6 输入输出
  cout << t3 << endl;
  
  cout << tuples::set_open('[') << tuples::set_close(']');
  cout << tuples::set_delimiter(',');
//   cout << "please input tuple";
//   cin >> t3;
  cout << t3 << endl;
  
  //7.6.7 连结变量
  int i;
  double d;
  string s;
  tie(i, d, s) = func();
  
  cout << i << endl;
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
