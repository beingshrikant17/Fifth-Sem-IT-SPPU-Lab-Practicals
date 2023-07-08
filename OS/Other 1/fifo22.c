#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#define MAX_BUF 1024
int main()
{
int fd;
FILE *fp;
char *fifo1="fifo1";
int fd1,fd2;
char c[10],w[10],l[10];
int words=1,lines=1,chars=0;
char buf1[MAX_BUF], buf2[MAX_BUF];

fd1=open(fifo1,O_RDWR);
read(fd1,buf1,sizeof(buf1));
close(fd1);
printf("\nTHe contents of file are %s\n",buf1);
int i=0;
while(buf1[i]!='\0')
{
if(buf1[i]==' '||buf1[i]=='\n')
{words++;}
else
{chars++;}
if(buf1[i]=='\n')
{lines++;}
i++;
}
printf("\n No. of Words: %d",words);
printf("\n NO.of Characters: %d",chars);
printf("\n NO.of lines: %d",lines);

strcpy(c,"\0");
fp=fopen("test.txt","w");
fprintf(fp,"%d %d %d",chars ,words, lines);
fclose(fp);
fp=fopen("test.txt","r");
fscanf(fp,"%s %s %s",c ,w ,l);
fclose(fp);
strcat(c," ");
strcat(c,w);
strcat(c," ");
strcat(c,l);
printf("\n output of counting %s",c);

mkfifo(fifo1,0666);
fd2=open(fifo1,O_RDWR);
write(fd2,c,20);
close(fd2);
return 0;
}
