#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#define MAX 500
int checkPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int fd1, fd2, i = 0, pid, prime;
	
	unlink("./tmp/nuskos");
	if (mkfifo("./tmp/nuskos", 0777)) {
		perror("fifo");
		exit(1);
	}
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		if ((pid = fork()) == 0)
		{
			int b;
			fd2 = open("./tmp/nuskos", O_RDONLY);
			read(fd2, &b, sizeof(int));
			if (checkPrime(b))
			{
				fprintf(stderr, "\nchild: %d is a prime number\n", b);
			}
			else
			{
				fprintf(stderr, "\nchild: %d is not a prime number\n", b);
			}
			close(fd2);
			exit(0);
		}
		else if (pid == -1)
		{
			perror("unable to fork");
		}
		else
		{
			prime = rand() % 100;
			fd1 = open("./tmp/nuskos", O_WRONLY);
			fprintf(stderr, "Parent: Is %d a prime number?\n", prime);
			write(fd1, &prime, sizeof(int));
			close(fd1);
			wait();
		}
	}
	return 0;
}
