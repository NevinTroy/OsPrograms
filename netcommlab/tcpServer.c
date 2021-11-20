#include <stdio.h>
#include <netdb.h>
#include<unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

int func(int sockfd)
{
	char buff[MAX];
	int n;
	int i;
	for(;;){
		bzero(buff,MAX);
		write(sockfd,"\tEnter the username",30);
		bzero(buff,MAX);
		read(sockfd,buff,sizeof(buff));
		if(strncmp(buff,"Nevin",5)==0){
			bzero(buff,MAX);
			write(sockfd,"\tEnter the password:",30);

			bzero(buff,MAX);
			read(sockfd,buff,sizeof(buff));
			if(strncmp(buff,"aezakmi",7)==0){
				bzero(buff,MAX);
				write(sockfd,"\tAuthenticated successfully",sizeof(buff));
				printf("Username and Password has been authenticated\n");
			}
			else{
				bzero(buff,MAX);
				write(sockfd,"Password is incorrect",30);
				return 1;
			}
				
		}else{
			bzero(buff,MAX);
			write(sockfd,"Username is incorrect",30);
			return 1;
		}

		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}
	}


}

int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));


	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);


	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(cli);

	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	func(connfd);

	close(sockfd);
}
