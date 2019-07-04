#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 6000
#define NET_ADDR "127.0.0.1"

void send_data(int);

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(sockfd != -1);

	struct sockaddr_in saddr;
	memset(&saddr, 0, sizeof(saddr));
	
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(PORT);
	saddr.sin_addr.s_addr = inet_addr(NET_ADDR);

	int ret = connect(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));
	assert(ret != -1);

	send_data(sockfd);

	close(sockfd);

	return 0;
}

void send_data(int sockfd)
{
	char buff[1024] = {0};
	printf("Input the path of the file which you want to transport:\n");
	scanf("%s", buff);
	FILE *source = fopen(buff, "rb+");
	memset(buff, 0, 1024);

	while(1)
	{
		if( fread(buff, 1024, 1, source) == 0 )
		{
			break;
		}
		send(sockfd, buff, sizeof(buff), 0);
		memset(buff, 0, 1024);
	}
	fclose(source);
}
