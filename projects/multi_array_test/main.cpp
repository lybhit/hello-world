#include <iostream>
#include <boost/multi_array.hpp>
#include <array>

using namespace boost;
using namespace std;

int main(int argc, char **argv) {
  multi_array<int, 3> ma(extents[2][3][4]);
  for(int i = 0, v = 0; i < 2; ++i)
    for(int j = 0; j < 3; ++j)
      for(int k = 0; k < 4; ++k)
      {
        ma[i][j][k] = v++;
      }
  
  for(int i = 0; i < 2; ++i)
  {
    for(int j = 0; j < 3; ++j)
    {
      for(int k = 0; k < 4; ++k)
      {
        cout << ma[i][j][k] << ",";
      }
      cout << endl;
    }
    
    cout << endl;
      
  }
    
  std::array<size_t, 3> idx = {0,1,2};
  ma(idx) = 10;
  cout << ma(idx);
  
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
