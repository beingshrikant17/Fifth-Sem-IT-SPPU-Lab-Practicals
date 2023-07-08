#include<stdio.h>
void Solution(int arr[],int arr2[],int n)
{
	int i,j;
	for(i=0; i<n;i++)
	{
		if(arr[i]>0 && i%2==0  && arr[i]!=100)
		{
			arr2[i]= arr[i];
			arr[i]=100;
		}
 
		if(arr[i]<0 && i%2!=0 && arr[i]!=100)
		{
			arr2[i]= arr[i];
			arr[i]=100;

		} 
		
		else if( arr[i] >0 && i%2!=0 && arr[i]!=100)
		{
			for(j=0; j<n ; j++)
			{
				if(arr[j]<0)
				{
					arr2[j]= arr[j];
					arr[j]= 100;
					break;
				}
			}
		}
		
		else if ( arr[i] <0 && i%2 ==0 && arr[i]!=100)
		{
			for(j=0; j<n; j++)
			{
				if(arr[j] >0)
				{
					arr2[j] =arr[j];
					arr[j]= 100;
					break;
				}
			}
		}

    }
}

int main()
{
	  int i;
	  int arr[]={2,5,-6,7,-1,2,-3,4};
	  int n=sizeof(arr)/sizeof(arr[0]);
	  int arr2[n];
	  Solution(arr,arr2,n);
	  for(i=0;i<n;i++)
		{
			printf("%d \n",arr2[i]);
		}
       return 0;
}
