#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	/* code */

	int fd1,fd2, ret1,ret2;

	fd1 = open("ioOut.txt",O_CREAT | O_APPEND | O_RDWR);
	fd2 = open("ioErr.txt",O_CREAT | O_APPEND | O_RDWR);

	if(fd1 < 0)
	{
		perror("open() out: ");
		close(fd1);
		exit(1);
	}

	if(fd2 < 0)
	{
		perror("open() error: ");
		close(fd2);
		exit(1);
	}

	ret1 = dup2(fd1,1);
	if(ret1 == -1)
	{
		perror("dup2 out: ");
		close(fd1);
		exit(1);
	}

	ret2 = dup2(fd2,2);
	if(ret2 == -1)
	{
		perror("dup2 error: ");
		close(fd2);
		exit(1);
	}

	system("ls /tmp /tmp3");

	close(fd1);
	close(fd2);

	return 0;
}