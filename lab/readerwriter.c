#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int readercount=0;
int value=1;
sem_t db;
pthread_mutex_t mutex;

void* write(void* arg){

    srand(time(NULL));
    int i= *(int *)arg;
    sem_wait(&db);
    int val=rand()%10;
    value=value*val;
    printf("Writer %d has changed value to %d\n",i,value);
    sem_post(&db);

}

void* read(void* arg){

    int i=*(int *)arg;

    pthread_mutex_lock(&mutex);
    readercount=readercount+1;
    if(readercount==1){
        sem_wait(&db);
    }
    pthread_mutex_unlock(&mutex);

    printf("Reader %d reads value as %d\n",i,value);

    pthread_mutex_lock(&mutex);
    readercount=readercount-1;
    if(readercount==0){
        sem_post(&db);
    }
    pthread_mutex_unlock(&mutex);

}

int main(int argc,char* argv[]){
    
    int i=0;
    pthread_t reader[10],writer[5];
    sem_init(&db,0,1);
    pthread_mutex_init(&mutex,NULL);
    
    for(i=0;i<10;i++){
        pthread_create(&reader[i],NULL,&read,(void *)&i);
    }
    for(i=0;i<5;i++){
        pthread_create(&writer[i],NULL,&write,(void *)&i);
    }
    for(i=0;i<10;i++){
        pthread_join(reader[i],NULL);
    }
    for(i=0;i<5;i++){
        pthread_join(writer[i],NULL);
    }

    sem_destroy(&db);
    pthread_mutex_destroy(&mutex);

    return 0; 
}