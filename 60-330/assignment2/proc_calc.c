/*
Student: Stephen Nusko
ID#: 103693282
Date: 17/02/2014
Homework#: 2
Class: 03-60-330 Operating systems
*/

// Libraries for c output, system calls, and exit function.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Function definition of f as given in assignment.
double f(double a)
{
	return 4/(1+(a*a));	
}
	
// This function is called on each child process to controll their execution.
void child_calc(int fd, int start)
{
	int t = 0;
	// calculate the results for their slices 100,000 times.
	while (t < 100000)
	{
		double sum = 0.0, i;
		// if they are the final 8000 slices include f(1).
		if (start +  8000 == 32000)
		{
			sum = f(1);
		}
		// calculate the remaining 8000 slices the process should do.
		for (i = (double)start; i <(double)(start+8000.0); ++i)
		{
			// if they are the first slice include f(0).
			if (i == 0)
			{
				sum = f(0);
			}
			// if currently on even iteration times by 2.
			else if ((int)i%2 == 0)
			{
				sum += 2.0*f(i/32000.0);
			}	
			// else if currently on odd iteration by 4.
			else
			{
				sum += 4.0*f(i/32000.0);
			}
		}
		// write the calculated double to the file descriptor.
		if (write(fd, &sum, sizeof(double)) != sizeof(double))
		{
			perror("writing");
			exit(1);
		}
		++t;
	}
	// Kill the child.
	exit(0);
}

int main()
{
	// store the 4 pids of the children.
	int pid[4];
	int t;
	double sum;
	// store the 4 pipes to communitcate with the children.
	int fd[8], k;
	// Create each pipe, and child to receive it.
	for (k = 0; k < 4; ++k)
	{
		// error occured during pipe creation, end program.
		if (pipe(fd+k*2) < 0)
		{
			perror("opening pipe");
			exit(1);
		}
		// If this is the child process.
		if ((pid[k] = fork()) == 0)
		{
			// close the read file descriptor.
			close(fd[0]);
			// launch management function for child, with correct pipe, and starting slice.
			child_calc(fd[2*k + 1], k*8000);
		}
		// Error occured during forking, end program.
		else if (pid[k] < 0)
		{
			perror("fork");
			exit(2);
		}
	}
	// Close all the write ends of the pipe in the parent.
	for (k = 1; k < 8; k += 2)
	{
		close(fd[k]);
	}
	// Do the calculations 100,000 times.
	for (t = 0; t < 100000; t++)
	{
		sum = 0.0;
		double curr;
		// Read from the first child.
		k = read(fd[0], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Read from the second child.
		k = read(fd[2], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Read from the third child.
		k = read(fd[4], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Read from the fourth child.
		k = read(fd[6], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Multiple the whole calculated equation.
		sum /= 3.0;
		sum *= 1.0/32000.0;
	}
	// Print the final results.
	printf("%lf\n", sum);
	return 0;
}
