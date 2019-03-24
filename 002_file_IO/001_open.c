/*文件IO：通过文件描述符访问文件，可以操作各类文件，0 1 2*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#if 0
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
功能：打开一个文件获得它的文件描述符，用于接下来的系统调用
返回：成功返回最小的非负的整数,且是进程当前没有正在使用的。失败返回-1
参数：mode ：文件创建时的权限(mode & ~umask)
	  flags：文件的访问方式
			 fopen   open
	  		 r 		 O_RDONLY
			 r+ 	 O_RDWR
			 w 		 O_WRONLY|O_CREAT|O_TRUNC
			 w+ 	 O_RDWR|O_CREAT|O_TRUNC
			 a 		 O_WRONLY|O_CREAT|O_APPEND
			 a+ 	 O_RDWR|O_CREAT|O_APPEND

int close(int fd);
功能：关闭文件描述符
#endif

int main(int argc, const char *argv[])
{
	int fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, 0664);
	if(fd == -1)
	{
		printf("open error\n");
		return -1;
	}
	printf("fd = %d\n",fd);
	printf("ok\n");

	close(fd);
	
	return 0;
}
