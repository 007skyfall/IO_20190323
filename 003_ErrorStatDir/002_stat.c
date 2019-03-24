#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#if 0
int stat(const char *path, struct stat *buf);
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

	printf("ino = %d\n",(int)buf.st_ino);
	printf("uid = %d\n",buf.st_uid);
	printf("gid = %d\n",buf.st_gid);

	struct tm *tm = localtime(&buf.st_mtime);
	printf("tim = %d\n",(int)buf.st_mtime);
	printf("%d-%d-%d %d:%d:%d\n", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
								  tm->tm_hour, tm->tm_min, tm->tm_sec);
	return 0;
}
