#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
char server_name[] = "/tmp/server_nusko";
#define MAX 100
void remove_new_line(char *);
int main(){
	int fd1, fd2, fd, file, i = 0, check;
	unsigned long int fsize;
	char pid1[MAX], pid2[MAX];
	char filename[MAX], ch, confirm[MAX];

	if ((fd = open(server_name, O_WRONLY)) == -1){
		printf("There was an issue opening the fifo: %s\n", server_name);
		exit(1);
	}
	int pid = getpid();
	printf("%d\n", pid);
	if (write(fd, &pid, sizeof(int)) == -1)
	{
		perror("writing pid");
		exit(1);
	}

	sprintf(pid2, "/tmp/fifo_%d_2", pid);
	sprintf(pid1, "/tmp/fifo_%d_1", pid);

	printf("Please insert the name of a file in the current working directory: ");
	scanf("%s", filename);
	while ((file = open(filename, O_RDONLY)) == -1)
	{
		printf("Error: Could not open file specified. Try again\n");
		scanf("%s", filename);
	}
	fsize = lseek(file, 0, SEEK_END);
	lseek(file, 0, SEEK_SET);
	ch = filename[i++];
	sleep(2);
	if ((fd1 = open(pid1, O_RDONLY)) == -1)
	{
		perror("fifo 1");
		exit(2);
	}
	sleep(2);
	if ((fd2 = open(pid2, O_WRONLY)) == 1)
	{
		perror("fifo 2");
		exit(3);
	}
	while (ch != '\0' )
	{
		if (write(fd2, &ch, 1) == -1)
		{
			perror("writing file name");
			exit(1);
		}
		ch = filename[i++];
	}
	ch = '\n';
	if (write(fd2, &ch, 1) == -1)
	{
		perror("writing new line");
		exit(1);
	}
	if (write(fd2, &fsize, sizeof(unsigned long int)) == -1)
	{
		perror("writing size");
		exit(1);	
	}
	printf("%ld\n", fsize);
	i = 0;
	while(read(fd1, &ch, 1) == 1)
	{
		if (ch == '\n')
		{
			confirm[i] = '\0';
			break;
		}
		else
		{
			confirm[i++] = ch;
		}
	}
	if(strcmp(filename, confirm) == 0)
	{
		printf("Confirmation successful\n");
	}
	else
	{
		printf("Confirmation not successful!\n");
	}
	while ((check = read(file, &ch, 1)) == 1)
	{
		if (write(fd2, &ch, 1) == -1)
		{
            printf("%c\n", ch);
			perror("writing file error");
			exit(1);
		}
	}
	if (check == -1)
	{
		perror("reading file error");
		exit(2);
	}
	i = 0;
	while((check = read(fd1, &confirm[i++], 1)) == 1);
	if (check == -1)
	{
		perror("reading error");
		exit(12);
	}
	confirm[i] = '\0';
	if(strcmp("Upload complete", confirm) == 0){
		printf("Upload completed successfully\n");
        printf("Exiting Client\n");
	}
	else
	{
		printf("Upload did not complete successfully");
	}
	close(fd);
	close(fd1);
	close(fd2);
	close(file);
	exit(0);

}

void remove_new_line(char * str)
{
	char *t;
	for (t = str; *t != '\0'; t++);
	if (*(t-1) == '\n')
		*(t-1) = '\0';
}
