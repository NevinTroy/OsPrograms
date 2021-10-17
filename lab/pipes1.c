#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
    int fd[2];
    if(pipe(fd)==-1){
        printf("There has been an error with the pipe");
        return 1;
    }
    char message[10]="Hello",rm[10];
    printf("Writing message to pipe\n");
    write(fd[1],&message,sizeof(message));
    printf("Reading message from pipe\n");
    read(fd[0],&rm,sizeof(rm));
    printf("%s\n",rm);
    close(fd[0]);
    close(fd[1]);
    return 0;
}
