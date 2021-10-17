#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *arg){
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from Thread %d \n",*(int *)arg);
    sem_post(&semaphore);
}

int main(int argc,char* argv[]){

    pthread_t th[THREAD_NUM];
    int i;
    sem_init(&semaphore,0,1);
    for(i=0;i<THREAD_NUM;i++){
        int *a=malloc(sizeof(int));
        *a=i;
        if(pthread_create(&th[i],NULL,&routine,a)!=0){
            perror("Failed to create Thread");
        }
    }
    for(i=0;i<THREAD_NUM;i++){
        if(pthread_join(th[i],NULL)!=0){
            perror("Failed to join");
            return 1;
        }
    }
    sem_destroy(&semaphore);
    return 0;
}
