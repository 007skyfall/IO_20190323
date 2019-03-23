#include <stdio.h>
#include <time.h>

#if 0
time_t time(time_t *t);
功能：获得当前的时间，秒数
参数：非NULL时将返回值同时存储到t内
返回：当前时间的秒数

struct tm *localtime(const time_t *timep);
功能：将time_t类型的秒数时间转化成日历时间

struct tm {
	int tm_sec;         /* seconds */
	int tm_min;         /* minutes */
	int tm_hour;        /* hours */
	int tm_mday;        /* day of the month */
	int tm_mon;         /* month */
	int tm_year;        /* year */
	int tm_wday;        /* day of the week */
	int tm_yday;        /* day in the year */
	int tm_isdst;       /* daylight saving time */
 };
#endif

int main(int argc, const char *argv[])
{
	FILE *fp = fopen(argv[1], "a+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	int ret = 0;
	int line = 0;

	while((ret = fgetc(fp)) != EOF)
	{
		if(ret == '\n')
		{
			line++;
		}
	}

	time_t mytm;
	struct tm *tm = NULL;

	while(1)
	{
		mytm = time(NULL);
		tm = localtime(&mytm);
		fprintf(fp, "%2d %d-%d-%d  %d:%d:%d\n", ++line, tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
			   									tm->tm_hour, tm->tm_min, tm->tm_sec);
		fflush(fp);
		sleep(1);
	}

	return 0;
}
