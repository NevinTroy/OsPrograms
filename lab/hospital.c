#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 30

struct patient{
    int priority,pno,at,bt,ct,tat,wt,rt;
};

int main(){
    struct patient p[max],t;
    int i,j,n;
    float atat=0,awt=0;
    int temp=0;
    printf("Enter the number of patients:\n");
    scanf("%d",&n);
    char type[10];
    for(i=0;i<n;i++)
    {
    printf("\nPatient %d Details",(i+1));
    printf("\nEnter the arrival time: ");
    
        scanf("%d",&p[i].at);
        p[i].pno=i+1;
   printf("\nEnter the estimated time taken: ");
   
        scanf("%d",&p[i].bt);
   
   printf("\nEnter the Patient type: ");
   scanf("%s",&type);
    if(strcmp(type,"Emergency")==0)
         p[i].priority = 1;
    else if(strcmp(type,"Woman")==0)
        p[i].priority = 2;
    else if(strcmp(type,"Child")==0)
        p[i].priority = 3;
    else if(strcmp(type,"Old")==0)
        p[i].priority = 4;
    else if(strcmp(type,"Young")==0)     
       p[i].priority = 5;
    else
        p[i].priority = 6;
   } 

   for(i=0;i<n;i++){
      for(j=0;j<n-i-1;j++){
          if(p[j].priority<p[j+1].priority && p[j].at>=p[j+1].at){
                 t=p[j];
                 p[j]=p[j+1];
                 p[j+1]=t;
          }
      }
   }
  for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].bt>p[j+1].bt && p[j].at>=p[j+1].at){
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
   printf("Patient  ArrivalTime  BurstTime  CompletionTime TurnAroundTime WaitingTime ResponseTime\n");
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