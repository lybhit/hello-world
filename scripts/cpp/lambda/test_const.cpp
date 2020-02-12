#include <iostream>
#include <vector>
#include <algorithm>
#include "boost/lambda/lambda.hpp"

int main()
{
  using boost::lambda::constant;
  using boost::lambda::constant_type;
  constant_type<char>::type newline(constant('\n'));
  constant_type<char>::type space(constant(' '));

  boost::lambda::placeholder1_type _;
  
  std::vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  std::for_each(vec.begin(),vec.end(), std::cout << space << _ << newline);

  std::for_each(vec.begin(),vec.end(),  std::cout << constant(' ') << _ << constant('\n'));
  
  return 0;
}
