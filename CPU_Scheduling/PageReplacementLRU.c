#include<stdio.h>
int main()
{
    int frames,pages;
    int pageFaults=0;
    int counter =0,i,j;    // New : Keeps track of time

    printf("Enter number of frames:");
    scanf("%d",&frames);

    printf("Enter number of pages:");
    scanf("%d",&pages);

    int frame[frames];
    int ref[pages];
    int time[frames];     // New :last used time of each frame

    // Initialize frames
    for(i=0;i<frames;i++)
    {
        frame[i]=-1;
        time[i]=0;
    }

    printf("Enter page reference string:\n");
    for(i=0;i<pages;i++)
    {
        scanf("%d",&ref[i]);
    }
    for(i=0;i<pages;i++)
    {
        int found=0;
        for(j=0;j<frames;j++)
        {
            if(frame[j]==ref[i])
            {
                found=1;
                counter++;
                time[j]=counter;     // Update recent use
                break;
            }
        }
        // Page Fault
        if(found==0)
        {
            // Step 1: First check for empty frame

            int pos=-1;
            for(j=0;j<frames;j++)
            {
                if(frame[j]==-1)
                {
                    pos=j;
                    break;
                }
            }
        // Step 2: no empty frames available , LRU must be applied
        if(pos==-1)
             {
                pos=0;
            // Find least recently used page
            for(j=1;j<frames;j++)
            {
                if(time[j]<time[pos])
                {
                    pos=j;
                }
            }
        }
        // insert page common for both cases
            counter++;
            frame[pos]=ref[i];    // Replace LRU page
            time[pos]=counter;
            pageFaults++;
        // Print Frames
        for(j=0;j<frames;j++)
        {
            printf("%d  ",frame[j]);
        }
        printf("\n");
    }
}
    printf("Total page faults=%d\n",pageFaults);
    return 0;
}