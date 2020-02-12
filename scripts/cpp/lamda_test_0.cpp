#include <iostream>
#include "boost/lambda/lambda.hpp"
#include "boost/function.hpp"

int main()
{
  using namespace boost::lambda;
  (std::cout << _1 << ' ' << _3 << ' ' << _2 << "!\n")
    ("Hello", "friend", "my");

  boost::function<void(int, int, int)> f =
    std::cout << _1 << "*" << _2 << "+" << _3 << "=" << _1 * _2 + _3 << "\n";

  f(1,2,3);
  f(3,2,1);
}
