#include <stdlib.h>
#include <stdio.h>
/*
 * purpose: to print the pid and ppid of a parent two children and then two children each of the two childrens
 * lab 52, 2013-02-27
 * Stephen Nusko, 102693282
 */
int main (int argc, char* argv[])
{
	int i;
	for (i = 0; i < 2; i++)
	{
		int pid = fork();
		if (pid == -1)
		{
			printf("unable to fork\n");
		}
		else if (pid == 0)
		{
			int k;
			printf("child %d, pid = %d, ppid = %d\n", i+1, getpid(), getppid());
			for (k = 0; k < 2; k++)
			{
				int pid1 = fork();
				if (pid == -1)
				{
					printf("unable to fork.\n");
				}
				else if (pid == 0)
				{
					printf("grandchild %d of child %d pid = %d ppid = %d.\n",
						       	k+1, i+1, getpid(), getppid());
					exit(0);
				}
				else
				{
					wait();
				}
			}
			exit(0);
		}
		else
		{
			wait();
		}
	}
	wait();
	printf("parent pid = %d, ppid = %d\n", getpid(), getppid());
	return 0;
}
