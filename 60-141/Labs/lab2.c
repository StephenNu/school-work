/* 
	Nusko, Stephen
	ID: 103693282
	Lab Exercise # 3
	Date: Jan 31th 1012
	Purpose: Create a program that showcases a bunch of functions that operate on a two dimensional array of size M, and N. Including setting the entries to either all 0s or random values between 1 and 100,
	or sorting, printing the array, as well as searching if a certain number is in the array or shifting each entry one to the left.
*/
#define M 10	// column
#define N 5		// row

#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void intiArray(int data[][N], int col, int row);				// intiArray sets all entries in the array to 0.
void printArray(int data[][N], int col, int row);				// printArray prints out the all entries in the array to the screen.
void randArray(int data[][N], int col, int row);				// randArray sets all entries in the array to a random value between 1 and 100.
void bubblesort(int data[][N], int col, int row);				// bubblesort takes the inputed 2D array and sorts it into ascending order from left to right top down.
int linearFind(int data[][N], int col, int row, int key);		// linearFind will check if any number in the array is equal to the inputted key.
void leftShift(int data[][N], int col, int row);				// leftShift will take all entries in the inputted array and shift each entries one to the left.

/* Main Program Routine */
int main(void)
{
	int data[M][N];
	int choice = 0;			// Variable to store the user's choice
	do 
	{
		// Display the menu choices to the user, and prompt for input.
		printf("\n1) use intiArray to set the array entries to all 0s.\n");
		printf("2) use printArray to print the array to the screen.\n");
		printf("3) use randArray to fill the array entries with random values between 1, and 100.\n");
		printf("4) use bubblesort to sort the array into ascending order from left to right top to bottom.\n");
		printf("5) use linearFind to return 1 if the number is found otherwise 0.\n");
		printf("6) use leftShift to shift all entries one spot to the left.\n");
		printf("Please input the desired function's number, 0 if you no longer wish to continue\n");
		// Read user input.
		scanf("%d", &choice);
		// Check which number was inputted.
		switch (choice)
		{
		case 1:
		{
			// Call intiArray.
			intiArray(data, M, N);
			break;
		}
		case 2:
		{
			// Call printArray.
			printArray(data, M, N);
			break;
		}
		case 3:
		{
			// Call randArray.
			randArray(data, M, N);
			break;
		}
		case 4:
		{
			// Call bubblesort.
			bubblesort(data, M, N);
			break;
		}
		case 5:
		{
			// Gather the required information and call linearFind, and print the results.
			int key;
			printf("Please input the number to check if it is inside the array\n");
			scanf("%d", &key);
			if (linearFind(data, M, N, key))
			{
				printf("%d was found in the array\n", key);
			}
			else
			{
				printf("%d was not found in the array\n", key);
			}
			break;
		}
		case 6:
		{
			// Call leftShift.
			leftShift(data, M, N);
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
	definition
		intiArray sets all entries in the array to 0.
	input
		An array of size [col][row].
	output
		All entries within the array of size [col][row] will be set to zero.
*/
void intiArray(int data[][N], int col, int row)
{
	int i, j;					// Counter variables.
	// While there are more entries to visit continue.
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < col; i++)
		{
			// Set the current entry to 0.
			data[i][j] = 0;
		}
	}
}

/*
	definition
		printArray prints out the all entries in the array to the screen.
	input
		An array of size [col][row].
	output
		The current state of the array will be printed out to the screen.
*/
void printArray(int data[][N], int col, int row)
{
	int i, j;					// Counter variables.
	// Line breaks for spacing.
	printf("\n\n");
	// While there are more entries to be visited continue.
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < col; i++)
		{
			// Print out the current entry.
			printf("%d\t", data[i][j]);
		}
		// Line break for spacing.
		printf("\n");
	}
	// Line break for spacing.
	printf("\n");
}

/*
	definition
		randArray sets all entries in the array to a random value between 1 and 100.
	input
		An array of size [col][row].
	output
		All entries within the array of size [col][row] will be set to a random value between 1 and 100.
*/
void randArray(int data[][N], int col, int row)
{
	int i, j;					// Counter variables.
	// While there are more entries to be visited continue.
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < col; i++)
		{
			// Set the current entry to a random number between 1 and 100.
			data[i][j] = rand() % 100 + 1;
		}
	}
}

/*
	definition
		bubblesort takes the inputed 2D array and sorts it into ascending order from left to right top down.
	input
		An array of size [col][row].
	output
		All entries within the array of size [col][row] will be set to ascending order.
*/
void bubblesort(int data[][N], int col, int row)
{
	int flag = 0, i, j, temp;		// Counter variables, flag and temp holder.

	// While the flag is not true, continue sorting the array.
	while (flag != 1)
	{
		flag = 1;					// Start the loop assuming a sorted array.
		// While there are more rows left to do continue sorting the arrays.
		for (j = 0; j < row; j++)
		{
			// Check if its not the first row, and if the last entry in the previous row is greater then first in the new row, swap the two.
			if (j != 0 && temp > data[0][j])
			{
				data[M-1][j-1] = data[0][j];
				data[0][j] = temp;
			}
			// While there are more columns in the row to check continue.
			for (i = 0; i < col-1; i++)
			{
				// Compare the curent entry with the next, and see if its bigger, if true swap the two, and set the sorted flag to 0.
				if (data[i][j] > data[i+1][j])
				{
					temp = data[i][j];
					data[i][j] = data[i+1][j];
					data[i+1][j] = temp;
					flag = 0;
				}
			}
			// Set temp to the last entry in the current row.
			temp = data[i][j];
		}
	}
}

/*
	definition
		linearFind will check if any number in the array is equal to the inputted key.
	input
		An array of size [col][row], and the number key to be checked if its in the array.
	output
		The function will return a 1 if the number was matched and 0 if the number wasn't in the array.
*/
int linearFind(int data[][N], int col, int row, int key)
{
	int i, j;						// Counter variables.
	// While there are more entries to visit continue.
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < col; i++)
		{
			// If the current entry is equal to the inputted key return 1.
			if (data[i][j] == key)
			{
				return 1;		
			}
		}
	}
	// If the key was never matched return 0.
	return 0;
}

/*
	definition
		leftShift will take all entries in the inputted array and shift each entries one to the left.
	input
		An array of size [col][row].
	output
		All entries within the array of size [col][row] will be shifted one entry to the left.
*/
void leftShift(int data[][N], int col, int row)
{
	int i, j, temp;		// Counter variables, and temp data.
	// Store the first entry.
	temp = data[0][0];
	// While there are more entries to visit continue.
	for (j = 0; j < row; j++)
	{
		// While there are move columns up to columns - 1 continue.
		for (i = 0; i < col-1; i++)
		{
			// Shift the entry over to the left by one.
			data[i][j] = data[i+1][j];
		}
		// If the current row is the last row.
		if (j == row-1)
		{
			// swap the last entry with the temp variable.
			data[col-1][row-1] = temp;
		}
		// Otherwise switch the first entry into the last entry of the previous row.
		else
		{
			data[col-1][j] = data[0][j+1];
		}
	}
}
