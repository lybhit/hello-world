#include <iostream>
#include <boost/typeof/typeof.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
using namespace std;

namespace ex
{
  struct demo_class{int a, b;};
}//namespace ex

BOOST_TYPEOF_REGISTER_TYPE(ex::demo_class);

int main(int argc, char **argv) {
  BOOST_AUTO(x, make_pair("test", ex::demo_class()));
  cout << typeid(x).name() << endl; 
  x.second.a = 10;
  x.second.b = 20;
  cout << x.second.a << x.second.b << endl;
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
