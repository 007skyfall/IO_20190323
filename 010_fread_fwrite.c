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

int main(int argc, const char *argv[])
{
	FILE *fp = fopen(argv[1], "r+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}

	char buf[N] = {0};
	int ret = 0;
 											//为了返回值与读取的字节数相匹配
	ret = fread(buf, 1, 7, fp); 			//size使用单位字节数
	fwrite(buf, 1, ret, stdout); 	

	fclose(fp);
	
	return 0;
}
