#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int sum = 0;
	close(0);
	close(2);
	while(open(argv[1], O_RDONLY) != -1)
	{
		sum++;
	}
	printf("sum = %d\n",sum);

	return 0;
}
