#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>

int main(){
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    char *filename="/tmp/file";
    fd=creat(filename,mode);

    fd=open("/tmp/file",O_RDWR,0);

    char b[100]="The brown lazy fox jumps over the lazy dog";
    size_t nb=strlen(b);
    ssize_t bytesWritten=write(fd,b,nb);

    return 0;
}
