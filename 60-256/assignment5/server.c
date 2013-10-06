#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#define MAX 100
char server_user[] = "/tmp/server_nusko";

void handle_client(int);
int main()
{
	int fd, pid, client_pid;
	unlink(server_user);
	if (mkfifo(server_user, 0777) == -1)
	{
		perror("Main server fifo");
		exit(1);
	}
	if ((fd = open(server_user, O_RDONLY)) == -1)
	{
		perror("opening server file");
		exit(1);
	}
	while (1)
	{
        printf("------Awaiting Client Connections------\n");
		read(fd, &client_pid, sizeof(int));
		if ((pid = fork()) == -1)
		{
			perror("unable to fork");
		}
		else if (pid == 0)
		{
			handle_client(client_pid);
		}
		else
		{
			close(fd);
			if ((fd = open(server_user, O_RDONLY)) == -1)
			{
				perror("opening server file while");
				exit(1);
			}
		}
	}
	return 0;
}

void handle_client(int pid)
{
	char names[MAX], ch, final[] = "Upload complete";
	int fd1, fd2, newfd, i = 0, check;
	unsigned long int size;
	sprintf(names, "/tmp/fifo_%d_1", pid);
	unlink(names);
	if (mkfifo(names, 0777))
	{
		perror("FIFO first");
		exit(1);
	}
    printf("Creating: %s\n", names);
	if ((fd1 = open(names, O_WRONLY)) == -1)
	{
		perror("opening client write file");
		exit(2);
	}	
	sprintf(names, "/tmp/fifo_%d_2", pid);
	unlink(names);
	if (mkfifo(names, 0777))
	{
		perror("FIFO second");
		exit(1);
	}
    printf("Creating: %s\n", names);
    
	if ((fd2 = open(names, O_RDONLY)) == -1)
	{
		perror("opening client read file");
		exit(2);
	}
	while ((check = read(fd2, &ch, 1)) == 1)
	{
		if (ch == '\n')
			break;
		else
			names[i++] = ch;
	}
	if (check == -1)
	{
		perror("reading file name");
		exit(4);
	}
	names[i] = '\0';
	if ((check = read(fd2, &size, sizeof(unsigned long int))) == -1)
	{
		perror("reading size of file");
		exit(4);
	}
	if ((newfd = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1)
	{
		perror("error creating new file");
		exit(5);
	}
	i = 0;
	ch = names[i++];
	while (ch != '\0')
	{
		if (write(fd1, &ch, 1) != 1)
		{
			perror("writing name back");
			exit(4);
		}
		ch = names[i++];
	}
	ch = '\n';
	if (write(fd1, &ch, 1) != 1)
	{
		perror("writing new line");
		exit(6);
	}
	while (size > 0 && (check = read(fd2, &ch, 1)) == 1)
	{
		if (write(newfd, &ch, 1) != 1)
		{
			perror("writing file");
		}
		size--;
	}
	if (check == -1)
	{
		perror("reading file");
		exit(4);
	}
	if (write(fd1, final, sizeof(final)) != sizeof(final))
	{
		perror("writing \"Upload complete\"");
		exit(4);
	}
	close(fd1);
	close(fd2);
	close(newfd);
	exit(0);
}
