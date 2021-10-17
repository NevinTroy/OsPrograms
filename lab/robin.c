#include<stdio.h>
#include<stdlib.h>
#define max 30

struct process{
    int pno,at,bt,ct,tat,wt,rt;
};
int main(){
    struct process p[max],t;
    int i,j,n;
    float atat=0,awt=0;
    int temp=0,tq,balancetime[max],count=0;
    int rq[max];
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
        balancetime[i]=p[i].bt;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    while(1){
        for(i=0,count=0;i<n;i++){
            if(balancetime[i]==0){
                count++;
                continue;
            }
            else if(balancetime[i]>=tq){
                temp+=tq;
                balancetime[i]-=tq;
            }
            else{
                if(balancetime[i]>0){
                    temp+=balancetime[i];
                    balancetime[i]=0;
                }
            }
        p[i].ct=temp;
        }
        if(count==n)
            break;
    }
    for(i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    printf("Process  ArrivalTime  BurstTime  CompletionTime TurnAroundTime WaitingTime \n");
    for(i=0;i<n;i++){
        printf("%4d \t %6d \t %4d \t  %5d\t\t%9d \t %5d\n",p[i].pno,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
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
