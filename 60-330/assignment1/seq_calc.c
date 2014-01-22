#include <stdio.h>
#include <math.h>

double f(double a)
{
	return 4/(1+(a*a));	
}

int main()
{
	double i, j;
	double sum;
	for (j = 0; j < 100000; ++j)
	{
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
		sum /= 3;
		sum *= 1.0/32000.0;
	}
	printf("%lf\n", sum);
	return 0;
}
