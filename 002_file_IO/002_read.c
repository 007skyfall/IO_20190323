#include <stdio.h>
#include <sys/types.h> 	//open
#include <sys/stat.h> 	//open
#include <fcntl.h> 		//O_RDWR  O_CREAT
#include <unistd.h> 	//close

#if 0
size_t read(int fd, void *buf, size_t count);
功能：从文件fd中读取count字节的数据存储到buf
参数：count：期望读取的字节数
返回：成功返回读取的字节数，读到文件结尾返回0，失败返回-1
#endif

#define N 5

int main(int argc, const char *argv[])
{
#if 0
	char buf[N] = {0};
	read(0, buf, N);
	printf("buf = %s\n",buf);
#else
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		printf("open error\n");
		return -1;
	}

	char buf[N] = "abcd";
	int ret;

	ret = read(fd, buf, N-2);
	printf("buf = %s\n",buf);
	printf("ret = %d\n",ret);

	ret = read(fd, buf, N-2);
	printf("ret = %d\n",ret);

	close(fd);
#endif
	
	return 0;
}
