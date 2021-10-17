#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculatedifference(int request[], int head,int diff[][2], int n){
    for (int i = 0; i < n; i++){
        diff[i][0] = abs(head - request[i]);
    }
}

int findMIN(int diff[][2], int n){
    int index = -1;
    int minimum = 1e9;

    for (int i = 0; i < n; i++){
        if (!diff[i][1] && minimum > diff[i][0]){
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(int request[],int head, int n){
    if (n == 0){
        return;
    }

    int diff[n][2];
    for (int i = 0; i < n; i++)
        diff[i][0] = diff[i][1] = 0;

    int seekcount = 0;

    int seeksequence[n + 1];

    for (int i = 0; i < n; i++){
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;
        seekcount += diff[index][0];
        head = request[index];
    }
    seeksequence[n] = head;

    printf("\nTotal number of seek operations = %d", seekcount);
    printf("\nSeek sequence is : ");

    for (int i = 0; i <= n; i++){
        printf("%d\n", seeksequence[i]);
    }
}


int main(int argc,char* argv[]){
    int n,head;
    printf("%s\n", "Enter the number of disk tracks:");
    scanf("%d", &n);
    int proc[n];
    printf("%s\n", "Enter disk track numbers");
    for (int i = 0; i < n; i++){
        scanf("%d", &proc[i]);
    }
    printf("%s\n", "Enter initial head position");
    scanf("%d", &head);
    shortestSeekTimeFirst(proc, head, n);
    return 0;
}
