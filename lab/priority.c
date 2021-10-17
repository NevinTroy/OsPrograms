#include<stdio.h>
#include<stdlib.h>
#define max 30

struct process{
    int priorityno,pno,at,bt,ct,tat,wt,rt;
};
int main(){
    struct process p[max],t;
    int i,j,n;
    float atat=0,awt=0;
    int temp=0;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("Enter the arrival time of each process: \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].at);
        p[i].pno=i+1;
    }
    printf("Enter the burst time of each process: \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].bt);
    }
    printf("Enter the priority of each process: \n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i].priorityno);
    }
    //Bubble Sorting the processes based on their priority
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].priorityno<p[j+1].priorityno && p[j].at>=p[j+1].at){
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++){
        /*if the process hasn't reached the ready queue yet,
        increment the time till it reaches the first process*/
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
    //sorting the processes based on their process number
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].pno>p[j].pno){
                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    printf("Process  ArrivalTime  BurstTime  CompletionTime TurnAroundTime WaitingTime ResponseTime\n");
    for(i=0;i<n;i++){
        printf("%4d \t %6d \t %4d \t  %5d\t\t%9d \t %5d \t\t %2d\n",p[i].pno,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
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