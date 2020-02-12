#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
  int fd;
  char buf[80];
  close(0);
  if((fd = open("./text.txt", O_RDONLY))!= 0)
  {
    perror("open");
    exit(EXIT_FAILURE);
  }
  read(0,buf,80);
  write(1,buf,80);
}
