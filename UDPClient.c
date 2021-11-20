#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
/* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  recv(clientSocket, buffer, 1024, 0);


  printf("Data received: %s",buffer);

    char *msg = "Hello From Client";
    int len = sizeof(serverAddr);
    sendto(clientSocket, (const char *)msg,strlen(msg),MSG_CONFIRM, (const struct sockaddr *)&serverAddr, len);
    printf("Hello message sent.\n");  
    
    int n = recvfrom(clientSocket,(char *)buffer,1024,0,(struct sockaddr *) &serverAddr, &len);
    buffer[n]='\0';
    printf("Server : %s\n",buffer);
    return 0;
}