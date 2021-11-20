#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int welcomeSocket, newSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;

  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  welcomeSocket = socket(PF_INET, SOCK_DGRAM, 0);
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  
  bind(welcomeSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));


 if(listen(welcomeSocket,5)==0)
   printf("Listening\n");
 else
 printf("Error\n");

  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr*)&serverStorage, &addr_size);

  strcpy(buffer,"Hello World\n");
  send(newSocket,buffer,13,0);

  /* Copied this from Geek For Geeks lol... pretty much just adding sendto and recvfrom functions*/
    char *msg = "Hello From Server";
    int len = sizeof(serverAddr);
    int n = recvfrom(welcomeSocket,(char *)buffer,1024,MSG_WAITALL,(struct sockaddr *) &serverAddr, &len);
    buffer[n]='\0';
    printf("Client : %s\n",buffer);
    sendto(welcomeSocket, (const char *)msg,strlen(msg),0, (const struct sockaddr *)&serverAddr, len);
    printf("Hello message sent.\n");
  return 0;
}