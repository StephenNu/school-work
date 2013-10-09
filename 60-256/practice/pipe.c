#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
long fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n* fact(n-1);
}
int fib(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return fib(n-1) + fib(n-2);
	}
}
void child(int fd[])
{
	char t;
	int i = 0;
	close(fd[1]);
	read(fd[0], &t, 1);
	i = atoi(&t);
	printf("%d\n", fib(i));

}
void parent(int fd[])
{
	char t[2];
	close(fd[0]);
        sprintf(t,"%d", 7);
	printf("%s\n",t);
	write(fd[1], t, 1);
}
int main()
{
	int pid, fd[2];
	if (pipe(fd) == -1)
	{
		perror("pipe opening");
		exit(1);
	}
	else
	{
		if ((pid = fork()) == 0)
		{
			child(fd);
			exit(0);
		}
		else
		{
			parent(fd);
			wait();
			exit(0);
		}
	}
	return 0;
}
