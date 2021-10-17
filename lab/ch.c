#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("The child process is doing this action\n");
		printf("My pid is %d\n",pid);
	}
}
