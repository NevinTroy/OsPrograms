#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<time.h>

int main(int argc,char* argv[]){

    int fd[2];
    int pid=fork();
    
    if(pid==-1){
        return 1;
    }
    else if(pid == 0){
        //Child process
        close(fd[1]);

        srand(time(NULL));
        int arr[10];
        int i;
        int n;
        n = rand()%10 + 1;
        for(i=0;i<n;i++){
            arr[i]=rand()%20;
            printf("Sent %d\n",arr[i]);
        }
        write(fd[1],&n,sizeof(int));
        write(fd[1],arr,sizeof(int)*n);

        close(fd[1]);
    }
    else{
        //Parent process

        close(fd[1]);

        int arr[10];
        int n;
        int i,sum=0;

        read(fd[0],&n,sizeof(int));
        read(fd[0],arr,sizeof(int)*n);

        for(i=0;i<n;i++){
            printf("Recieved %d\n",arr[i]);
            // sum+=arr[i];
        }
        printf("Sum is %d \n",sum);
        close(fd[0]);

        wait(NULL);
    }


    return 0;
}