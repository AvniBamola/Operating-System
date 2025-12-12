#include<stdio.h>
typedef struct{
    int arrival;
    int burst;
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
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i].arrival);
    }
    int completed_count=0;
    int current_time=0;
    double total_wait=0,total_tat=0;
    int gantt[100],g=0;
    int current_time=0,wait=0,completion=0,tat=0;

    //Main Loop
    while(completed_count<n)
    {
        int min_index=-1;
        int min_burst=1e9;
        //Find the process with smallest burst time among the arrives ones
        for(i=0;i<n;i++)
        {
            if(p[i].completed==0 && p[i].arrival<=current_time)
            {
                if(p[i].burst<min_burst)
                {
                    min_burst=p[i].burst;
                    min_index=i;
                }
            }
        }
        // If no process has yet arrives CPU sits idle
        if(min_index==-1)
        {
            curent_time++;
            continue;
        }
        //run the selected process
        
    }
}