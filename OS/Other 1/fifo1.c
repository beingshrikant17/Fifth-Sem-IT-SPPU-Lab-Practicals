#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_BUF 1024

int main()
{
	int fd,c=0;
	char *fifo1="fifo1";
	int fd1,fd2;
	char buf1[MAX_BUF];
	char buf2[MAX_BUF];
	mkfifo(fifo1,0666);
	fd1=open(fifo1,O_RDWR);
	char str;
	printf("\nEnter the string:");
	while ((str=getchar())!='#')
		buf1[c++]=str;
	buf1[c]='\0';
	write(fd,buf1,sizeof(buf1));
	close(fd1);
	//printf("\nOutput of buf1: %d",sizeof(buf1));
	sleep(1);
	fd2=open(fifo1,O_RDWR);
	read(fd2,buf2,sizeof(buf2));
	//printf("\nOutput of buf2: %d",sizeof(buf2));
	printf("\nThe count of file Words,Characters,Lines are- %s\n",buf2);
	close(fd2);
	return 0;
}
