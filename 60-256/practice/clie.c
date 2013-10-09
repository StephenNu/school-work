#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
int main (int argc, char *argv[])
{
	char ch, name[100];
	int sd, ip, port;
	struct sockaddr_in serv;
	if (argc != 2)
	{
		exit(9);
	}
	sd = socket(AF_INET, SOCK_STREAM, 0);
	serv.sin_family = AF_INET;
	sscanf(argv[1], "%d", &ip);
	serv.sin_addr.s_addr = htonl((uint16_t)ip);
	sscanf(argv[2], "%d", &port);
	serv.sin_port = htonl((uint16_t)port);
	bind(sd, (struct sockaddr*)&serv, sizeof(serv));
	connect(sd,(struct sockaddr*)&serv, sizeof(serv));
	read(sd, &ch, 1);
	if (ch == '\0')
	{
		printf("please input the filename\n", name);
	}


	return 0;
}
