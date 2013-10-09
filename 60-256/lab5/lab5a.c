#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * purpose: to print the pid and ppid of a parent two children and then two children each of the two childrens
 * lab 52, 2013-02-27
 * Stephen Nusko, 102693282
 */
int main ()
{
	int pid = fork(), pid1, pid2, pid3, pid4, pid5;
	if (pid == -1)
	{
		printf("unable to fork");
	}
	else if (pid == 0)
	{
		pid4 = fork();
		if (pid4 == 0)
		{
			printf("pid child 1 = %d, ppid = %d\n", getpid(), getppid());
			exit(0);
		}
		else if (pid4 == -1)
		{
			printf("unable to fork\n");
		}
		else
		{
			pid5 = fork();
			if (pid5 == 0)
			{
				printf("pid child 2 = %d, ppid = %d\n", getpid(), getppid());
				exit(0);
			}
			else if (pid5 == -1)
			{
				printf("unable to fork\n");
			}
			else
			{
				wait();
				printf("original child 1 = %d, ppid = %d\n", getpid(), getppid());
				exit(0);
			}
		}
	}
	else
	{
		wait();
		pid1 = fork();
		if (pid1 == 0)
		{
			pid2 = fork();
			if (pid2 == 0)
			{
				printf("pid1 child 1 = %d, ppid = %d\n", getpid(), getppid());
				exit(0);
			}
			else if (pid2 == -1)
			{
				printf("unable to fork\n");
			}
			else
			{
				wait();
				pid3 = fork();
				if (pid3 == 0)
				{
					printf("pid1 child 2 = %d, ppid = %d\n", getpid(), getppid());
					exit(0);
				}
				else if (pid3 == -1)
				{
					printf("unable to fork\n");
				}
				else
				{
					wait();
					printf("original child 2 = %d, ppid = %d\n", getpid(), getppid());
					exit(0);
				}
			}
		}
		else if (pid1 == -1)
		{
			printf("unable to fork\n");
		}
		else
		{
			wait();
			printf("original pid = %d, ppid = %d\n", getpid(), getppid());
			exit(0);
		}
	}
	return 0;
}


