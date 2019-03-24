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
	//使用命令行传参的方式，以追加的方式进行读写
	FILE *fp = fopen(argv[1], "a+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}

	fprintf(fp, "ABCD\n");
	fclose(fp);
	//文件的指针已经关闭，再次进行读写操作无效
	fprintf(fp, "ABCD");
#endif
	
	return 0;
}
