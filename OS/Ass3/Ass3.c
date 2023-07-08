/*
       Name :   Pawar Shrikant Sanjeev
       Subject: OS Lab
       Roll No: 57
       Assignment No 3-b
*/

#include<stdio.h>

struct times
{
       int p,art,but,wtt,tat,rnt;
};

struct sjf
{
       int bt,at,wt,st,pno,tt,cbt;
};

void sortart(struct times a[],int pro)
{
       int i,j;
       struct times temp;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].art > a[j].art)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}

int get(struct sjf arr[],int t,int n)
{
       int imin,min=9999,i;
       for(i=0;i<n;i++)
       {
              if(arr[i].at<=t&&arr[i].st==0)
                     if(min>arr[i].bt)
                     {
                           min=arr[i].bt;
                           imin=i;
                     }
       }
       return imin;
}

void gantt_chart(struct sjf arr[],int p[],int n,int nop)
{
       int i,a[100],s=0;
       float avgtt=0,avgwt=0;
       printf("***************************************\n");
       printf("GANTT CHART\n");
       printf("0");
       for(i=0;i<n-1;i++)
       {
              while(i<n-1&&p[i]==p[i+1])
              {
                     s++;
                     i++;
              }
               
              s++;
              printf(" -> [P%d] <- %d",arr[p[i]].pno,s);
              arr[p[i]].wt=s-arr[p[i]].at-arr[p[i]].tt;
       }
       for(i=0;i<nop;i++)
       {
              arr[i].tt+=arr[i].wt;
              avgwt+=arr[i].wt;
              avgtt+=arr[i].tt;
       }
       printf("\n***************************************\n");
       printf("Pro\tArTi\tBuTi\tWtTi\n");
       printf("***************************************\n");
       for(i=0;i<nop;i++)
       {
              printf("[P%d]\t%d\t%d\t%d\n",arr[i].pno,arr[i].at,arr[i].cbt,arr[i].wt);
       }
       printf("***************************************\n");
       avgwt = avgwt/nop;
       avgtt = avgtt/nop;
       printf("Average Waiting Time : %.2f\n",avgwt);
       return;
}

int iscomplite(struct sjf arr[],int n)
{
       int i;
       for(i=0;i<n;i++)
       {
              if(arr[i].st==0)
              {
                  return 0;
              }
       }
              
       return 1;
}

void RR()
{
	 int i,j,pro,time,remain,flag=0,ts;
       struct times a[100];
       float avgwt=0,avgtt=0;
       printf("Round Robin Scheduling Algorithm\n");
       printf("Enter Number Of Processes : ");
       scanf("%d",&pro);
       remain=pro;
       for(i=0;i<pro;i++)
       {
              printf("Enter arrival time and Burst time for Process P%d : ",i);
              scanf("%d%d",&a[i].art,&a[i].but);
              a[i].p = i;
              a[i].rnt = a[i].but;
       }
       sortart(a,pro);
       printf("Enter Time Slice OR Quantum Number : ");
       scanf("%d",&ts);
       printf("\n***************************************\n");
       printf("Gantt Chart\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(a[i].rnt<=ts && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf(" -> [P%d] <- %d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - ts;
                     time = time + ts;
                     printf(" -> [P%d] <- %d",a[i].p,time);
              }
              if(a[i].rnt==0 && flag==1)
              {
                     remain--;
                     a[i].tat = time-a[i].art;
                     a[i].wtt = time-a[i].art-a[i].but;
                     avgwt = avgwt + time-a[i].art-a[i].but;
                     avgtt = avgtt + time-a[i].art;
                     flag=0;
              }
              if(i==pro-1)
                     i=0;
              else if(a[i+1].art <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n\n");
       printf("***************************************\n");
       printf("Pro\tArTi\tBuTi\tTaTi\tWtTi\n");
       printf("***************************************\n");
       for(i=0;i<pro;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\n",a[i].p,a[i].art,a[i].but,a[i].tat,a[i].wtt);
       }
       printf("***************************************\n");
       avgwt = avgwt/pro;
       avgtt = avgtt/pro;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
}


void SRTF()
{
	int n,i,a,t=0;
       int p[100];
       float avgwt=0,avgtt=0;
       struct sjf arr[100];
       printf("SRTF (Shortest Remaining Time First) \n");
       printf("Enter Number of Processes\n");
       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
              printf("Enter Arrival Time & Burst Time for Process [P%d]\n",i);
              scanf("%d%d",&arr[i].at,&arr[i].bt);
              arr[i].pno = i;
              arr[i].cbt = arr[i].bt;
              arr[i].st=0;
              arr[i].tt=arr[i].bt;
              arr[i].wt=0;
       }
       i=0;
       while(1)
       {
              if(iscomplite(arr,n))
                     break;
              a=get(arr,t,n);
              p[i]=a;
              arr[a].bt-=1;
              if(arr[a].bt==0)
                     arr[a].st=1;
              t=t+1;
              i++;
       }
       gantt_chart(arr,p,i,n);
}

int main()
{
	int ch=0;
	while(ch!=198)
	{
		printf("Enter The choice");
		printf("\n 1 - RR \n 2 - SRTF \n 3 - EXIT"); 
		scanf("%d",&ch);
		switch(ch) {
			case 1: 
				RR();
				break;
			case 2:
				SRTF();
				break;
			case 3: 
				ch = 198;
				break;
		}
	}
      
}

/*
       Output : 
student@student-HP-Pro-3330-MT:~/TEIT-57/Ass3$ gcc RR.c
student@student-HP-Pro-3330-MT:~/TEIT-57/Ass3$ ./a.out
Enter The choice
 1 - RR 
 2 - SRTF 
 3 - EXIT1
Round Robin Scheduling Algorithm
Enter Number Of Processes : 5
Enter arrival time and Burst time for Process P0 : 0
8
Enter arrival time and Burst time for Process P1 : 1
5
Enter arrival time and Burst time for Process P2 : 3
3
Enter arrival time and Burst time for Process P3 : 4
1
Enter arrival time and Burst time for Process P4 : 6
4
Enter Time Slice OR Quantum Number : 2

***************************************
Gantt Chart
0 -> [P0] <- 2 -> [P1] <- 4 -> [P2] <- 6 -> [P3] <- 7 -> [P4] <- 9 -> [P0] <- 11 -> [P1] <- 13 -> [P2] <- 14 -> [P4] <- 16 -> [P0] <- 18 -> [P1] <- 19 -> [P0] <- 21

***************************************
Pro	ArTi	BuTi	TaTi	WtTi
***************************************
P0	0	8	21	13
P1	1	5	18	13
P2	3	3	11	8
P3	4	1	3	2
P4	6	4	10	6
***************************************
Average Waiting Time : 9.40
Average Turnaround Time : 13.60
Enter The choice
 1 - RR 
 2 - SRTF 
 3 - EXIT2
SRTF (Shortest Remaining Time First) 
Enter Number of Processes
5
Enter Arrival Time & Burst Time for Process [P0]
0
9
Enter Arrival Time & Burst Time for Process [P1]
1
1
Enter Arrival Time & Burst Time for Process [P2]
2
7
Enter Arrival Time & Burst Time for Process [P3]
3
1
Enter Arrival Time & Burst Time for Process [P4]
4
6
***************************************
GANTT CHART
0 -> [P0] <- 1 -> [P1] <- 2 -> [P2] <- 3 -> [P3] <- 4 -> [P2] <- 10 -> [P4] <- 16 -> [P0] <- 24
***************************************
Pro	ArTi	BuTi	WtTi
***************************************
[P0]	0	9	15
[P1]	1	1	0
[P2]	2	7	2
[P3]	3	1	0
[P4]	4	6	6
***************************************
Average Waiting Time : 4.60
Enter The choice
 1 - RR 
 2 - SRTF 
 3 - EXIT3
student@student-HP-Pro-3330-MT:~/TEIT-57/Ass3$ 


*/    
