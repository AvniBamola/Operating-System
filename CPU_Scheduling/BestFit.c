#include<stdio.h>
int main()
{
    int b,p,i,j;
    printf("Enter number of blocks:");
    scanf("%d",&b);

    int block[b];
    int used[b]; // 0=free , 1=used

    printf("Enter block sizes:\n");
    for (int i = 0; i < b; i++) {
        scanf("%d", &block[i]);
        used[i] = 0;
    }
    printf("Enter the number of processes\n");
    scanf("%d",&p);

    int process[p];
    printf("Enter process sizes\n");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &process[i]);
    }
    // Best Fit Allocation
    
for(i=0;i<p;i++)
{
    int best=-1;
    for(j=0;j<b;j++)
    {
        if(used[j]==0 && block[j]>=process[i])
        {
            if(best==-1 || block[j]<block[best])
            {
                best=j;
            }
        }
    }
    if(best!=-1)
    {
        printf("Process %d allocated to Block %d\n", i+1, best+1);
        used[best] = 1;
    }
    else
    {
      printf("No free block available for process %d\n", i+1);

    }
}
    return 0;
}
