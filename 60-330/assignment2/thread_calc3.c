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
#include <pthread.h>

// The 4 different pipes the threads will use to communicate.
int fd[8];
// Function definition of f as given in assignment.
double f(double a)
{
	return 4/(1+(a*a));	
}
	
// This function is called on each thread process to controll their execution.
void *thread_calc(void* in)
{
	int t = 0;
	int *start = (int*)in;
	// calculate the results for their slices 100,000 times.
	while (t < 100000)
	{
		double sum = 0.0, i;
		// if they are the final 8000 slices include f(1).
		if (*start +  8000 == 32000)
		{
			sum = f(1);
		}
		// calculate the remaining 8000 slices the process should do.
		for (i = (double)(*start); i <(double)(*start+8000.0); ++i)
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
		if (write(fd[((*start)/8000)*2 + 1], &sum, sizeof(double)) != sizeof(double))
		{
			perror("writing");
			pthread_exit(0);
		}
		++t;
	}
	// Kill the thread.
	pthread_exit(0);
}

int main()
{
	// store the 4 tids of the threads.
	pthread_t tid[4];
	int t;
	double sum;
	int k;
	int sections[4];
	// Create each pipe, and thread to receive it.
	for (k = 0; k < 4; ++k)
	{
		// error occured during pipe creation, end program.
		if (pipe(fd+k*2) < 0)
		{
			perror("opening pipe");
			exit(1);
		}
		// Set up sections to be passed to the thread
		sections[k] = k*8000;
		if (pthread_create(&tid[k], NULL, thread_calc, &sections[k]) != 0)
		{
			// Error occured during thread creation, end program.
			perror("pthread_create");
			exit(2);
		}
	}
	// Do the calculations 100,000 times.
	for (t = 0; t < 100000; t++)
	{
		sum = 0.0;
		double curr;
		// Read from the first thread.
		k = read(fd[0], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Read from the second thread.
		k = read(fd[2], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Read from the third thread.
		k = read(fd[4], &curr, sizeof(double));
		// Error occurred during read, end program.
		if (k < 0)
		{
			perror("reading error");
		}
		sum += curr;
		// Read from the fourth thread.
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
