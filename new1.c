#include<stdio.h>

int main()
{
    printf("\n FIXES SIZE MEMORY PARTIONING\n");
    int avail_mem=4000000;
    printf("\nAvailable Memory = 4 MB");
    printf("\nFrame Size = 16 KB");
    int frame_size=16000;
    int no_frames=avail_mem/frame_size;
    printf("\nNo of frames = %d",no_frames);
    int frame_full=0;
    printf("\nNo of occupied frames: %d",frame_full);
    printf("\nNo of free frames: %d",(no_frames-frame_full));
    int p_size=1024000;
    printf("\nSize of New Process: %d Bytes",p_size);
    int p_frames=p_size/frame_size;
    printf("\nNo of frames taken by process = %d",p_frames);
    frame_full+=p_frames;
    int page_table[p_frames],i,j=0;
    printf("\nPAGE TABLE BEFORE ALLOCATION");
    for(i=0;i<p_frames;i++)
    {
        page_table[i]=0;
        printf("\n%d-----%d",i,page_table[i]);
    }  
    for(i=p_frames;i>=0;i--)
        page_table[j++]=i;
    printf("\nPAGE TABLE ENTRY");
    for(i=0;i<p_frames;i++)
    {
        printf("\n%d-----%d",i,page_table[i]);
    }    
    return 0;
}