#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    pid_t pid=fork();
    if(pid>0){
        printf("This is the parent process\n");
        exit(0);
    }
    else{
        sleep(15);
        printf("This is the child process\n");
    }

    return 0;
}