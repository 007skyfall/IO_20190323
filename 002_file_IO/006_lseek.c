#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#if 0
off_t lseek(int fd, off_t offset, int whence);
功能：改变文件的读写位置
参数：offset：偏移量，以字节为单位
	  whence：相对位置
	  		  SEEK_SET  文件的开始
			  SEEK_CUR 	文件的当前
			  SEEK_END 	文件的末尾(最后一个字符的下一个位置)
返回：设定问位置后,文件当前的读写位置,相对于文件开始的偏移量。失败返回-1
#endif

int main(int argc, const char *argv[])
{
	int fd = open(argv[1], O_RDWR);
	if(fd == -1)
	{
		printf("open error\n");
		return -1;
	}
	off_t ret = 0;

	ret = lseek(fd, -4, SEEK_END);
	printf("ret = %d\n",(int)ret);
	write(fd, "A", 1);
	write(fd, "B", 1);
	write(fd, "C", 1);
	close(fd);

	return 0;
}
