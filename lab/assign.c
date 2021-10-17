#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    pid_t pid;
    char *args[]={"./assign2",NULL};
    printf("We are in the first program\n");
    execv(args[0],args);
}
