#include <iostream>
#include <vector>
#include <functional>
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/bind.hpp"

using namespace std;
void plain_function(int i)
{
  cout << "void plain_function(" << i << ")\n";
}

class some_class {
public:
  void member_function(int i) const {
    cout << "void some_class::member_function(" << i << ") const\n";
  }
};

int main()
{
  vector<int> vec(3);
  vec[0] = 12;
  vec[1] = 10;
  vec[2] = 7;
  some_class sc;
  some_class* psc = &sc;

  //bind to a free function using ptr_fun
  for_each(
    vec.begin(),
    vec.end(),
    std::ptr_fun(plain_function));

  //bind to a member function using mem_fun_ref
  for_each(vec.begin(), vec.end(),
    std::bind1st(
      std::mem_fun_ref(&some_class::member_function), sc));

  //bind to a member function using mem_fun
  std::for_each(vec.begin(), vec.end(),
    std::bind1st(
      std::mem_fun(&some_class::member_function), psc));

  using namespace boost::lambda;
  std::for_each(
    vec.begin(),
    vec.end(),
    bind(&plain_function, _1));

  std::for_each(vec.begin(), vec.end(),
    bind(&some_class::member_function, sc, _1));

  std::for_each(vec.begin(), vec.end(),
    bind(&some_class::member_function, psc, _1));

}
