#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int server;
	char buff[1024];
	struct sockaddr_in servAddr;
	struct sockaddr_storage store;
	int clientsize=sizeof(store);
	server=socket(AF_INET,SOCK_DGRAM,0);
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(2002);
	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(server,(struct sockaddr*)&servAddr,sizeof(servAddr));
	recvfrom(server,buff,sizeof(buff),0,(struct sockaddr*)&store,&clientsize);
	printf("number recied is %s",buff);
	int n=atoi(buff);
	int flag=0;
	for(int i=2;i<=n/2;i++)
	{if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{	
		strcpy(buff,"prime");
		sendto(server,buff,sizeof(buff),0,(struct sockaddr*)&store,clientsize);
	}
	else	
	{
		strcpy(buff,"not prime");
		sendto(server,buff,sizeof(buff),0,(struct sockaddr*)&store,clientsize);
	}
	close(server);
}	
