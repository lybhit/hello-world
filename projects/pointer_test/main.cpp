#include <iostream>
#include <stdint.h>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
  
  uint8_t a = 10;
  uint8_t *b = &a;
  cout << reinterpret_cast<int*>(b) << endl;
  
  uint8_t c[10] = {1,2,3,4,5,6,7,8,9,10};
  uint8_t *pp = &(c[5]);
  uint8_t d = pp[-2];
  
  cout << static_cast<int>(d) << endl;
  
  cout << sizeof(c) << endl;
  
  uint8_t *gg = new uint8_t[100];
  for(int i = 0; i < 100; ++i)
  {
    gg[i] = 1;
  }
  cout << "gg size is " << sizeof(gg) << endl;
  
  cout << "size of uint8_t = " << sizeof(uint8_t) << endl;
  
  delete[] gg;
  
  stringstream str;
  str << "../data" << 1 << ".txt";
  cout << str.str() << endl;
  
 
  return 0;
}
