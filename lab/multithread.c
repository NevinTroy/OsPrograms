#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define max 15
int min,maximum;

typedef struct datastruct{
    int size;
    int *values;
}datastruct;

void *avg(void *ptr){
    int aveg=0;
    datastruct *num=(datastruct *)ptr;
    int n=num->size;
    int i;
    for(i=0;i<n;i++){
        aveg+=(num->values[i]);
    }
    printf("\nThe average is %d \n",(int)aveg/n);
}

void *max_val(void *ptr){
    datastruct *num=(datastruct *)ptr;
    int n=num->size;
    maximum=(num->values[0]);
    int i;
    for(i=1;i<n;i++){
        if(maximum<(num->values[i])){
            maximum=(num->values[i]);
        }
    }
    printf("The maximum value is %d\n",maximum);
}

void *min_val(void *ptr){
    datastruct *num=(datastruct *)ptr;
    int n=num->size;
    min=(num->values[0]);
    int i;
    for(i=1;i<n;i++){
        if(min>(num->values[i])){
            min=(num->values[i]);
        }
    }
    printf("The minimum value is %d\n",min);
}

int main(int argc,char* argv[]){

    int num[max],i=0;
    int count=0;
    while(argc--!=0){
        num[i++]=atoi(*argv++);
        count++;
    }

    /*The first argument is the execution which is ./multithread 
    and when we convert it to int we get 0. This value is not needed,
    therefore to discard it we execute the following for loop*/
    for(i=0;i<count-1;i++){
        num[i]=num[i+1];
    }
    count --;
    
    printf("The arguments are: \n");
    for(i=0;i<count;i++){
        printf("%d ",num[i]);
    }
    /*we can only pass one argument to the thread runner function 
    but to calculate all these values we need two arguments,
    therefore we create a structure as a pointer*/
    datastruct ds={count,num};

    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,&avg,&ds);
    pthread_create(&t2,NULL,&max_val,&ds);
    pthread_create(&t2,NULL,&min_val,&ds);


    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    return 0;
}
