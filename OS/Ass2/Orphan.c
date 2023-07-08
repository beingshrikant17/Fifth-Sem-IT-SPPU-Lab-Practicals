#include <stdio.h>
#include <sys/wait.h>

void bubbleSort(int arr[],int n)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>=arr[j])
			{
       			temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("Sorted Array : \n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",arr[i]);
	}
}
 
void main(void)
{
	pid_t cpid, pid;
	int status;
	int n=0,i=0;
	printf("Enter The Size of array : \n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{	
		printf("Enter The No : %d \n",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("\nThis is Original Process");
	cpid=fork();
    //Fork Will create New Process means child process , which runs concurrently with the process that makes the fork() call (parent process).
	if(cpid==0)
	{
		printf("\nThis is Child Process");
		printf("\nChild : My Process ID is : %d",getpid());
		printf("\nChild : My Parent Process ID is %d\n",getppid());
		bubbleSort(arr,n);
		printf("\n***Child exiting .....\n");
	}
	else 
	{
		printf("\nParent : My Process ID is : %d",getpid());
		printf("\nParent : My Parent Process ID is %d\n",getppid());
		bubbleSort(arr,n);
		printf("\n***Parent Detects Process %d is Finished with status %d*** \n", pid,status);
		printf("***Parent exits \n");
		printf("***This is Orphan State \n");

	}
}