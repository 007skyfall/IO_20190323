//使用fgetc、fputc完成文件的拷贝操作
#include <stdio.h>

int main(int argc, const char *argv[])
{
	if(argc < 3)
	{
		printf("argument is too less\n");
		return -1;
	}

	FILE *fp_r = fopen(argv[1], "r");
	if(fp_r == NULL)
	{
		printf("fp_r fopen error\n");
		return -1;
	}

	FILE *fp_w = fopen(argv[2], "w");
	if(fp_w == NULL)
	{
		printf("fp_w fopen error\n");
		return -1;
	}

	int ret = 0;

	while((ret = fgetc(fp_r)) != EOF)
	{
		fputc(ret, fp_w);
	}
	printf("copy ok\n");

	fclose(fp_r);
	fclose(fp_w);
	
	return 0;
}
