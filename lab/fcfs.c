#include<stdio.h>
#include<stdlib.h>
#define max 30

struct process{
    int at,bt,ct,tat,wt,rt;
};

int main(){
    struct process p[max];
    int i,j,n;
    float atat=0,awt=0;
    int temp=0;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("Enter the arrival time of each process: \n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i].at);
    printf("Enter the burst time of each process: \n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i].bt);
    for(i=0;i<n;i++){
        /*check if the process has reached the ready queue,
        if not keep incrementing the value of temp till
        it reaches the arrival time of the next process
        */
        if(temp<p[i].at){
            while(temp<p[i].at){
                temp++;
            }
        }
        p[i].ct=temp+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        p[i].rt=temp-p[i].at;

        temp+=p[i].bt;
    }
    printf("Process  ArrivalTime  BurstTime  CompletionTime TurnAroundTime WaitingTime ResponseTime\n");
    for(i=0;i<n;i++){
        printf("%4d \t %6d \t %4d \t  %5d\t\t%9d \t %5d \t\t %2d\n",i+1,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    for(i=0;i<n;i++){
        atat+=p[i].tat;
        awt+=p[i].wt;
    }
    atat=atat/n;
    awt=atat/n;
    printf("The average waiting time is: %5.3f\n",awt);
    printf("The average turn around time is: %5.3f\n",atat);
    return 0;
}
