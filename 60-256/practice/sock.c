#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
void doClient(int fd);
int main(int argc, char *argv[])
{
	int sd, portnum;
	struct sockaddr_in serv;
	if (argc == 0)
	{
		exit(9);
	}
	sd = socket(AF_INET , SOCK_STREAM, 0);
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	sscanf(argv[1], "%d", &portnum);
	serv.sin_port = htonl((uint16_t)portnum);
	bind(sd, (struct sockaddr*)&serv, sizeof(serv));
	listen(sd, 10);

	while (1)
	{
		doClient(accept(sd,(struct sockaddr*) NULL, NULL));
	}
}

void doClient(int fd)
{
	char name[100], end='\0', com[100];
	int backup, i=0;
	backup = dup(1);
	dup2(fd, 1);
	system("ls");
	write(fd, &end, 1);
	do {
		read(fd, &name[i++], 1);
	} while (name[i-1] != '\0');
	sprintf(com, "cat %s", name);
	system(com);
	write(fd, &end, 1);
	close(fd);
	dup2(backup, 1);
}
