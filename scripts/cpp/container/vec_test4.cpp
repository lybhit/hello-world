#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
  vector<int> a = {1,2,8,9,199,23,-1,666,33};
  sort(a.begin(), a.end());
  
  auto it = a.begin();
  while(it != a.end())
  {
    cout << *it << endl;
    it++;
  }
  return 0;
}
