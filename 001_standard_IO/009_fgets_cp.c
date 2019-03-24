#include <stdio.h>

#define N 5

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
	char buf[N]; 	

	while(fgets(buf, N, fp_r) != NULL)
	{
//		printf("buf = %s\n",buf);
		fputs(buf, fp_w);
	}
	printf("copy ok\n");

	fclose(fp_r);
	fclose(fp_w);
	
	return 0;
}
