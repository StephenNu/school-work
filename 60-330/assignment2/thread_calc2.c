/*
Student: Stephen Nusko
ID#: 103693282
Date: 17/01/2014
Homework#: 2
Class: 03-60-330 Operating systems
*/

// Libraries for c output, system calls, and exit function.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


double results[4];
pthread_cond_t cond[4];
pthread_mutex_t mutex[4];
// Function definition of f as given in assignment.
double f(double a)
{
	return 4/(1+(a*a));	
}
	
// This function is called on each child process to controll their execution.
void* thread_calc(void* in)
{
	int* start = (int*)(in);
	int t = 0;
	// calculate the results for their slices 100,000 times.a

	pthread_mutex_lock(&mutex[(*start)/8000]);
	while (t < 100000)
	{
		//printf("got the %dth mutex\n", (*start)/8000);
		double sum = 0.0, i;
		// if they are the final 8000 slices include f(1).
		if (*start +  8000 == 32000)
		{
			sum = f(1);
		}
		// calculate the remaining 8000 slices the process should do.
		for (i = (double)*start; i <(double)(*start+8000.0); ++i)
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
		//if (write(fd, &sum, sizeof(double)) != sizeof(double))
		//{
		//	perror("writing");
		//	exit(1);
		//}
		++t;
		results[(*start)/8000] = sum;
		//printf("doing calculation in thread %d\n", (*start)/8000);
		pthread_cond_signal(&cond[(*start)/8000]);
		pthread_cond_wait(&cond[(*start)/8000], &mutex[(*start)/8000]);
	}
	// Kill the child.
	pthread_exit(0);
}

int main()
{
	// store the 4 pids of the children.
	pthread_t tid[4];
	//bool running[4];
	int t;
	double sum;
	//double results[4];
	// store the 4 pipes to communitcate with the children.
	int sections[4], k;
	// Create each pipe, and child to receive it.
	for (k = 0; k < 4; ++k)
	{
		pthread_cond_init(&cond[k], NULL);
		pthread_mutex_init(&mutex[k], NULL);
		pthread_mutex_lock(&mutex[k]);
		// error occured during pipe creation, end program.
	//	if (pipe(fd+k*2) < 0)
	//	{
	//		perror("opening pipe");
	//		exit(1);
	//	}
		// If this is the child process.
		sections[k] = k*8000;
		if (pthread_create(&tid[k], NULL, thread_calc, &sections[k]) != 0)
		{
			// close the read file descriptor.
	//		close(fd[0]);
			// launch management function for child, with correct pipe, and starting slice.
	//		child_calc(fd[2*k + 1], k*8000);
			perror("pthread_create");
			exit(2);
		}
	}
	// Close all the write ends of the pipe in the parent.
	//for (k = 1; k < 8; k += 2)
	//{
	//	close(fd[k]);
	//}
	// Do the calculations 100,000 times.
	for (t = 0; t < 100000; t++)
	{
		// error occured during pipe creation, end program.
	//	if (pipe(fd+k*2) < 0)
	//	{
	//		perror("opening pipe");
	//		exit(1);
	//	}
		// If this is the child process.
		sum = 0.0;
		/*// Read from the first child.
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
		sum *= 1.0/32000.0;*/
		for (k = 0; k < 4; k++)
		{
			//printf("releasing the %dth lock\n", k);
			pthread_cond_wait(&cond[k], &mutex[k]);
			sum += results[k];
			pthread_cond_signal(&cond[k]);
		}	
		sum /= 3.0;
		sum *= 1.0/32000.0;
	}
	// Print the final results.
	printf("%lf\n", sum);
	return 0;
}
