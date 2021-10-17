#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
	int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
 
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
	}

	printf("Enter the number of blocks(partitions in memory): ");
	scanf("%d", &bno);

    printf("Enter the number of processes: ");
	scanf("%d", &pno);
	
	printf("\nEnter the size of each block:\n");
	for(i = 0; i < bno; i++)
    {
		printf("Block no.%d:",(i+1));
        scanf("%d", &bsize[i]);
    }
	printf("\nEnter the size of each process:\n");
	for(i = 0; i < pno; i++)
    {
		printf("Process no.%d:",(i+1));
        scanf("%d", &psize[i]);
    }   
	for(i = 0; i < pno; i++)         
		for(j = 0; j < bno; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}

	printf("\nBlock no.\tSize\t\tProcess no.\t\tSize\t\tFragment");
	for(i = 0; i < bno; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d\t\t%d",allocation[i]+1,psize[allocation[i]],(bsize[i]-psize[allocation[i]]));
		else
			printf("NOT ALLOCATED");
	}
    printf("\n");

	return 0;
}
