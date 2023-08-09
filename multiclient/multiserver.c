#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main()
{
	int server,client1,client2;
	struct sockaddr_in servAddr;
	struct sockaddr_storage store1,store2;
	int c1size=sizeof(store1);
	int c2size=sizeof(store2);
	char buff1[1024],buff2[1024];
	server=socket(AF_INET,SOCK_STREAM,0);
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(6265);
	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(server,(struct sockaddr*)&servAddr,sizeof(servAddr));
	if(listen(server,5)==0)
		printf("listening...\n");
	client1=accept(server,(struct sockaddr*)&store1,&c1size);
	client2=accept(server,(struct sockaddr*)&store2,&c2size);
	while(1)
	{
		recv(client1,buff1,sizeof(buff1),0);
		recv(client2,buff2,sizeof(buff2),0);
		printf("MESSAGE FROM CLIENT1 :%s\n",buff1);
		printf("MESSAGE FROM CLIENT :%s\n",buff2);
		gets(buff1);
		send(client1,buff1,sizeof(buff1),0);
		gets(buff2);
		send(client2,buff2,sizeof(buff2),0);
		memset(buff2,0,sizeof(buff2));
		memset(buff1,0,sizeof(buff1));
	}
	close(server);
	close(client1);
	close(client2);
}
