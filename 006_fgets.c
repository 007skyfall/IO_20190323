#include <stdio.h>

#define N 5
#if 0
char *fgets(char *s, int size, FILE *stream);
功能：从一个文件读取字符串
参数：s存储读取数据的首地址
注意：1、至多读取size-1个字符
	  2、读取到EOF或‘\n’会停止读取，并且‘\n’也会被读取
	  3、末尾自动加‘\0’字符
返回：成功返回s，失败或到达文件末尾返回NULL
#endif

int main(int argc, const char *argv[])
{
#if 0
	char buf[N];
	fgets(buf, N, stdin);
	printf("buf = %s\n",buf);

#else
	FILE *fp = fopen(argv[1], "r+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}

	char buf[N] = "abcd";
	fgets(buf, N, fp);
	printf("buf = %s\n",buf);

	fclose(fp);
#endif
	
	return 0;
}
