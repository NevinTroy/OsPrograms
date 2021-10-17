#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc,char* argv[]){
    if(mkfifo("myfifo1",0777) ==-1){
            printf("Couldnt create file\n");
            return 1;
    }
    printf("Opening\n");
    int fd=open("myfifo1",O_WRONLY);
    if(fd==-1){
        return 2;
    }
    printf("Opened\n");
    int x=97;
    if( write(fd, &x,sizeof(x)) ==-1){
        return 3;
    }
    printf("Written\n");

    return 0;
}