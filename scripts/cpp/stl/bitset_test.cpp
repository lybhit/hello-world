#include <iostream>
#include <bitset>

int main()
{
  std::bitset<4> foo;
  
  foo[1] = 1;
  foo[2] = foo[1];

  std::cout << "foo: " << foo << '\n';

  return 0;
}
