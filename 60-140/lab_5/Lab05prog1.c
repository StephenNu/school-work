/*
40 per day
or 30 per day 12c per mile
*/
#include <stdio.h>

int main(void)
{
int days = 0, miles = 0;
float secondPlan = 0.0, firstPlan = 0.0;
float counterMiles = 0.0;
int counterDays = 0;
printf("Please input the number of days you wish to rent the car for\n");
scanf("%d", &days);
printf("Please input the miles you plan to drive the car while renting\n");
scanf("%d", &miles);
firstplan = 40.0 * days;
secondplan = (30.0 * days) + (0.15 * miles);
	if (firstPlan < secondPlan)
	{
		printf("first plan is better.\nFirst plan was %0.1f and second plan was %0.1f\n", firstPlan, secondPlan);
	}
	else
	{
		printf("second plan is better");
	}
}
