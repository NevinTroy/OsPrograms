#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>


int main(int argc,char* argv[]){
    
    int fd[2];
    if(pipe(fd)<0){
        return 1;
    }
    
    int pid=fork();
    if(pid<0){
        return 2;
    }

    if(pid==0){
        close(fd[0]);
        char s[100];
        int n=strlen(s)+1;
        printf("Enter message:\n");
        fgets(s,100,stdin);
        s[n-1]='\0';
        write(fd[1],&n,sizeof(int));
        write(fd[1],s,sizeof(char)*n);
        close(fd[1]);
    }
    else{
        close(fd[1]);
        char s[100];
        int n;
        read(fd[0],&n,sizeof(int));
        read(fd[0],s,sizeof(char)*n);
        printf("The message is %s:\n",s);
        close(fd[0]);
        wait(NULL);
    }
    
    
    return 0;
}