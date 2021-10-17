#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[5];

void eat(int phil){
	printf("\nPhilosopher %d is eating",phil);
}

void* philosopher(void* arg){
	int i=*(int *)arg;

	sem_wait(&room);
	printf("\nPhilosopher %d has entered room",i);
	sem_wait(&chopstick[i]);
	sem_wait(&chopstick[(i+1)%5]);
	eat(i);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",i);
	sem_post(&chopstick[i]);
	sem_post(&chopstick[(i+1)%5]);
	sem_post(&room);
}

int main()
{
	int i;
	pthread_t th[5];
	int *a=malloc(sizeof(int));
	sem_init(&room,0,4);
	
	for(i=0;i<5;i++){
        sem_post(&chopstick[i]);
    }
	for(i=0;i<5;i++){
		*a=i;
		if(pthread_create(&th[i],NULL,philosopher,a)!=0){
            perror("Thread coudn't be created");
            return 1;
        };
	}
	for(i=0;i<5;i++){
        if(pthread_join(th[i],NULL)!=0){
            perror("Thread failed to join");
            return 1;
        };
    }

    return 0;
}
