#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    pid_t id=fork();
    if(id==0){
        printf("Child process\n");
        exit(0);
    }
    else{
        sleep(50);
    }

    return 0;
}
