#include <stdio.h>
#include <sys/types.h> 	//open
#include <sys/stat.h> 	//open
#include <fcntl.h> 		//O_RDWR  O_CREAT
#include <unistd.h> 	//close

#if 0
ssize_t read(int fd, void *buf, size_t count);
功能：从文件fd中读取count字节的数据存储到buf
参数：count：期望读取的字节数
返回：成功返回读取的字节数，读到文件结尾返回0，失败返回-1

ssize_t write(int fd, const void *buf, size_t count);
功能：将buf内的数据写count字节到文件fd内
返回：成功返回写入的字节数，失败返回-1
#endif

#define N 5

int main(int argc, const char *argv[])
{
#if 0
	write(1,"h", 1);
	sleep(1);

	write(1,"h", 1);
	sleep(1);

	write(1,"h", 1);
	sleep(1);
#else
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		printf("open error\n");
		return -1;
	}

	char buf[N] = "abcd";
	write(fd, buf, sizeof(buf)-1);

	close(fd);
#endif
	
	return 0;
}
