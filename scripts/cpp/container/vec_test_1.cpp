#include <iostream>
#include <vector>

using namespace std;

void vec_alloc()
{
  vector<vector<double> > vec_set;
  cout << vec_set.size() << endl;

  vector<double> temp;  
  for(int i = 0; i < 10; i++)
  {
    
    for(int j = 0; j < 10; j++)
    {
      temp.push_back(100);
    }
    vec_set.push_back(temp);
    
  }
  
  for(int i = 0; i < 10; i++)
  {
    
    for(int j = 0; j < 10; j++)
    {
      cout << " vec_set[i].at(j) = " << (vec_set[i])[j] << endl;
    }
    
  }
  
  cout << "ok" << endl;
}

int main()
{
    vec_alloc();

  return 0;
}
