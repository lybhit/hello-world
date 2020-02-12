#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace Eigen;
using namespace std;
int main()
{
  bool a = (Array2i(0, 0) <= Array2i(1,2)).all();
  
  cout << "a =" << a << endl;
  cout << Vector2d::Ones() << endl;
  return 0;
}
