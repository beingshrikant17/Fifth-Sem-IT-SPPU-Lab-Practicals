#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[],char *en[])
{
	int i,j,c,ele,temp,cnt;
	int Arr[argc];

	for(j=0;j<argc-1;j++)
	{
		//converts String to integer
		int n=atoi(argv[j]);
		Arr[j]=n;
	}

	cnt=argc-1;
	j=cnt-1;

	for(i=0;i<(int)(cnt/2);i++)
	{
		temp=Arr[i];
		Arr[i]=Arr[j];
		Arr[j]=temp;	
		j--;
	}
	
	printf("\nInside the child Process ...\n");
	printf("\nElements Reversed in the given array are\n");
	for(i=0;i<cnt;i++)
	{
		printf("\nElement No %d is %d: ",i+1,Arr[i]);		
	}
	printf("\n");		
	printf("\nArgc count in Child : %d  \n", argc);
}
