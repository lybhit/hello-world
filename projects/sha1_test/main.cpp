#include <iostream>
#include <string.h>
#include <boost/uuid/sha1.hpp>

using namespace boost::uuids::detail;
using namespace std;

int main(int argc, char **argv) {
  sha1 sha;
  
  char *szMsg = "a short message";
  sha.process_byte(0x10);
  sha.process_bytes(szMsg, strlen(szMsg));
  sha.process_block(szMsg, szMsg+ strlen(szMsg));
  
  unsigned int digest[5];
  sha.get_digest(digest);
  for(int i = 0; i < 5; ++i)
  {
    cout << hex << digest[i] << endl;
  }
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
