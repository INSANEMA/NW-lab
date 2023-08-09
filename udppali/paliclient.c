#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int client;
	char buff[1024];
	struct sockaddr_in servAddr;
	int servsize=sizeof(servAddr);
	client=socket(AF_INET,SOCK_DGRAM,0);
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(2002);
	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	printf("enter a number\n");
	gets(buff);
	sendto(client,buff,sizeof(buff),0,(struct sockaddr*)&servAddr,sizeof(servAddr));
	recvfrom(client,buff,sizeof(buff),0,(struct sockaddr*)&servAddr,&servsize);
	printf("the number is %s\n",buff);
	close(client);
}
