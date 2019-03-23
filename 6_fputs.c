#include <stdio.h>

#if 0
int fputs(const char *s, FILE *stream);
功能：向指定文件输出字符串
返回：成功返回非负数，失败EOF(-1)
#endif

int main(int argc, const char *argv[])
{
#if 0
	fputs("hello\n",stdout);
#else
	FILE *fp = fopen(argv[1], "r+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	int ret = 0;

	fputs("world\0hello", fp); 	 	//遇到'\0'结束输出

	fclose(fp);
#endif
	
	return 0;
}
