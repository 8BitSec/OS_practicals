#include<stdio.h>

//structure of a process
typedef struct{
  int pid;        //process id
  int at;         //arrival time
  int bt;         //burst time
  int priority;   //priority
  int rt;         //remaining time

} process;


int main()
{  
  int i,j;
  int n, time, sum_wait=0, sum_turnaround=0, smallest;
  //int at[10],bt[10],pt[10],rt[10],remain; //rt = remaining Time
  int remain;
  
  printf("Enter no of Processes : ");
  scanf("%d",&n);
  process p[n];
  
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter arrival time, burst time and priority for process p%d :",i+1);
    scanf("%d",&p[i].at);
    scanf("%d",&p[i].bt);
    scanf("%d",&p[i].priority);
    p[i].rt=p[i].bt;
  }
  p[n-1].priority = n+1; 
  //pt[9]=11;
  printf("\n\nProcess\tTurnaround time Waiting time\n");
  
  for(time=0;remain!=0;time++)
  {
    smallest=n-1;
    for(i=0;i<n;i++)
    {
      if(p[i].at<=time && p[i].priority<p[smallest].priority && p[i].rt>0)
      {
    smallest=i;
      }
    }
    p[smallest].rt--;

    if(p[smallest].rt==0)
    {
      remain--;
      printf("P[%d]\t\t%d\t\t%d\n",smallest+1,time+1-p[smallest].at,time+1-p[smallest].at-p[smallest].bt);
      sum_wait+=time+1-p[smallest].at;
      sum_turnaround+=time+1-p[smallest].at-p[smallest].bt;
    }
  }
  printf("\nAvg waiting time = %f\n",sum_wait*1.0/n);
  printf("Avg turnaround time = %f",sum_turnaround*1.0/n);
  return 0;
}
