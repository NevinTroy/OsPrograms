#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int x=0;
void handle_sigusr1(int sig){
	if(x==0){
		printf("(Hint) Repetitive addition\n");
	}
}

int main(int argc,char* argv[]){
	int pid=fork();

	if(pid==0){
		sleep(5);
		kill(getppid(),SIGUSR1);		
	}
	else{

		struct sigaction sa;
		sa.sa_flags=SA_RESTART;
		sa.sa_handler=&handle_sigusr1;
		sigaction(SIGUSR1,&sa,NULL);

		printf("What is 5*3 :");
		scanf("%d",&x);
		if(x==15){
			printf("Right Answer!\n");
		}
		else{
			printf("wrong answer\n");
		}

		wait(NULL);
	}

	return 0;
}