#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

void* roll_dice(){
    srand(time(NULL));
    int value=rand()%6 +1;
    int *result=malloc(sizeof(int));
    *result=value;
    return (void *) result;
}   

int main(int argc,char* argv[]){

    pthread_t t1;
    int *res;
    pthread_create(&t1,NULL,&roll_dice,NULL);
    pthread_join(t1,(void **) &res);
    printf("The value is %d",*res);
    free(res);
    
    return 0;
}