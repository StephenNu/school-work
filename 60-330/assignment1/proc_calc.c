#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
double f(double a)
{
	return 4/(1+(a*a));	
}
		
void child_calc(int fd, int start)
{
	int t = 0;
	while (t < 100000)
	{
		double sum = 0.0, i;
		if (start == 0)
		{
			sum = f(0);
		}
		else if (start +  8000 == 32000)
		{
			sum = f(1);
		}
		for (i = (double)start; i <(double)(start+8000.0); ++i)
		{
			if (i == 0)
			{
				continue;
			}
			else if ((int)i%2 == 0)
			{
				sum += 2.0*f(i/32000.0);
			}	
			else
			{
				sum += 4.0*f(i/32000.0);
			}
		}
		if (write(fd, &sum, sizeof(double)) != sizeof(double))
		{
			perror("writing");
			exit(1);
		}
		++t;
	}
	exit(0);
}

int main()
{
	int pid[4];
	int t;
	double sum;
	int fd[8], k;
	for (k = 0; k < 4; ++k)
	{
		if (pipe(fd+k*2) < 0)
		{
			perror("opening pipe");
			exit(1);
		}
		if ((pid[k] = fork()) == 0)
		{
			close(fd[0]);
			child_calc(fd[2*k + 1], k*8000);
		}
		else if (pid[k] < 0)
		{
			perror("fork");
			exit(2);
		}
	}
	for (k = 1; k < 8; k += 2)
	{
		close(fd[k]);
	}
	for (t = 0; t < 100000; t++)
	{
		sum = 0.0;
		double curr;
		k = read(fd[0], &curr, sizeof(double));
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		k = read(fd[2], &curr, sizeof(double));
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		k = read(fd[4], &curr, sizeof(double));
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		k = read(fd[6], &curr, sizeof(double));
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		sum /= 3.0;
		sum *= 1.0/32000.0;
	}
	printf("%lf\n", sum);
	return 0;
}
