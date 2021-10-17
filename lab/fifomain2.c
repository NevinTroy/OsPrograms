#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

int main(int argc,char* argv[]){

    int i,arr[5];
    
    int fd=open("fifoarr",O_RDONLY);
    if(fd==-1){
        return 1;
    }

    for(i=0;i<5;i++){
        if(read(fd,&arr[i],sizeof(int))==-1){
            return 2;
        }
        printf("Read %d\n",arr[i]);
    }

    close(fd);
    return 0;
}
