#include <iostream>
#include <Eigen/Dense>
#include <fstream>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv)
{
  double val;
  double vec[9];
  ifstream infile; //输入流

  infile.open("/home/suirui/scripts/cpp/Rot2Quat/data.txt", ios::in);
  if(!infile.is_open ())
    cout << "Open file failure" << endl;
  
  int i = 0;
  while (!infile.eof())            // 若未到文件结束一直循环
  {
    infile >> val;
    vec[i] = val;
    ++i;
  }
  infile.close();
  Matrix3d t_R = Eigen::Matrix3d::Identity();
//  t_R(0,0) = -0.498664149424961;
//  t_R(0,1) = 0.2277529422328564;
//  t_R(0,2) = -0.8363388448365634;
//  t_R(1,0) = 0.5625229857537684;
//  t_R(1,1) = -0.6490510953427268;
//  t_R(1,2) = -0.5121528737916761;
//  t_R(2,0) = -0.6594709671979095;
//  t_R(2,1) = -0.7258521012841967;
//  t_R(2,2) = 0.1955422473133882;

  t_R(0,0) = vec[0];
  t_R(0,1) = vec[1];
  t_R(0,2) = vec[2];
  t_R(1,0) = vec[3];
  t_R(1,1) = vec[4];
  t_R(1,2) = vec[5];
  t_R(2,0) = vec[6];
  t_R(2,1) = vec[7];
  t_R(2,2) = vec[8];

  Vector3d eulerAngle = t_R.matrix().eulerAngles(2,1,0);

  cout << "eulerAngles = " << '\n' << eulerAngle << endl;

  Quaterniond t_Q(t_R);

  cout << "Quaternion" << endl << t_Q.coeffs() <<endl;

  return 0;
  
}
