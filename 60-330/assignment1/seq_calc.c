/*
Student: Stephen Nusko
ID#: 103693282
Date: 22/01/2014
Homework#: 1
Class: 03-60-330 Operating systems
*/

// Libraries for c output.
#include <stdio.h>

// Function definition of f as given in assignment.
double f(double a)
{
	return 4/(1+(a*a));	
}


int main()
{
	// counter variables, plus one to sum all results.
	double i, j;
	double sum;
	// Loop 100,000 times to showcase time required.
	for (j = 0; j < 100000; ++j)
	{
		// function at 0.
		sum = f(0);
		for (i = 1; i < 32000; ++i)
		{
			// if it is even slice times by 2 otherwise times by 4.
			if ((int)i%2 == 0)
				sum += 2*f(i/32000);
			else
			{
				sum += 4*f(i/32000);
			}

		}
		// function at 1.
		sum += f(1);
		// multiple the entire bracket by the following.
		sum /= 3;
		sum *= 1.0/32000.0;
	}
	// print final result.
	printf("%lf\n", sum);
	return 0;
}
