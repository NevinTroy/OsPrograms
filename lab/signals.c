#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>

int main(int argc,char* argv[]){

    int pid=fork();
    if(pid == -1){
        return 1;
    }
    if(pid==0){
        while(1){
            printf("Some text\n");
            usleep(100000);
        }
    }
    else{
        kill(pid,SIGSTOP);
        int t;
        do{
            printf("Enter the time: ");
            scanf("%d",&t);
            if(t>0){
                kill(pid,SIGCONT);
                sleep(t);
                kill(pid,SIGSTOP);
            }
        }while(t>0);
        
    }
    
    return 0;
}