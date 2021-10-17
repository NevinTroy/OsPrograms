#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *fact(void* n){
    int num=*(int*)n;
    int f=1;
    int i;
    for(i=1;i<=num;i++){
        f=f*i;
    }
    printf("The factorial is %d\n",f);
}

int main(int argc,char* argv[]){

    pthread_t t1;
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    pthread_create(&t1,NULL,&fact,&n);
    pthread_join(t1,NULL);

    return 0;
}
