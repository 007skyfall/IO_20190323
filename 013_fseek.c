#include <stdio.h>

#if 0
int fseek(FILE *stream, long offset, int whence);
功能：设定文件的读写位置
参数：offset：偏移量，以字节为单位
	  whence：相对位置
	  		  SEEK_SET  文件的起始
			  SEEK_CUR  文件的当前
			  SEEK_END 	文件末尾(最后一个字符的下一个位置)
返回：成功返回1，失败返回-1

void rewind(FILE *stream);
功能：将文件的读写位置拉回到文件最开始
#endif


int main(int argc, const char *argv[])
{
	FILE *fp = fopen(argv[1], "r+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	
	fputc('X',fp);
	fputc('Y',fp);
	rewind(fp); 		//<==>  fseek(fp, 0, SEEK_SET);
	fputc('Z',fp);
	//XY <=======>ZY
#if 1	
	fseek(fp, -4, SEEK_END);
	fputc('A', fp);
	fputc('B', fp);
#endif

#if 1
	fseek(fp, 2, SEEK_SET);
	fputc('c', fp);
	fputc('d', fp);
#endif

	fclose(fp);
	
	return 0;
}
