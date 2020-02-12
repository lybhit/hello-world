#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
  int pid, fd;
  char buf[80];
  mkfifo("fifotest", 0644);
  if((pid = fork()) > 0)
  {
	fd = open("fifotest", O_WRONLY);
	write(fd, "message to test FIFO!", 22);
	close(fd);
	exit(EXIT_SUCCESS);
  }
  else if(pid == 0)
  {
	fd = open("fifotest", O_RDONLY);
	read(fd, buf, 80);
	printf("%s\n", buf);
	close(fd);
	exit(EXIT_SUCCESS);
  }
}
