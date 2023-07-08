#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int i,j,n,temp;
	printf("\nEnter the size for the array  : ");
	scanf("%d",&n);
	printf("\n");
	int Arr[n];
	for(i=0;i<n;i++)
	{
		printf("Enter element No %d: ",i+1);
		scanf("%d",&Arr[i]);
	}
	printf("\nEntered Elements are\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement No %d is %d: ",i+1,Arr[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Arr[i]>=Arr[j])
			{
       			temp=Arr[i];
				Arr[i]=Arr[j];
				Arr[j]=temp;
			}
		}
	}
	printf("\nSorted Elements are\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement No %d is %d: ",i+1,Arr[i]);;
	}
	
	
	pid_t pid;
	char *newenviron[] ={NULL};
	char* cval[n];

	for(i=0;i<n+1;i++)
	{
		//allocate a big enough char to store an int (which is 4 bytes, depending on your platform)
		char a[sizeof(int)];
		// copy int to char
		snprintf(a,sizeof(int), "%d",Arr[i]);
		// allocate enough space on char* array to store this result
		cval[i] =malloc(sizeof(a));
		// copy to the array of results
		strcpy(cval[i],a);
	}
	cval[i]=NULL;

	printf("\n\nforking a child Process ...");
	pid=fork();

	if(pid==0)
	{
		printf("\nArgc count in Parent : %d  \n", argc);
		execve(argv[1],cval,newenviron);
		perror("Error in execve call ...");
	}
}