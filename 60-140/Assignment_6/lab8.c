// Import required libraries.
#include <stdio.h>

/* Function prototypes:
readData(float[12][6]) reads in a 12 by 6 two dimensional array and returns the amount of rows that have data inputted into them.
RowCalc(float[12][6], int) caclulates the average and the minimum number per row, and inputs them into the side columns in the array.
ColumnCalc(float[12][6], int) caclulates the average and the minimum number per column, and inputs them into the bottom rows of the array.
*/
float ReadData(float[12][6]);
void RowCalc(float[12][6], int);
void ColumnCalc(float[12][6], int);

// Constant variable for ease of modifiying if more tests are added in later years.
const float numberOfTests = 4.0;

/* Starts the program to take the input of grades of up to 10 different students then calculate their minimum, and their average,
then calculate the average and minimum of the whole class, well keeping track of the scores above 90%*/
float main(void)
{
	// Declare variables.
	float numTable[12][6];
	int ninety = 0, r, c;
	
	// Call readData to fill numTable with values, and to get the number of rows inputted.
	float numberOfRows = ReadData(numTable);
	printf("\n\n");
	// Call RowCalc to get the averages and minimums stored in numTable.
	RowCalc(numTable, numberOfRows);
	printf("\n\n");
	// Call ColumnCalc to get the averages and minimums stored in numTable.
	ColumnCalc(numTable, numberOfRows);
	
	// Print numTable in the correct fashion. 
	printf("\tTest1\tTest2\tTest3\tTest4\tRow Ave\tRow Min");
	for (r = 0; r < numberOfRows; r++)
	{		

		printf("\n\t");
		for (c = 0; c < 6; c++)
		{
			if (numTable[r][c] >= 90)
			{
				ninety++;
			}
			if (c != 4)
			{
				printf("%0.0f\t", numTable[r][c]);
			}
			else
			{
				printf("%0.2f\t", numTable[r][c]);
			}
		}
	}
	for (r = 10; r < 12; r++)
	{
		switch (r)
		{
		case 10: printf("\nAverage\t"); break;
		case 11: printf("\nMinimum\t"); break;
		}
		for (c = 0; c < 6; c++)
		{
			if (r == 10 && c == 5 || r == 11 && c == 4)
			{
				printf(" - \t");
			}
			else
			{
				if (r == 10)
				{
					printf("%0.2f\t", numTable[r][c]);
				}
				else
				{
					printf("%0.0f\t", numTable[r][c]);
				}
			}
		}
	}
	printf("\n\nThere are %d scores greater than or equal to 90%%", ninety);
	printf("\n\n");

	// End the program
	return 0;
}

/* 
	ReadData() reads in numbers into a a two dimensional 4 numbers per row, until a -1 is inputted as the first number of a row. 
	For every row that is inputted rowNum is increased by one and then returns it at the end. 
*/
float ReadData(float table[12][6])
{
	int r, c;
	float input, rowNum = 0;
	for (r = 0; r < 12; r++)
	{
		scanf("%f", &input);
		if (input == -1)
		{
			return rowNum;
		}
		else
		{
			table[r][0] = input
			for (c = 1; c < 4; c++)
			{
				scanf("%f", &input);
				table[r][c] = input;
			}
			rowNum++;
		}
	}
	return rowNum;
}

/* 
	RowCalc() takes a [12] by [6] array and calculates the average and minimum values for each row upto a total equal to maxRows.
*/
void RowCalc(float table[12][6], int maxRows)
{
	// Declare variables.
	int r, c;
	// Cicle through the rows reseting the correct result row to the start for each loop.
	for (r = 0; r < maxRows; r++)
	{
		// Set the row minimum entry index to the first result of that row.
		table[r][5] = table[r][0];
		// Set the row sum entry index to zero.
		table[r][4] = 0;
		// Cicle through the columns updating the sum an minimum values for each column.
		for (c = 0; c < 4; c++)
		{
			// Update the sum entry for that row with the current row and column entry.
			table[r][4] += table[r][c];
			// If the current row and column entry is less then the minimum entry index set the minimum equal to the current row and column.
			if (table[r][c] < table[r][5])
			{
				table[r][5] = table[r][c];
			}
		}
		// At the end of every row update the row sum to be divided by the amount of tests.
		table[r][4] /= numberOfTests;
	}	
}

/*
	ColumnCalc takes a [12] by [6] array and calculates the average and minimum values for each column based on the amount of rows equal to maxRows.
*/
void ColumnCalc(float table[10][6], int maxRows)
{
	// Declare variables.
	int r, c;
	// Cicle through the columns reseting the sum and minimum entrys to zero and the start of each column respectively.
	for (c = 0; c < 6; c++)
	{
		// Set the column minimum entry to the first entry of that column.
		table[11][c] = table[0][c];
		// Set the column sum entry to zero.
		table[10][c] = 0;
		// Cicle through each row upto a total equal to maxRows.
		for (r = 0; r < maxRows; r++)
		{
			// Increase the sum entry by the current row and column.
			table[10][c] += table[r][c];
			// if the current row and column is less then the minimum entry update the minimum to the current row and column.
			if (table[r][c] < table[11][c])
			{
				table[11][c] = table[r][c];
			}
		}
		// At the end of every column update the column sum to be divided by maxRows.
		table[10][c] /= maxRows;
	}
}
