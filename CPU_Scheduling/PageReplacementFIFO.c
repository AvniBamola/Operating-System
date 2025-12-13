#include<stdio.h>
int main()
{
    int frames,pages;
    int pageFaults=0;
    int pointer=0,i,j;

    printf("Enter thr number of frames\n");
    scanf("%d",&frames);

    printf("Enter the number of pages\n");
    scanf("%d",&pages);

    int frame[frames];
    int ref[pages];
    // Initially frames are empty

    for(i=0;i<frames;i++)
    {
        frame[i]=-1;
    }
    printf("Enter page reference string\n");
    for(i=0;i<pages;i++)
    {
        scanf("%d",&ref[i]);
    }
    // FIFO Algorithm
    for(i=0;i<pages;i++)
    {
        int found=0;
        //check if page already exists in the frame
        for(j=0;j<frames;j++)
        {
            if(ref[i]==frame[j])
            {
                found=1;
                break;
            }
        }
        // Page fault
        if(found==0)
        {
            frame[pointer]=ref[i];
            pointer=(pointer+1)%frames;
            pageFaults++;
        }
        //print Frames
        for(j=0;j<frames;j++)
        {
            printf("%d",frame[j]);
        }
        printf("\n");
    }
    printf("Total page faults=%d\n",pageFaults);
}