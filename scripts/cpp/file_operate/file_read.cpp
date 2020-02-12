#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
int main(int argc, char** argv)
{
  ifstream infile;   //输入流

  std::string str = "/home/suirui/scan_tools/src/laser_scan_matcher/data";
  std::string str_1 = ".txt";

  str += argv[1];
  str += str_1;

  const char* p = str.c_str();

  infile.open(p, ios::in); 

  if(!infile.is_open ())
  {
    cout << "Open file failure" << endl;
  }

  char data[10];
  infile >> data;

  unsigned int nrays;
  float v;

  infile >> nrays;
  cout << "nrays = " << nrays << endl;

  std::vector<float> vec_data;
  int counter = 0;

  while (!infile.eof() && counter < nrays)            // 若未到文件结束一直循环
  {
      infile >> v;
      vec_data.push_back(v); 
      cout << v <<endl;

      counter++;               
  }
  infile.close();   //关闭文件
  cout << "counter = " << counter << endl;
  return 0;
}
