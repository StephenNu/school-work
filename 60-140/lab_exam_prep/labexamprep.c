#include <stdio.h>

void findProduct(int[], int[]);

int main(void)
{
	int i, array1[5], array2[5];
	for (i = 0; i < 5; i++)
	{
	printf("Please input the next array1 entry\n");
	scanf("%d", &array1[i]);
	printf("Please input the next array2 entry\n");
	scanf("%d", &array2[i]);
	}
	findProduct(array1, array2);
	return 0;
}

void findProduct(int array1[], int array2[])
{
	int result[5], i;
	printf("array1\tarray2\tproduct_array\n");
	for (i = 0; i < 5; i++)
	{
		result[i] = array1[i] * array2[i];
		printf("%d\t%d\t%d\n", array1[i], array2[i], result[i]);
	}
}