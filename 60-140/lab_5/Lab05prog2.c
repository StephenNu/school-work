#include <stdio.h>

int main (void)
{

	float income = 0.0, tax = 0.0;
	scanf("%f", &income);

	if (income > 199999.99)
	{
		tax = income * 0.5;
	}
	else if (income > 149999.00)
	{
		tax =  income * .36;
	}
	else if (income > 99999.99)
	{
		tax = income * 0.30;
	}
	else if (income > 49999.99)
	{
		tax = income * .20;
	}
	else if (income > 19999.99)
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
