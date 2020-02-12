#include <iostream>
#include <cmath>
#include <algorithm>
#include <boost/utility/result_of.hpp>
#include <boost/typeof/typeof.hpp>

using namespace boost;
using namespace std;

template<typename T, typename T1>
typename boost::result_of<T(T1)>::type call_func(T t, T1 t1)
{
  return t(t1);
}

int main(int argc, char **argv) {
  
  typedef double (*Fun)(double d);
  Fun func = std::sqrt;
  
  boost::result_of<Fun(double)>::type x = func(5.0);
  cout << typeid(x).name() << endl;
  
  BOOST_AUTO(y, call_func(func, 6.0));
  cout << y << endl;
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
