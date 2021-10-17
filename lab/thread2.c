#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

//Creating thread runner function
void *routine(void *c){
    char *message=(char *)c;
    printf("%s\n",message);
}

int main(int argc,char* argv[]){

    char *message1="Hello from t1";
    char *message2="Hello from t2";

    //Setting Thread attributes
    pthread_t t1,t2;

    pthread_create(&t1,NULL,&routine,(void*)message1);
    pthread_create(&t2,NULL,&routine,(void*)message2);

    //joining the threads
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}
