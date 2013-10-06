#include <stdio.h>

int main(void)
{
	float beanCost = 0.0, binCost1 = 0.0, binCost2 = 0.0, binCost3 = 0.0, subTotal = 0.0, tax = 0.0;
	int bin1Weight = 0, bin2Weight = 0, bin3Weight = 0, age = 0;
	
	printf("Please input the price per lbs\n");
	scanf("%f", &beanCost);
	printf("Please input the weight of bin 1\n");
	scanf("%d", &bin1Weight);
	printf("Please input the weight of bin 2\n");
	scanf("%d", &bin2Weight);
	printf("Please input the weight of bin 3\n");
	scanf("%d", &bin3Weight);
	printf("Please input the age of the customer\n");
	scanf("%d", &age);
	
	binCost1 += beanCost * (float)bin1Weight;
	binCost2 += beanCost * (float)bin2Weight;
	binCost3 += beanCost * (float)bin3Weight;

	subTotal = binCost1 + binCost2 + binCost3;
	if (age < 65)
	{
		tax = subTotal * 0.13;
	}

	printf("\n%d lbs Bin 1 @ %0.2f per lb ... \t$%0.2f\n", bin1Weight, beanCost, binCost1);
	printf("%d lbs Bin 1 @ %0.2f per lb ... \t$%0.2f\n", bin2Weight, beanCost, binCost2);
	printf("%d lbs Bin 1 @ %0.2f per lb ... \t$%0.2f\n", bin3Weight, beanCost, binCost3);
	printf("\tSubtotal\t\t$%0.2f\n",subTotal);
	printf("\tHST\t\t\t$%0.2f\n", tax);
	printf("\tTotal\t\t\t$%0.2f\n", subTotal+tax);
	return 0;
}

