#include<stdio.h>
int main()
{
    int b,p,i;
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
    // First Fit Allocation
    for(i=0;i<p;i++)
    {
        int allocated=0;
        for(int j=0;j<b;j++)
        {
            if(used[j]==0 && block[j]>=process[i])
            {
                printf("Process %d allocated to Block %d\n",i+1,j+1);
                used[j]=1;
                allocated=1;
                break;
            }
        }
        if(allocated==0)
        {
            printf("No free block available for process =>%d\n",i+1);
        }
    }
    return 0;
}
