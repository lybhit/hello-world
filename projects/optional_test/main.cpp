#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <boost/optional.hpp>

using namespace boost;
using namespace std;

optional<double> calc(int x)
{
  return optional<double>(x != 0, 1.0 / x);
}
optional<double> sqrt_op(double x)
{
  return optional<double>(x > 0, sqrt(x));
}

int main(int argc, char **argv) {
  optional<string> ops("test");
  cout << *ops << endl;
  
  vector<int> v(10);
  optional<vector<int>& > opv(v);
  assert(opv);
  
  opv->push_back(5);
  assert(opv->size() == 11);
  
  optional<double> d = calc(10);
  if(d){
    cout << *d << endl;
  }
  
  d = sqrt_op(-10);
  if(!d){
    cout << "no result" << endl;
  }
  
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
