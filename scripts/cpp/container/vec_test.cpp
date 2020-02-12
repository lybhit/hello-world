#include <iostream>
#include <vector>

using namespace std;

void vec_alloc()
{
  vector<double> vec_set;
  vec_set.resize(10000);
  for(int i = 0; i < 10000; i++)
  {
    vec_set[i] = 100;
  }
  cout << "ok" << endl;
}

int main()
{
  for(int i = 0; i < 1000; i++)
  {
    vec_alloc();
  }

  return 0;
}
