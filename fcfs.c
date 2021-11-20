#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
void FCFS(int arr[], int head, int size){
    int seek_count = 0;
    int distance, cur_track;
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
  
    printf("Total number of seek operations = %d",seek_count);
    printf("\nSeek Sequence is \n");
    for (int i = 0; i < size; i++) {
        printf("%d\n",arr[i]);
    }
}

int main(int argc,char* argv[]){ 
    int n,head;
    printf("%s\n", "Enter the number of disk tracks:");
    scanf("%d", &n);
    int proc[n];
    printf("%s\n", "Enter disk track numbers");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &proc[i]);
    }
    printf("%s\n", "Enter initial head position");
    scanf("%d", &head);
    FCFS(proc, head, n);
    return 0;
}
