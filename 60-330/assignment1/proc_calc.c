#include <stdio.h>
#include <math.h>

double f(double a)
{
	return 4/(1+pow(a,2));	
}

int main()
{
	double i, j;
	double sum = 0.0;
	
	
	/*
	sum = f(0);
	for (i = 1; i < 32000; ++i)
	{
		if ((int)i%2 == 0)
			sum += 2*f(i/32000);
		else
		{
			sum += 4*f(i/32000);
		}
	}
	sum += f(1);
	*/
	sum /= 3;
	sum *= 1.0/32000.0;
	printf("%lf\n", sum);
	return 0;
}
