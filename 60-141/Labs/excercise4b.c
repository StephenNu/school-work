#include <stdio.h>								// Import required studios.
#define MAX 20									// Define MAX

void Swap(int*, int*);							// Swap will swap the two values of the inputted numbers. TripleArray will triple all the values currently stored in the array.
int Triple(int*);								// Triple will triple the inputed value at the pointer.	
void BubbleSort(int[], int size, int order);	// BubbleSort will sort the NumList, and the size in either ascending or descending order based on the input.
void printArray(int[], int numElements);		// printArray will display the array to the screen.
void PopulateArray(int[], int numElements);		// populateArray will set all the values of the array to even numbers starting at 4 and increasing by 2.
void TripleArray(int[], int numElements);		// TripleArray will triple all the values currently stored in the array.

int main()
{
	int NumList[MAX], input;
	int choice = 0;			// Variable to store the user's choice
	do 
	{
		// Display the menu choices to the user, and prompt for input.
		printf("\n1) use Populate the array with even numbers started from 4.\n");
		printf("2) use printArray to print the array to the screen.\n");
		printf("3) use Triple to triple all the values in the array.\n");
		printf("4) use bubblesort to sort the array into ascending or descending order.\n");
		printf("Please input the desired function's number, 0 if you no longer wish to continue\n");
		// Read user input.
		scanf("%d", &choice);
		// Check which number was inputted.
		switch (choice)
		{
		case 1:
		{
			// Call PopulateArray.
			PopulateArray(NumList, MAX);
			break;
		}
		case 2:
		{
			// Call printArray.
			printArray(NumList, MAX);
			break;
		}
		case 3:
		{
			// Call TripleArray.
			TripleArray(NumList, MAX);
			break;
		}
		case 4:
		{
			// Get the sort order and call bubblesort.
			int input;
			printf("Please input 1 for ascending order, and -1 for descending order.\n");
			scanf("%d", &input); 
			BubbleSort(NumList, MAX, input);
			break;
		}
		case 0: 
		{
			// Thank the user for testing the program since the while loop will end.
			printf("\nThank you for testing the programs :).\n\n");
			break;
		}
		default:
		{
			// Inform the user there was an incorrect input, and prompt for correct input.
			printf("Incorrect input. Please input a number between 1 and 16, or 0 if you wish to exit");
		}
		}
		// If the choice was 0 end the while loop.
	} while (choice != 0);
	// End the program.
	return 0;
}
/*
	Definition:
		printArray will display the array to the screen.
	Input:
		An array NumList, and the total amount of number of elements.
	Output:
		The array will be displayed to the screen.
*/
void printArray(int NumList[], int numElements)
{
	int k;								// Counter variable.
	int *pointer = NumList;				// Pointer to the start of the array.
	// While there are more entries continue.
	for (k = 0; k < numElements; k++)
	{
		printf("%d\t", *pointer);		// Print the current entry.
		pointer++;						// Move to the next entry.
	}
	printf("\n");
}
/*
	Definition:
		populateArray will set all the values of the array to even numbers starting at 4 and increasing by 2.
	Input:
		An array NumList, and the total amount of number of elements.
	Output:
		The array will be set to increasing even numbers starting at 4.
*/
void PopulateArray(int NumList[], int numElements)
{
	int k, counter = 4;					// Start variables.
	int *pointer = NumList;				// Set the pointer to the start of the array.
	// While there are more entries continue.
	for (k = 0; k < numElements; k++)
	{
		*pointer = counter;				// Set to the current value of counter.
		counter += 2;					// Increase counter to the next even number.
		pointer++;						// Move to the next entry.
	}
}
/*
	Definition:
		TripleArray will triple all the values currently stored in the array.
	Input:
		An array NumList, and the total amount of number of elements.
	Output:
		The array entries will all be tripled in value.
*/
void TripleArray(int NumList[], int numElements)
{
	int k;								// Counter variable.
	int *pointer = NumList;				// Set the pointer to the start of the array.
	// While there are more entries continue.
	for (k = 0; k < numElements; k++)
	{
		*pointer = Triple(pointer);		// Triple the value in the current entry.
		pointer++;						// Move to the next entry.
	}
}
/*
	Definition:
		Swap will swap the two values of the inputted numbers. 
	Input:
		Two int pointers to have their values swaped.	
	Output:
		The two values will be swaped.
*/
void Swap(int* a, int* b)
{
	int temp = *a;						// Variable to store the value at a.
	*a = *b;							// Set the value of a to the value at b
	*b = temp;							// Set the value of b to the number stored in temp.
}
/*
	Definition:
		Triple will triple the inputed value at the pointer.	
	Input:
		A int pointer to be tripled in value.
	Output:
		Will return the value inputted times by three.
*/
int Triple(int* a)
{
	return *a * 3;						// Return the value inputted timesed by three.
}
/*
	Definition:
		BubbleSort will sort the NumList, and the size in either ascending or descending order based on the input.
	Input:
		An array NumList, the size and the desired sortOrder.
	Output:
		The array will be sorted in the inputted order.
*/
void BubbleSort(int NumList[], int size, int sortOrder)
{
	int i, flag = 0;					// Start variables.
	int *pointer1 = NumList;			// Set the pointer to the start of the array.
	// If the sort order was acsending.
	if (sortOrder == 1)
	{
		while (flag != 1)				// While the array is unsorted.
		{
			flag = 1;					// Set the flag to sorted.
			// While there are more entries to compare continue.
			for (i = 0;  i < size-1; i++)
			{
				// if the current value is greated then the next value after the current swap the values.
				if (*(pointer1+i) > *(pointer1+i+1))
				{
					Swap((pointer1+i), (pointer1+i+1));
					flag = 0;			// Set the flag to unsorted.
				}
			}	
		}
	}
	// Otherwise if the sort order was descending.
	else if (sortOrder == -1)
	{
		while (flag != 1)				// While the array is unsorted.
		{
			flag = 1;					// Set the flag to sorted.
			// While there are more entries to compare continue.
			for (i = 0;  i < size-1; i++)
			{
				// if the current value is greated then the next value after the current swap the values.
				if (*(pointer1+i) < *(pointer1+i+1))
				{
					Swap((pointer1+i), (pointer1+i+1));
					flag = 0;			// Set the flag to unsorted.
				}
			}	
		}
	}
}
