#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
void FIFO(char [],char [],int,int);
void lru(char [],char [],int,int);
void opt(char [],char [],int,int);

int main()
{
   int ch,YN=1,i,l,f;
   char F[10],s[25];
   printf("\nEnter the no of empty frames: ");
   scanf("%d",&f);
   printf("\nEnter the length of the string: ");
   scanf("%d",&l);
   printf("\nEnter the string: ");
   scanf("%s",s);
   for(i=0;i<f;i++)
	{
     	F[i]=-1;
	}
  do
    {
      printf("\n\n\t*********** MENU ***********");
      printf("\n\n\t1:FIFO\n\n\t2:LRU\n\n\t3:OPT\n\n\t4:EXIT");
      printf("\n\n\tEnter your choice: ");
      scanf("%d",&ch);
      switch(ch)
       {
          case 1:
          for(i=0;i<f;i++)
           {
             F[i]=-1;
           }

		FIFO(s,F,l,f);
          break;
      case 2:
          for(i=0;i<f;i++)
           {
             F[i]=-1;
           }
          lru(s,F,l,f);
          break;
      case 3:
          for(i=0;i<f;i++)
           {
             F[i]=-1;
           }

          opt(s,F,l,f);
          break;
      case 4:
          YN=198;
       }
    }while(YN!=198);
	return(0);
}

void FIFO(char s[],char F[],int l,int f)
{
   int i,j=0,k,flag=0,cnt=0;
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
        flag=1;
    }

       if(flag==0)
    {
      printf("\n\t%c\t",s[i]);
      F[j]=s[i];
      j++;

      for(k=0;k<f;k++)
       {
        printf("   %c",F[k]);
       }
      printf("\tPage-fault%d",cnt);
      cnt++;
    }

       else
    {
      flag=0;
      printf("\n\t%c\t",s[i]);
      for(k=0;k<f;k++)
       {
        printf("   %c",F[k]);
       }

      printf("\tNo page-fault");
    }
       if(j==f)
    j=0;
    }

}

void lru(char s[],char F[],int l,int f)
{
   int i,j=0,k,m,flag=0,cnt=0,top=0;
   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
       {
        flag=1;
         break;
       }
    }

       printf("\n\t%c\t",s[i]);
       if(j!=f && flag!=1)
    {
      F[top]=s[i];
      j++;

      if(j!=f)
       top++;
    }
       else
    {
       if(flag!=1)
        {
          for(k=0;k<top;k++)
           {
        F[k]=F[k+1];
           }

           F[top]=s[i];
        }
       if(flag==1)
        {
           for(m=k;m<top;m++)
           {
        F[m]=F[m+1];
           }

           F[top]=s[i];
        }
    }
       for(k=0;k<f;k++)
    {
     printf("   %c",F[k]);
    }

       if(flag==0)
    {
      printf("\tPage-fault%d",cnt);
      cnt++;
    }
       else
     printf("\tNo page fault");
       flag=0;
    }

}

void opt(char s[],char F[],int l,int f)
{
   int i,j=0,k,m,flag=0,cnt=0,temp[10];

   printf("\n\tPAGE\t    FRAMES\t  FAULTS");
   for(i=0;i<10;i++)
     temp[i]=0;

   for(i=0;i<f;i++)
     F[i]=-1;

   for(i=0;i<l;i++)
    {
       for(k=0;k<f;k++)
    {
      if(F[k]==s[i])
        flag=1;
    }

       if(j!=f && flag==0)
    {
      F[j]=s[i];
      j++;
    }

       else if(flag==0)
    {
       for(m=0;m<f;m++)
        {
          for(k=i+1;k<l;k++)
           {
          if(F[m]!=s[k])
           {
             temp[m]=temp[m]+1;
           }
          else
           break;
           }
        }
       m=0;
       for(k=0;k<f;k++)
        {
           if(temp[k]>temp[m])
        {
          m=k;
        }
        }

       F[m]=s[i];
    }

       printf("\n\t%c\t",s[i]);
       for(k=0;k<f;k++)
    {
       printf("  %c",F[k]);
    }
       if(flag==0)
    {
      printf("\tPage-fault %d",cnt);
      cnt++;
    }
       else
     printf("\tNo Page-fault");
       flag=0;

       for(k=0;k<10;k++)
     temp[k]=0;
     }
}
