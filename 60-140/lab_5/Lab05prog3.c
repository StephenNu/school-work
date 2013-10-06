#include <stdio.h>

int main (void)
{

	int income = 0;
	float tax = 0.0; 
	scanf("%d", &income);
	switch (income)
	{
		case 200000:
		{
			tax = (float)income * 0.5; break;
		}
		case 150000:
		{
			tax =  (float)income * .36; break;
		}
		case 100000:
		{
			tax = (float)income * 0.30; break;
		}
		case 500000:
		{
			tax = (float)income * .20; break;
		}
		case 20000:
		{
			tax = (float)income * .10; break;
		}
		case 0:
		{
		 	tax = 0; break;
		}

	}	
	printf("The tax required is: %0.2f\n", tax);
	return 0;
}
