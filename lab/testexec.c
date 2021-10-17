#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){

    int id=fork();
    if(id==-1){
        return 1;
    }
    if(id==0){
        int err=execlp("ping","ping","-c","3","google.com",NULL);
        if(err==-1){
            return 2;
        }
        printf("This statement wont get printed because it has been replaced\n");
    }
    else{
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus)){
            int statusCode=WEXITSTATUS(wstatus);
            if(statusCode==0){
                printf("Success\n");
            }
            else{
                printf("Failed with status code %d\n",statusCode);
            }
        }
    }
    return 0;
}