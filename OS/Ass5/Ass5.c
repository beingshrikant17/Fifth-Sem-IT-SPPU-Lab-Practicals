#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter No Processes\n");
    scanf("%d",&n);
    printf("Enter No Resources\n");
    scanf("%d",&m);

    int alloc[n][m];
    int max[n][m];
    int avail[m];
    
    for(i=0;i<n;i++)
	  {
		  printf("Enter resources Allocated to P[%d]\n",i);
		  for(j=0;j<m;j++)
		  {
		  	scanf("\t%d",&alloc[i][j]);
		  }
	  }
 
   for(i=0;i<n;i++)
	  {
		  printf("Enter Maximum to P[%d]\n",i);
		  for(j=0;j<m;j++)
		  {
		  	scanf("\t%d",&max[i][j]);
		  }
	  }

    printf("Enter Available resources\n");
	  for(i=0;i<m;i++)
	  {
		  scanf("\t%d",&avail[i]);
	  }
 
    int need[n][m];
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    //Important Part Starts Here
        
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) 
    {
        f[k] = 0;
    }
    int y = 0;
    for (k = 0; k < 5; k++) 
    {
        for (i = 0; i < n; i++) 
        {
            if (f[i] == 0) 
            {
                int flag = 0;
                for (j = 0; j < m; j++) 
                {
                    if (need[i][j] > avail[j])
                     {
                        flag = 1;
                         break;
                     }
                }
 
                if (flag == 0) 
                 {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                 }
            }
        }
    }
   
      int flag = 1;
      for(int i=0;i<n;i++)
      {
        if(f[i]==0)
        {
         flag=0;
         printf("The following system is not safe\n");
	       printf("process no P[%d]",i);
         break;
         }
      }

      if(flag==1)
      {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }
    return (0);
}


/*
       Output : 


student@student-HP-Pro-3330-MT:~/TEIT-57/Ass5$ gcc Ass5.c -o Ass5
student@student-HP-Pro-3330-MT:~/TEIT-57/Ass5$ ./Ass5
Enter No Processes
5
Enter No Resources
3
Enter resources Allocated to P[0]

0
1

0
Enter resources Allocated to P[1]
2
0
0
Enter resources Allocated to P[2]
3
0
2
Enter resources Allocated to P[3]
2
1
1
Enter resources Allocated to P[4]
0
0
2
Enter Maximum to P[0]
7
5
3
Enter Maximum to P[1]
3
2
2
Enter Maximum to P[2]
9 
0
2
Enter Maximum to P[3]
2
2
2
Enter Maximum to P[4]
4
3
3
Enter Available resources
3
3
2
Following is the SAFE Sequence
 P1 -> P3 -> P4 -> P0 -> P2student@student-HP-Pro-3330-MT:~/TEIT-57/Ass5$ 

*/
