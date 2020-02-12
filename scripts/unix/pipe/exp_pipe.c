#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main()
{
  int pfd[2];
  char buf[81];
  if(pipe(pfd) == -1)
  {
	perror("pipe");
	exit(EXIT_FAILURE);
  }

  printf("The pipe will read from %d, write to %d.\n", pfd[0], pfd[1]);
  write(pfd[1], "this is write to pipe!\n", 23);
  read(pfd[0], buf, 23);
  printf("%s", buf);
}
