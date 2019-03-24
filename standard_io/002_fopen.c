/*标准IO：带缓存，通过文件指针FILE*访问文件, stream*/
/*stdin  stdout  stderr*/
#include <stdio.h>


#if 0
fopen  --- fprintf ---- fclose

FILE *fopen(const char *path, const char *mode);
功能：打开一个文件，获得文件访问的文件指针
参数：path：文件的路径及名字
	  mode：r 	只读，不可创建
	  		r+  读写，不可创建，覆盖模式
			w   只写，创建，清空模式
			w+  读写，创建，清空模式
			a   只写，创建，追加模式
			a+  读写，创建，追加模式，读从开始读
返回：成功返回文件指针，失败返回NULL

int fprintf(FILE *stream, const char *format, ...);
与printf的使用方式一样

int fclose(FILE *fp);
功能：关闭一个文件指针
#endif

int main(int argc, const char *argv[])
{
	FILE *fp = fopen("test.txt", "w+");
	if(fp == NULL)
	{
		printf("open error\n");
		return -1;
	}

	fprintf(fp, "Hello........\n");

	fclose(fp);
	
	return 0;
}
