#include <stdio.h>

int main(void)
{
	int qty, item, itemCount = 0;
	float price, totalPrice;
	printf("Enter item code\n");
	scanf("%d", &item);
	while (item != -1)
	{
		printf("Enter qty and price\n");
		scanf("%d %f", &qty, &price);
		printf("Item: %d Price %0.2f\n", item, qty*price);
		itemCount++;
		printf("Enter item code\n");
		scanf("%d", &item);
		totalPrice += qty*price;
	}
	printf("Number of Items: %d Total Sales income %0.2f\n\n", itemCount, totalPrice);
	return 0;
}


