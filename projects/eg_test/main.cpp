#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

using namespace Eigen;
using namespace std;

int main(int argc, char **argv) {
//   MatrixXd m = MatrixXd::Random(3,3);
//   m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
//   cout << "m = " << endl << m << endl;
//   
//   VectorXd v(3);
//   v << 1, 2, 3;
//   cout << "m * v =" << endl << m * v << endl;
  
  Translation2f initial_pose(3.5, 1.0);
  Vector3f point(1.0, 2.0, 0);
  
  Vector2f translated_point = Affine2f(initial_pose) * point.head<2>();
  cout << "translated_point = " << translated_point << endl;
  
  Array2i min_bound = Array2i::Zero();
  Array2i max_bound = Array2i::Zero();

  
  vector<Array2i> scan;
  scan.push_back(Array2i(2, 2));
  scan.push_back(Array2i(6, 6));
  
  for(Array2i& xy_index : scan)
  {
    cout << "ok" << endl;
    cout << xy_index << endl;
    min_bound.min(-xy_index);
    max_bound.max(Array2i(10, 10) - xy_index);
  }
  
  cout << min_bound << endl << max_bound;
  return 0;
}
