#include <stdio.h>

#if 0 
int fputc(int c, FILE *stream);
功能：输出一个字符
参数：c：要输出的字符
	  stream：文件
返回：成功返回输出字符的ASCII码，失败-1
#endif

int main(int argc, const char *argv[])
{

#if 0
	fputc('L',stdout);
	fputc('\n',stdout);
#else
	FILE *fp = fopen(argv[1], "a+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}

	fputc('K', fp);
	fclose(fp);
#endif
	
	return 0;
}
