#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	int pid=fork();
	if(pid>0){
		printf("This is the parent process: %d\n",getpid());
		exit(0);
	}
	else{
		sleep(10);
		printf("This is the orphaned child process running in the background: %d\n",getpid());
		exit(1);
	}
	return 0;
}
