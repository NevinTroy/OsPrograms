#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>


#define PORT 8080
#define MAXLINE 1024

int main(){
    int sockfd;
    char buffer[MAXLINE];
    char *message="Hello from Client";
    struct sockaddr_in servaddr;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);

    memset(&servaddr,0,sizeof(servaddr));

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=INADDR_ANY;
    servaddr.sin_port=htons(PORT);

    int len,n;
    
    sendto(sockfd,(const char*)message,strlen(message),MSG_CONFIRM,(const struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("Hello message sent\n");

    n=recvfrom(sockfd,(char *)buffer,MAXLINE,MSG_WAITALL,(struct sockaddr*)&servaddr,&len);
    buffer[n]='\0';
    printf("Server says:%s\n",buffer);

    close(sockfd);

    return 0;
}