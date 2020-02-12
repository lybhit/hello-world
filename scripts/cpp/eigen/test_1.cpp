#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace Eigen;
using namespace std;
int main()
{
  Array2i a(3,4);
//  a.matrix();
  cout << a.matrix() << endl;
  return 0;
}
