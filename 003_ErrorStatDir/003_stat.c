#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#if 0
int stat(const char *path, struct stat *buf);
功能：获得文件的属性信息
注意：stat访问链接文件时，获得的是链接文件所代表的源文件的属性信息
struct stat {
	ino_t     st_ino;     /* inode number */
	mode_t    st_mode;    /* protection */
	nlink_t   st_nlink;   /* number of hard links */
	uid_t     st_uid;     /* user ID of owner */
	gid_t     st_gid;     /* group ID of owner */
	time_t    st_atime;   /* time of last access */
	time_t    st_mtime;   /* time of last modification */
};
#endif
int main(int argc, const char *argv[])
{
	struct stat buf;
	if(stat(argv[1], &buf) == -1)
	{
		perror("stat error");
		return -1;
	}

	printf("mode = %o\n",buf.st_mode);
	switch(buf.st_mode & S_IFMT)
	{
	case S_IFREG:printf("-\n");break;
	case S_IFDIR:printf("d\n");break;
	case S_IFCHR:printf("c\n");break;
	case S_IFLNK:printf("l\n");break;
	default:printf("other\n");
	}

	return 0;
}
