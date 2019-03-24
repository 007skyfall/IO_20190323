#include <stdio.h>

#if 0
int fgetc(FILE *stream);
功能：读取一个字符，并返回相应的ASCII码
返回：成功返回ASCII码，失败或到达文件末尾返回EOF(-1)
#endif

int main(int argc, const char *argv[])
{
#if 0
	int ret = 0;
	ret = fgetc(stdin);
	printf("ret = %c\n",ret);
#else
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("fopen error");
		return -1;
	}
	int ret = 0;
	//文件指针会移动
	ret = fgetc(fp);
	printf("ret = %c\n",ret);

	ret = fgetc(fp);
	printf("ret = %c\n",ret);

	ret = fgetc(fp);
	printf("ret = %d\n",ret);
	fclose(fp);
#endif
	
	return 0;
}
