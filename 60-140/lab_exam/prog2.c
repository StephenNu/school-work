#include <stdio.h>

void findBigger(int[], int[]);
void fillTwoArrays(int[], int[], int);

int main(void)
{
	int size = 5, array1[size], array2[size];
	fillTwoArrays(array1, array2, size);
	findBigger(array1, array2);
	return 0;
}

void fillTwoArrays(int array1[], int array2[], int size)
{	
	int i;
	for (i = 0; i < size; i++)
	{
	printf("Please input the next array1 entry\n");
	scanf("%d", &array1[i]);
	printf("Please input the next array2 entry\n");
	scanf("%d", &array2[i]);
	}
}

void findBigger(int array1[], int array2[])
{
	int result[5], i;
	printf("array1\tarray2  |\tBigger\n");
	printf("________________|_______________________\n");
	for (i = 0; i < 5; i++)
	{
		if (array1[i] < array2[i])
		{
			result[i] = array2[i];
		}
		else
		{
			result[i] = array1[i];
		}
		printf("%d\t%d \t|\t%d\n", array1[i], array2[i], result[i]);
	}
}
