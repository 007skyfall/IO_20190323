#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#if 0
int closedir(DIR *dirp);
功能：关闭一个目录指针
返回：成功返回0，失败返回-1

DIR *opendir(const char *name);
功能：打开一个目录
返回：成功返回目录指针，失败返回NULL

struct dirent *readdir(DIR *dirp);
功能：读取接下来的一个目录项
返回：成功返回目录项的信息地址，失败或到达目录结尾返回NULL
 struct dirent {
	ino_t          d_ino;       /* inode number */
	off_t          d_off;       /* offset to the next dirent */
	unsigned short d_reclen;    /* length of this record */
	unsigned char  d_type;      /* type of file; not supported by all file system types */
	char           d_name[256]; /* filename */
 };
#endif

int main(int argc, const char *argv[])
{
	DIR *dir = opendir(argv[1]);
	if(dir == NULL)
	{
		perror("opendir error");
		return -1;
	}

	struct dirent * dirp = NULL;
	while((dirp = readdir(dir)) != NULL)
	{
		if(dirp->d_name[0] != '.')
		{
			printf("%s\n",dirp->d_name);
		}
	}

	closedir(dir);
	return 0;
}
