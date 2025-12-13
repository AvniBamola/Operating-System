#include<stdio.h>
#define MAXP 50
#define MAXR 10

int main()
{
    int p,r,i,j;
    printf("Enter the number of processes and resources available");
    scanf("%d",&p);
    scanf("%d",&r);

    int Max[MAXP][MAXR];
    int Alloc[MAXP][MAXR];
    int Need[MAXP][MAXR];
    int Available[MAXR];
    int Finish[MAXP]={0};
    int SafeSeq[MAXP];

    /*Read Max*/
    printf("Enter the maximum resources requires\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&Max[i][j]);
        }
    }
    /*Read Allocation*/
    printf("Enter the resources allocated\n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&Alloc[i][j]);
        }
    }
    printf("Enter the available resources \n");
/*Read Available Directly*/
for(j=0;j<r;j++)
{
    scanf("%d",&Available[j]);
}
/*Need=Max-Alloc*/

for(i=0;i<p;i++)
{
    for(j=0;j<r;j++)
    {
        Need[i][j]=Max[i][j]-Alloc[i][j];
    }
}

/*Safety Algorithm*/

int count=0,progress=1;
while(count<p && progress==1)
{
    progress=0;
    for(i=0;i<p;i++)
    {
        if(Finish[i]==0)
        {
            int can_run=1;
            for(j=0;j<r;j++)
            {
                if(Need[i][j]>Available[j])
                {
                    can_run=0;
                    break;
                }
            }
            if(can_run==1)
            {
                for(j=0;j<r;j++)
                {
                    Available[j]+=Alloc[i][j];
                }
                SafeSeq[count]=i;
                count++;
                Finish[i]=1;
                progress=1;
            }
        }
    }
}
if(count==p)
{
    printf("Request can be fulfilled\n");
    printf("Safe Sequence:");
    for(i=0;i<p;i++)
    {
        printf("P%d ",SafeSeq[i]);
    }
    printf("\n");
}
else
{
    printf("Request cannot be fulfilled\n");
}
}
