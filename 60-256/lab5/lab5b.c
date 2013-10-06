#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
/*
 * purpose: to use a child process to read and output a file opened by the parent.
 * lab 52 2013-02-27
 * Stephen Nusko, 103693282
 */
int main(int argc, char* argv[])
{
	int fp = open("file.txt", O_RDONLY);
	if (fp == -1)
	{
		perror("file opening problem"); exit(1);
	}
	else
	{
	int pid = fork();
	if (pid == -1)
	{
		printf("unable to fork.\n");
	}
	else if (pid == 0)
	{
		char t;
		long int check;
		while (check = read(fp, &t, 1) > 0)
		{
			if (write(1, &t, 1) != 1)
			{
				perror("writing error"); exit(3);
			}
		}
		if (check == -1)
		{
			perror("reading problem"); exit(2);
		}
		exit(20);
	}
	else
	{
		int status;
		wait(&status);
		printf("My child has terminated its life %d\n", WEXITSTATUS(status));
	}
	}
	return 0;
}
