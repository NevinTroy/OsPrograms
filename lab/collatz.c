#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
    int n;
    pid_t pid;
    do{
		printf("Please enter a number :\n"); 
  		scanf("%d", &n);	
	}while (n<= 0);
    pid =fork();
    if(pid==0){
        printf("\nChild process is working\n");
        printf("%d ",n);
        while(n!=1){
            if(n%2==0){
                n=n/2;
            }
            else{
                n=3*n+1;
            }
            printf("%d  ",n);
        }
        printf("\nChild process has finished!\n");
    }
    else{
        printf("\nParent process is waiting for the child process to complete\n");
        wait(NULL);
        printf("\nParent process is done!!\n");
    }
}
