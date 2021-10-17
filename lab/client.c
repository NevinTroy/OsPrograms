#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<ctype.h>

#define SHMSIZE 27

int main(int argc,char* argv[]){

    key_t key;
    int shmid;
    char *shm,*s;
    char c;
    key=9976;

    shmid=shmget(key,SHMSIZE,0666);
    if(shmid<0){
        perror("shmget");
        return 1;
    }
    shm=shmat(shmid,NULL,0);
    if(shm== (char *)-1){
        perror("shmat");
        return 1;
    }

    for(s=shm;*s!='\0';s++){
        printf("\nClient is reading: %c\n",*s);
        printf("Client writes: %c\n",toupper(*s));
    }
    
    *shm='*';

    return 0;
}
