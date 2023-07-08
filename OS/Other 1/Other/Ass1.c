#include <stdio.h>
#include <sys/types.h>

void main(void)
{
	pid_t cpit, pid;
	int status;
	printf("\nThis is Original Process");
	cpid=fork();

	if(cpid==0)
	{
		printf("\nThis is Child Process")
		printf("\nChild : My Process ID is : %d",getpid());
		printf("\nChild : My Parent Process ID is %d",getppid());
		sleep(3);
		printf("***Child exiting .....");
	}

	else 
	{
		sleep(2);
		printf("\nParent : My Process ID is : %d",getpid());
		printf("\nParent : My Parent Process ID is %d",getppid());
		pid=wait(&status);
		printf("***Parent Detects Process %d is Finished with status %d*** \n", pid,status);
		printf("***Parent exits \n");
	}
}
