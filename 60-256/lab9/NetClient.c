#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sockfd = 0, n = 0, i;
	char recvBuff[1024];
	struct sockaddr_in serv_addr;

	if(argc != 2)
	{
		printf("\n Usage: %s <ip of server> \n", argv[0]);
		printf(" (Use loop back address: 127.0.0.1)\n");
		return 1;
	}

	/*initialize all bits of "recvBuff" to 0*/
	memset(recvBuff, '0',sizeof(recvBuff));

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("creating socket");
		exit(1);
	}

	/*initialize all bits of "serv_addr" to 0*/
	memset(&serv_addr, '0', sizeof(serv_addr));

	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(7777);
	inet_aton(argv[1], (struct in_addr *)&serv_addr.sin_addr.s_addr);
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("connecting");
		exit(1);
	}
	if ((n = read(sockfd, recvBuff, strlen(recvBuff))) == -1)
	{
		perror("writing");
		exit(3);
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", recvBuff[i]);
	}
	return 0;
}
