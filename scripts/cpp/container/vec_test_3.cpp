#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> a;
  a.reserve(100);
  
  cout << "a size = " << a.size() << '\n';

  a.emplace_back(10);
  
  cout << "after emplace, a size = " << a.size() << '\n';

  return 0;
}
