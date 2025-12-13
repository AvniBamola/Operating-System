// For Priority scheduling simply add a priority variable in structure and just change the if condition instead of comparing on the basis of shortest burst time simply compare on the basis of priority
#include<stdio.h>
typedef struct{
    int arrival;
    int burst;
    int remaining;
    int idx;
    int completed;
}Process;

int main()
{
    int n;
    scanf("%d",&n);
    Process p[100];
    int i;

    for(i=0;i<n;i++)
    {
        p[i].idx=i;
        p[i].completed=0;
        scanf("%d",&p[i].burst);
        p[i].remaining=p[i].burst;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].arrival);
    }

    int completed_count=0;
    double total_wait=0,total_tat=0;
    int gantt[500],g=0;
    int current_time=0,wait=0,start=0,complete=0,tat=0;

    //Main Loop
    while(completed_count<n)
    {
        int min_index=-1;
        int min_remaining_burst=1e9;
        //Find the process with smallest burst time among the arrives ones
        for(i=0;i<n;i++)
        {
            if(p[i].completed==0 && p[i].arrival<=current_time)
            {
                if(p[i].remaining<min_remaining_burst)
                {
                    min_remaining_burst=p[i].remaining;
                    min_index=i;
                }
            }
        }
        // If no process has yet arrives CPU sits idle
        if(min_index==-1)
        {
            current_time++;
            continue;
        }
        // Run process for 1 unit (Preemptive Part)
        p[min_index].remaining--;
        gantt[g++]=min_index;    // store execution order
        current_time++;

        // if completed now
        //run the selected process
        if(p[min_index].remaining==0)
        {
            p[min_index].completed=1;
            completed_count++;
        complete=current_time;
        tat=complete-p[min_index].arrival;
        wait=tat-p[min_index].burst;
        total_wait+=wait;
        total_tat+=tat;
    }
}
    printf("Gantt Chart :");
    for (int i = 0; i < g; i++)
        printf(" P%d", gantt[i]);
    printf("\n");

    printf("Average waiting time: %.2f\n", total_wait / n);
    printf("Average turnaround time : %.2f\n", total_tat / n);

}