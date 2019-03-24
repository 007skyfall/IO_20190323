#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 32

int main(int argc, const char *argv[])
{
	int fd_r = open(argv[1], O_RDONLY);
	if(fd_r == -1)
	{
		printf("open error\n");
		return -1;
	}

	int fd_w = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, 0664);
	if(fd_w == -1)
	{
		printf("open error\n");
		return -1;
	}

	char buf[N];
	int ret = 0;

	while((ret = read(fd_r, buf, N)) > 0)
	{
		write(fd_w, buf, ret);
	}
	printf("copy ok\n");

	close(fd_r);
	close(fd_w);
	return 0;
}
