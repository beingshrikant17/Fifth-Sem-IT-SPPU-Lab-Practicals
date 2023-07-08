
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
    char buf1[MAX_BUF];
    char buf2[MAX_BUF];
    mkfifo(fifo1,0666);
    fd=open(fifo1,O_RDWR);
    char str;
    printf("\nEnter the String:");
    str=getchar();
    while (str!='#')
   	{
         buf1[c++]=str;
   	     str=getchar();
    }
    buf1[c]='\0';
    write(fd,buf1,sizeof(buf1));
    close(fd);
    sleep(3);
    fd2=open(fifo2,O_RDWR);
    read(fd2,buf2,sizeof(buf2));
    close(fd2);
    FILE* ptr;
    ptr = fopen("/home/Shrikant19/Documents/os/data.txt", "r");
    if (NULL == ptr) 
    {
        printf("file can't be opened \n");
    }
    else
    {    
        char word[10];
        printf("Words\t\tCharacters\tLines\n");
        while (fscanf(ptr, "%s", word) != EOF)
        {
            printf("%s\t\t", word);
        }
        fclose(ptr);
    }
    return 0;