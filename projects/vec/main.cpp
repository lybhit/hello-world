#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
using namespace std;

void AddValue(deque<float>& input, const float value) {
    while (!input.empty() &&
           value > input.back()) {
      input.pop_back();
    }
    input.push_back(value);
  }


int main(int argc, char **argv) {
  
  float b = 5.3;
  float c = 6.6;
  int d = std::lround(b);
  cout << d << endl;
  
  int e = std::lround(c);
  cout << e << endl;
  string a = "hello world";
  std::cout << a << std::endl;
  
  vector<float> vv = {1,3,-2,4,-6,9,5,8,3};
  deque<float> cc = {2};
  
  for(int i = 0; i < vv.size(); ++i)
  {
    AddValue(cc, vv[i]);
  }
  
  for(float& elem : cc)
  {
    cout << elem << endl;
  }
  
  
  
  return 0;
}
