#include <iostream>
#include <vector>
#include <algorithm>
#include "boost/lambda/lambda.hpp"

int main()
{
  using namespace boost::lambda;
  std::vector<int> vec(3);

  vec[0] = 1;
  vec[1] = 2;
  vec[2] = 3;
  std::for_each(vec.begin(), vec.end(), _1 += 10);
  std::for_each(vec.begin(), vec.end(), _1 -= 10);
  std::for_each(vec.begin(), vec.end(), _1 *= 10);
  std::for_each(vec.begin(), vec.end(), _1 /= 10);
  std::for_each(vec.begin(), vec.end(), _1 %= 10);
}
