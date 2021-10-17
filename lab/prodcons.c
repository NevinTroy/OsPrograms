#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>

sem_t semEmpty;
sem_t semFull;

#define THREAD_NUM 2

int buffer[10];
int count=0;
pthread_mutex_t mutex;
int cp=0,cr=0;

void* producer(void* arg){

    while(1){
        if(cp<100){
            int x=rand()%100;
            sleep(1);
            sem_wait(&semEmpty);
            pthread_mutex_lock(&mutex);
            printf("Produced %d\n",x);
            buffer[count]=x;
            count++;  
            pthread_mutex_unlock(&mutex);
            sem_post(&semFull);
            cp++;
        }
        else{
            system("clear");
            sleep(10);
            cp=0;
        }
    }

}

void* consumer(void* arg){

    int y;
    while (1){   
        if(cr<100){
            sem_wait(&semFull);
            pthread_mutex_lock(&mutex);
            y=buffer[count-1];
            count--;
            printf("Consumed %d\n",y);
            pthread_mutex_unlock(&mutex);
            sem_post(&semEmpty);
            cr++;
        }
        else{
            system("clear");
            sleep(10);
            cr=0;
        }
    }
    
}

int main(int argc,char* argv[])
{
    srand(time(NULL));
    int i=0;
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&semFull,0,0);
    sem_init(&semEmpty,0,100);
    for(i=0;i<THREAD_NUM;i++){
        if(i%2==0){
            if(pthread_create(&th[i],NULL,&producer,NULL)!=0){
                perror("Failed to create thread");
                return 1;
            }
        }
        else{
            if(pthread_create(&th[i],NULL,&consumer,NULL)!=0){
                perror("Failed to create thread");
                return 1;
            }
        }
    }
    for(i=0;i<THREAD_NUM;i++){
        if(pthread_join(th[i],NULL)!=0){
            perror("Failed to join Thread");
            return 1;
        }
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    
    return 0;
}
