#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
    //fd[0]-used for read
    //fd[1]-used for write
    int fd[2];
    if(pipe(fd)==-1){
        printf("There has been an error with the pipe");
        return 1;
    }

    int id=fork();
    if(id==0){
        //writing to pipe from child process
        int x;
        printf("Welcome to the child process, please enter a number: \n");
        scanf("%d",&x);
        //writing to pipe using write()
        //write(location to be written into,address of value,size)
        write(fd[1],&x,sizeof(x));
        close(fd[1]);
        close(fd[0]);
    }
    else{
        wait(NULL);
        printf("Welcome to the parent process\n");
        int y;
        //reading from pipe using read()
        //read(location to be read from,var to be read into,size)
        read(fd[0],&y,sizeof(y));
        printf("The value of y is: %d \n", y);
        close(fd[0]);
        close(fd[1]);
    }
    return 0;
}