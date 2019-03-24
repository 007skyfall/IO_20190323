#include <stdio.h>
#include <unistd.h>

#if 0
刷新缓存的条件：程序正常结束  ‘\n’  fflush  缓存区满
int fflush(FILE *stream);
功能：刷新缓存区
注意：不能刷新stdin
#endif

int main(int argc, const char *argv[])
{
	int i;
	for(i=0; i<5; i++)
	{
		printf("%c", 'A'+i);
	//	fflush(stdout);
	//该选项使用前后对比验证fflush的功能
		sleep(1);
	}

	printf("\n");


	return 0;
}
