#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>

void* writeRoutine(){
    int fd;
    mode_t mode=S_IRUSR| S_IWUSR | S_IRGRP | S_IROTH;
    char *filename="/tmp/input1";
    fd=creat(filename,mode);

    fd=open("/tmp/input1",O_WRONLY,0);

    char b[100]="Date\tStoreInfo\tAmount\n";
    ssize_t nb=strlen(b);
    ssize_t bytesWritten=write(fd,b,nb);
    
    char input[100];
    int i=0;
    for(i=0;i<10;i++){
        printf("Input: ");
        fgets(input,200,stdin);
        input[strlen(input)-1]='\n';
        ssize_t n=strlen(input);
        bytesWritten=write(fd,input,n);
    }   

}

void *readRoutine(){
    
    int fd;
    mode_t mode=S_IRUSR| S_IWUSR | S_IRGRP | S_IROTH;
    char *filename="/tmp/input1";
    fd=open("/tmp/input1",O_RDONLY,0);
    char output[10];
}

int main(int argc,char* argv[]){

    pthread_t t1,t2;
    if( pthread_create(&t1,NULL,&writeRoutine,NULL)<0){
        perror("Thread couldn't be created");
        return 1;
    }
    pthread_join(t1,NULL);

    return 0;
}
