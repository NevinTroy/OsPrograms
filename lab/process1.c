#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    printf("Process Id before forking: %d\n",getpid());
    int id=fork();
    if(id==0){
        printf("Child process ID after forking: %d\n",getpid());
    }
    else{
        printf("Parent process ID after forking: %d\n",getpid());
    }
    return 0;
}
