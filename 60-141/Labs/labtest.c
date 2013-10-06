/*
	Name: Stephen Nusko
	ID#: 103693282
	Purpose: To code take a two diminsional array and fill it with user entered values, then write two functions to print the array, and then to flip any
	number not on the diagonial.
*/

#include <stdio.h>						// Import required libraries
#define ROWS 20
#define COLS 20

void Print(float A[][COLS], int rows, int cols);		// Prints the array A, up to the size inputted in the values rows, and cols.
void Mirror(float A[][COLS], int rows, int cols);		// Filps the position of values not on the diagonial up to the size rows, and cols.


// The main will start the array A, and gather the size the user wishes to store values in, and the values before calling functions to work on the array.
void main(void)
{
	int p, q;						// Counter variables for the for loop.
	int rows, cols;						// The inputted size the user wishes for the array.
	float A[ROWS][COLS];					// Declaring the array A to be of size ROWS and COLS (defined above).

	// Request input for the number of rows and cols.
	printf("Enter # of rows, # of cols: \n");
	scanf("%d%d", &rows, &cols);
	// While there are more entries to fill gather the required information and store it in the array.
	for (p = 0; p < rows; p++)
	{
		printf("Enter %d column values for row %d:\n", cols, p+1);
		for (q = 0; q < cols; q++)
		{
			scanf("%f", &A[p][q]);
		}
	}

	Print(A, rows, cols);		// Print the array to the screen.
	Mirror(A, rows, cols);		// Flip the numbers not on the diagonial.
	Print(A, rows, cols);		// Print the result of the previous function.
}

/*
	Definition:
		Prints the array A up to the size of the inputs rows, and cols.
	Input:
		An Array A to be printed, and the values rows, and cols must be equal, and within the size of the array A.
	Output:
		The array's values will be printed out and displayed on the monitior.
*/
void Print(float A[][COLS], int rows, int cols)
{
	int i, j;			// Counter variables for the for loop.
	// While there are more entries to print to the screen continue.
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%0.2f\t", A[i][j]);
		}
		// Go to a new line.
		printf("\n");
	}
	// Format an extra space.
	printf("\n");
}
/*
	Definition:
		Filps the position of values not on the diagonial up to the size rows, and cols.
	Input:
		An Array A to be fliped, and the values rows, and cols must be equal, and within the size of the array A.
	Output:
		The inputted array A will have its numbers fliped around the diagonial up to the size of the inputs rows, and cols
		example;
				1.00 8.00 7.00
			A =	2.00 4.00 5.00
				3.00 6.00 0.00
			rows = 3, cols = 3
			output will be,
				1.00 2.00 3.00
			A =	8.00 4.00 6.00
				7.00 5.00 0.00

*/
void Mirror(float A[][COLS], int rows, int cols)
{
	float temp;			// A float to store the value to be fliped.
	int i, j;			// Counter variables for the for loop.
	// While there are more entries to be checked continue.
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			// If its not on the diagonial, and has not be fliped before. Flip the entry.
			if (i != j && j > i)
			{
				temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
			}
		}
	}
}

