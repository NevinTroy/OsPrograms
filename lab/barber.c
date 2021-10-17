#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t cus;
sem_t barb;
sem_t cutting;
pthread_mutex_t mutex;
int c1=0;
int n=5;

void *barber(void *arg){

    sem_wait(&cus);
    pthread_mutex_lock(&mutex);
    c1=c1-1;
    printf("Barber is cutting hair\n");
    sem_post(&barb);
    pthread_mutex_unlock(&mutex);
    sleep(3);

}

void *customer(void *arg){

    pthread_mutex_lock(&mutex);
    if(c1<n){
        c1=c1+1;
        printf("Customer added\n");
        sem_post(&cus);
        pthread_mutex_unlock(&mutex);
        sem_wait(&barb);
    }
    else{
        printf("shop is full\n");
        pthread_mutex_unlock(&mutex);
    }
}

// void cut_hair(){
//     printf("Barber is busy cutting hair\n");
//     sem_wait(&cutting);
// }

// void get_haircut(){
    
//     printf("Customer is getting hair cut\n");
//     sleep(1);
//     sem_post(&cutting);
// }


int main(int argc,char* argv){

    int i;
    sem_init(&cus,0,0);
    sem_init(&barb,0,1);
    sem_init(&cutting,0,0);
    pthread_mutex_init(&mutex,NULL);
    pthread_t customers[7],barbers;

    for(i=0;i<n;i++){
        pthread_create(&customers[i],NULL,&customer,&i);
    }
    pthread_create(&barbers,NULL,&barber,NULL);

    for(i=0;i<n;i++){
        pthread_join(customers[i],NULL);
    }
    pthread_join(barbers,NULL);

    sem_destroy(&cus);
    sem_destroy(&barb);
    sem_destroy(&cutting);
    pthread_mutex_destroy(&mutex);
    return 0;
}