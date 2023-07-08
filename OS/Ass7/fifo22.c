#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

#define MAX_BUF 1024

int main()
{
    int fd,c=0;
    char *fifo1="fifo1";
    char *fifo2="fifo2";
    int fd1,fd2;
    int words=1,lines=1,chars=0;
    char buf1[MAX_BUF], buf2[MAX_BUF];
    mkfifo(fifo2,0666);
    fd1=open(fifo1,O_RDWR);
    read(fd1,buf1,sizeof(buf1));
    close(fd1);
    printf("\nThe contents of file are %s\n",buf1);
    int i=0;
      while(buf1[i]!='\0')
          {
            if(buf1[i]==' '||buf1[i]=='\n')
             {words++;}
            else
             {chars++;}
             if(buf1[i]=='\n')
             {lines++;}
           i++;}
     printf("\n No of Words: %d",words);
     printf("\n No of Characters: %d",chars);
     printf("\n No of Lines: %d",lines);
     char str1[20],str2[20],str3[20];
    sprintf(str1,"%d",words);
    sprintf(str2,"%d",chars);
    sprintf(str3,"%d",lines);
    FILE *fp;
    fp  = fopen ("/home/Shrikant19/Documents/os/data.txt", "w");
    fputs(str1, fp);
    fputs(" ", fp);
    fputs(str2, fp);
    fputs(" ", fp);
    fputs( str3,fp);
    fclose(fp);
    
    
    buf2[0]=words;
    buf2[1]=chars;	
    buf2[2]=lines;
    buf2[3]='\0';
    fd2=open(fifo2,O_RDWR);
    write(fd2,buf2,sizeof(buf2));
    close(fd2);
    return 0;
}