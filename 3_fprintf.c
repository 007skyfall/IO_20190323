/*标准IO：带缓存，通过文件指针FILE*访问文件, stream*/
/*stdin  stdout  stderr*/
#include <stdio.h>


#if 0
fopen  --- fprintf ---- fclose

FILE *fopen(const char *path, const char *mode);
功能：打开一个文件，获得文件的访问的文件指针
int fprintf(FILE *stream, const char *format, ...);
功能：与printf的使用方式一样
int fclose(FILE *fp);
功能：关闭一个文件指针
#endif

int main(int argc, const char *argv[])
{
#if 0

	fprintf(stdout, "hello world\n");

#else
	FILE *fp = fopen(argv[1], "a+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}

	fprintf(fp, "ABCD");
	fclose(fp);
	fprintf(fp, "ABCD");
#endif
	
	return 0;
}
