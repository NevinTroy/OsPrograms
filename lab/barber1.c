#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int n=5;
sem_t waitingRoom,barberChair,barber,cutting;
int allDone=0;

void *cus(void *arg){
    int i=*(int *)arg;
    srand(time(NULL));
    int t=rand()%5;
    
    sleep(t);
    printf("Customer %d has reached the shop \n",i);
    sem_wait(&waitingRoom);
    printf("Customer %d is waiting \n",i);
    sem_wait(&barberChair);
    sem_post(&waitingRoom);
    printf("Customer is waking the barber up\n");
    sem_post(&barber);
    sem_wait(&cutting);
    sem_post(&barberChair);
    printf("Customer %d is leaving the shop\n",i);

}
void *barb(void* arg){

    srand(time(NULL));
    int t=rand()%5;
    while (!allDone){
        sem_wait(&barber);
        if(!allDone){
            printf("The barber is cutting hair\n");
            sleep(t);
            printf("The barber has finished cutting hair\n");
            sem_post(&cutting);
        }
        else{
            printf("The barber is going home\n");
        }
    
    }
    

}

int main(int argc,char* argv[]){

    pthread_t customers[7],barbers;
    int i;
    sem_init(&waitingRoom,0,n);
    sem_init(&barberChair,0,1);
    sem_init(&barber,0,0);
    sem_init(&cutting,0,0);

    pthread_create(&barbers,NULL,&barb,NULL);
    for(i=0;i<7;i++){
        pthread_create(&customers[i],NULL,&cus,&i);
    }
    for(i=0;i<7;i++){
        pthread_join(customers[i],NULL);
    }
    allDone=1;
    sem_post(&barber);
    pthread_join(barbers,NULL);

    return 0;
}