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
	client=socket(AF_INET,SOCK_STREAM,0);
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(6265);
	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	connect(client,(struct sockaddr*)&servAddr,sizeof(servAddr));
	while(1)
	{
	printf("enter the data to sent to client\n");
	gets(buff);
	send(client,buff,sizeof(buff),0);
	recv(client,buff,sizeof(buff),0);
	printf("data recieved from server:%s",buff);
	memset(buff,0,sizeof(buff));
	}
	close(client);
}
