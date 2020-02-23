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

int recv_data(int);

int main()
{
		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		assert(sockfd != 1);

		struct sockaddr_in saddr;
		memset(&saddr, 0, sizeof(saddr));

		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(PORT);
		saddr.sin_addr.s_addr = inet_addr(NET_ADDR);

		int ret = bind(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));
		assert(ret != -1);

		listen(sockfd, 5);

		int val = recv_data(sockfd);
		close(val);

		return 0;
}

int recv_data(int sockfd)
{
		struct sockaddr_in caddr;
		int len = sizeof(caddr);

		char buff[1024] = {0};
		int c = -1;
		while(c < 0)
				c = accept(sockfd, (struct sockaddr*)&caddr, &len);

		printf("You are ready to receive a file, Input it's name:\n");
		scanf("%s", buff);
		FILE *target = fopen(buff, "wb+");
		memset(buff, 0, 1024);

		int res = 0;
		while(1)
		{
				res = recv(c, buff, sizeof(buff), 0);
				if( res <= 0)
				{
						break;
				}

				fwrite(buff, res, 1, target);
				memset(buff, 0, 1024);
		}
		fclose(target);

		return c;
}
