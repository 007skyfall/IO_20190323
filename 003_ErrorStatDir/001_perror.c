#include <stdio.h> 		//perror
#include <string.h> 	//strerror
#include <errno.h> 		//errno

#if 0
void perror(const char *s);
功能：s + ':' + '空格' + '错误信息' + '\n'

char *strerror(int errnum);
功能：将错误码转换成对应错误信息

errno
功能：自动记录最后一次的错误码
#endif

int main(int argc, const char *argv[])
{
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		perror("fopen error");
		printf("strerror   : %s\n",strerror(errno));
		return -1;
	}
	printf("ok\n");
	
	return 0;
}
