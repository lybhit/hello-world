#include <iostream>
#include <stdlib.h>
#include <linux/can.h>

using namespace std;
int main(int argc, char **argv) {
  struct can_frame a;
  a.can_dlc = 8;
  a.can_id = 0x401;
  for(int i = 0; i < 8; ++i)
    a.data[i] = 0;
  
  cout << sizeof(struct can_frame) << endl;
  cout << sizeof(a) << endl;
    
  std::cout << "Hello, world!" << std::endl;
  return 0;
}
