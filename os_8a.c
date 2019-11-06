#include<stdio.h>
#define MAX 20
 
int main()
{
    int n;                          // total number of processes
    int burst_time[MAX];            // burst time array for all processes
    int wait_time[MAX] = {0};       // wait time array for all processes
    int turn_around_time[MAX];      // turn around times for all processes
    int av_wait_time=0;             // average wait time
    int av_turn_around_time=0;      // average turn around time
    int i,j;                        // for iterating

    printf("Enter the total number of processes (max 20):");
    scanf("%d",&n);
 
    printf("\nEnter Process Burst Time\n");
    for(i=0; i<n; i++)
    {
        printf("P(%d):", i+1);
        scanf("%d", &burst_time[i]);
    }
 
    for(i=1; i<n; i++)
    {
        for(j=0; j<i; j++)    wait_time[i] += burst_time[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    for(i=0; i<n; i++)
    {
        turn_around_time[i] = burst_time[i] + wait_time[i];
        av_wait_time += wait_time[i];
        av_turn_around_time += turn_around_time[i];
        printf("\n  P(%d) \t\t%d  \t\t%d  \t\t%d", i+1, burst_time[i], wait_time[i], turn_around_time[i]);
    }
 
    av_wait_time /= i;
    av_turn_around_time /= i;

    printf("\n\nAverage Waiting Time: %d",av_wait_time);
    printf("\nAverage Turnaround Time: %d\n",av_turn_around_time);
 
    return 0;
}

