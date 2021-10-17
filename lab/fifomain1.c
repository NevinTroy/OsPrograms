#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

int main(int argc,char* argv[]){

    int i,arr[5];
    srand(time(NULL));
    for(i=0;i<5;i++){
        arr[i]=rand()%100;
    }
    
    int fd=open("fifoarr",O_WRONLY);
    if(fd==-1){
        return 1;
    }

    for(i=0;i<5;i++){
        if(write(fd,&arr[i],sizeof(int))==-1){
            return 2;
        }
        printf("Wrote %d\n",arr[i]);
    }

    close(fd);
    return 0;
}
