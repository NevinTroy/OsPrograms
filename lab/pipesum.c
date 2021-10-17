#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
    int fd[2];
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int arrsize=sizeof(arr)/sizeof(int);
    int start,end,i,sum=0;
    if(pipe(fd)==-1){
        printf("There is some error with pipe\n");
        return 1;
    }
    int id=fork();
    if(id==0){
        start=0;
        end=arrsize/2;
    }
    else{
        start=arrsize/2;
        end=arrsize;
    }
    for(i=start;i<end;i++){
        sum+=arr[i];
    }
    wait(NULL);
    printf("Calculated partial sum is: %d\n",sum);
    if(id==0){
        write(fd[1],&sum,sizeof(sum));
        close(fd[0]);
        close(fd[1]);
    }
    else{
        int sumFromChild;
        read(fd[0],&sumFromChild,sizeof(sumFromChild));
        sum+=sumFromChild;
        write(fd[1],&sum,sizeof(sum));
        close(fd[0]);
        close(fd[1]);
        printf("The total sum is: %d \n",sum);
    }
    return 0; 
}
