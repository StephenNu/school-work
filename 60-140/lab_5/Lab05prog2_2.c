#include <stdio.h>

int main (void)
{

	float income = 0.0, tax = 0.0;
	scanf("%f", &income);

	if (income >= 200000)
	{
		tax = income * 0.5;
	}
	else if (income >= 150000)
	{
		tax =  income * .36;
	}
	else if (income >= 100000)
	{
		tax = income * 0.30;
	}
	else if (income >= 50000)
	{
		tax = income * .20;
	}
	else if (income >= 20000)
	{
		tax = income * .10;
	}
	else
	{
	 	tax = 0;
	}

	printf("The tax required is: %0.2f\n", tax);
	return 0;
}
