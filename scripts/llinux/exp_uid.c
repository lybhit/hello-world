#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  printf("uid=%d, euid=%d\n", getuid(),geteuid());
  printf("gid=%d, egid=%d\n", getuid(),geteuid());
  return 0;

}
