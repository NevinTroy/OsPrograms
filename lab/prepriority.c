#include<stdio.h>
 
struct process{
    int no;
    int at, bt, ct, wt, tat, priority;
    int status;
}p[10];
 
int limit;
 
void at_Sorting(){
    struct process temp;
    int i, j;
    for(i = 0; i < limit - 1; i++){
        for(j = i + 1; j < limit; j++){
            if(p[i].at > p[j].at){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main(int argc,char* argv[]){

    int i, time = 0, bt = 0, largest;
    float wait_time = 0, tat = 0, average_wt, average_tat;
    printf("Enter Total Number of Processes:");
    scanf("%d", &limit);
    printf("Enter Arrival Time: \n");
    for(i = 0; i < limit; i++){
        p[i].no=i+1;
        scanf("%d", &p[i].at );
    }
    printf("Enter Burst Time: \n");
    for(i = 0; i < limit; i++){
        scanf("%d", &p[i].bt);
    }
    printf("Enter Priority: \n");
    for(i = 0; i < limit; i++){
        scanf("%d", &p[i].priority);
        p[i].status = 0;
        bt = bt + p[i].bt;
    }
    at_Sorting();
    p[9].priority = -9999;
    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
    for(time = p[0].at; time < bt;){
        largest = 9;
        for(i = 0; i < limit; i++){
            if(p[i].at <= time && p[i].status != 1 && p[i].priority > p[largest].priority){
                largest = i;
            }
        }
        time = time + p[largest].bt;
        p[largest].ct = time;
        p[largest].wt = p[largest].ct - p[largest].at - p[largest].bt;
        p[largest].tat = p[largest].ct - p[largest].at;
        p[largest].status = 1;
        wait_time = wait_time + p[largest].wt;
        tat = tat + p[largest].tat;
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[largest].no,p[largest].at, p[largest].bt, p[largest].priority, p[largest].wt);
    }
    average_wt = wait_time / limit;
    average_tat = tat / limit;
    printf("\n\nAverage waiting time:\t%4.2f\n", average_wt);
    printf("Average Turnaround Time:\t%4.2f\n", average_tat);

    return 0;
}