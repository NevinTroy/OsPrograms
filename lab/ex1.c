#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char argv[]){
    printf("pID of ex1.c = %d \n",getpid());
    char *args[]={"Hello","Neso","Academy",NULL};
    execv("./ex2.c",args);
    printf("Back to the ex1.c");
}
