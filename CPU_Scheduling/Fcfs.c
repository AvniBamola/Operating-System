#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int arrival;
    int burst;
    int idx;
} Process;

int comparator(const void *a,const void *b)
{
    Process *p1=(Process*)a;
    Process *p2=(Process*)b;
    if(p1->arrival !=p2->arrival)
    {
        return p1->arrival-p2->arrival;
    }
    return p1->idx-p2->idx;
}
int main()
{
    int n,i,g=0,total_waiting_time=0,total_turnaround_time=0;
    printf("Enter the number of peocesses");
    scanf("%d",&n);
    Process *p=malloc(sizeof(Process)*n);
    if(p==NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        p[i].idx=i;
        scanf("%d",&p[i].burst);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].arrival);
    }
    //sort by arrival time , tie by original index
    qsort(p,n,sizeof(Process),comparator);
    int current_time=0,waiting_time=0,completion_time=0,turnaround_time=0,start_time=0;
    int gantt[n];
    for(i=0;i<n;i++)
    {
        if(current_time<p[i].arrival)
        {
            //CPU sits idle until this process arrives
            current_time=p[i].arrival;
        }
        start_time=current_time;
        waiting_time=start_time-p[i].arrival;
        completion_time=start_time+p[i].burst;
        turnaround_time=completion_time-p[i].arrival;
        gantt[g++]=p[i].idx;
        current_time = completion_time;
        total_turnaround_time+=turnaround_time;
        total_waiting_time+=waiting_time;
    }
    printf("Gantt Chart :");
      for (int i = 0; i < g; ++i) {
        printf(" P%d", gantt[i]);
    }
     printf("Average waiting time: %.2f\n",(double)total_waiting_time / n);
    printf("Average turnaround time : %.2f\n", (double)total_turnaround_time / n);

    free(p);
    return 0;
}