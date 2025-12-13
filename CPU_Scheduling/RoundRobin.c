#include<stdio.h>
typedef struct {
    int arrival;
    int burst;
    int remaining;
    int idx;
    int completed;
} Process;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Process p[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].burst);
        p[i].remaining = p[i].burst;
        p[i].completed = 0;
        p[i].idx = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].arrival);
    }
int quantum=2;    
int queue[2000];
int front=0,rear=0;
int current_time=0,completed=0;
double totaol_wait=0,total_tat=0;
int gantt[2000],g=0;
// Enqueue process that arrive at time 0;
for(i=0;i<n;i++)
{
    if(p[i].arrival==0)
    {
        queue[rear++]=i;
    }
}
while(completed<n)
{
    if(front==rear)
    {
        // 
    }
}