#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *routine(void* n){
    int a=*(int*)n;
    int i=0,flag=0;
    for(i=2;i<=a/2;i++){
        if(a%i==0){
            flag++;
            break;
        }
    }
    if(flag==0){
        printf("The number is prime\n");
    }
    else{
        printf("The number is not prime\n");
    }
}

int main(int argc,char* argv[]){

    pthread_t t1;
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    pthread_create(&t1,NULL,&routine,&n);
    pthread_join(t1,NULL);
    return 0;
}
