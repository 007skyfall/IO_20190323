#include <stdio.h>

#if 0
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
功能：从文件stream中读取nmemb项数据存储到ptr里，每项size大小
返回：成功读取的完整项数，失败或文件末尾返回0
注意：为了返回值与读取的字节数相匹配，size使用单位字节数

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
功能：将ptr内的数据写nmemb项到文件stream里，每项size大小
返回：成功写入的完整项数，失败或文件末尾返回0
#endif

#define N 32

struct name{
	int a;
	float b;
	char c;
};

int main(int argc, const char *argv[])
{
	FILE *fp = fopen(argv[1], "r+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}

	struct name x;
	x.a = 10;
	x.b = 12.34;
	x.c = 'P';
	fwrite(&x, sizeof(struct name), 1, fp);

	fclose(fp);
	
	return 0;
}
