// Import required libraries.
#include <stdio.h>


/*
	To change the number of columns you would only need to change numberOfTests by that number, and then change any [6] to be 
	2 more then whatever number was put in numberOfTests.
	To change the number of rows ie students that can be entered, change the numberOfStudents to that number and change the 
	first declartion of numTable from [12] to be 2 more then whatever number was put in numberOfStudents.
*/

/* 
	Function prototypes:
	readData(float[][6]) reads in a ? by 6 two dimensional array and returns the amount of rows that have data inputted into them.
	RowCalc(float[][6], int) caclulates the average and the minimum number per row, and inputs them into the side columns in the array.
	ColumnCalc(float[][6], int) caclulates the average and the minimum number per column, and inputs them into the bottom rows of the array.
*/
float ReadData(float[][6]);
void RowCalc(float[][6], int, int*);
void ColumnCalc(float[][6], int);

// Constant variable for ease of modifiying if more tests or students are added in later years.
const int numberOfTests = 4, numberOfStudents = 10;

/* 
	Starts the program to take the input of grades of up to 10 different students then calculate their minimum, and their average,
	then calculate the average and minimum of the whole class, well keeping track of the scores above 90%
*/
float main(void)
{
	/* 
		Declare variables. From the assignment we know there will only be up to 10 students, and 4 tests. 
		We declare the table to have two extra columns and rows to store the minimum and average. 
	*/
	float numTable[12][6];
	int ninety = 0, r, c;
	
	// Prompt for input.
	printf("Please enter a student's test grades, each seperated by a space, and then repeat until there is no more to enter. When you are finished please enter -1 in the first column\n");
	// Call readData to fill numTable with values, and to get the number of rows inputted.
	float numberOfRows = ReadData(numTable);
	printf("\n\n");
	// Call RowCalc to get the averages and minimums stored in numTable.
	RowCalc(numTable, numberOfRows, &ninety);
	printf("\n\n");
	// Call ColumnCalc to get the averages and minimums stored in numTable.
	ColumnCalc(numTable, numberOfRows);
	
	// Print numTable in the correct fashion. 
	printf("\tTest1\tTest2\tTest3\tTest4\tRow Ave\tRow Min");
	for (r = 0; r < numberOfRows; r++)
	{		

		printf("\n\t");
		for (c = 0; c < numberOfTests+2; c++)
		{
			if (c != numberOfTests)
			{
				printf("%0.0f\t", numTable[r][c]);
			}
			else
			{
				printf("%0.2f\t", numTable[r][c]);
			}
		}
	}
	for (r = numberOfStudents; r < numberOfStudents+2; r++)
	{
		switch ((r == numberOfStudents))
		{
		case 1: printf("\nAverage\t"); break;
		case 0: printf("\nMinimum\t"); break;
		}
		for (c = 0; c < numberOfTests+2; c++)
		{
			if (r == numberOfStudents && c == (numberOfTests+1) || r == (numberOfStudents+1) && c == numberOfTests)
			{
				printf(" - \t");
			}
			else
			{
				if (r == numberOfStudents)
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
float ReadData(float table[][6])
{
	int r, c;
	float input, rowNum = 0;
	for (r = 0; r < numberOfStudents+2; r++)
	{
		scanf("%f", &input);
		if (input == -1)
		{
			return rowNum;
		}
		else
		{
			table[r][0] = input;
			for (c = 1; c < numberOfTests; c++)
			{
				scanf("%f", &table[r][c]);
			}
			rowNum++;
		}
	}
	return rowNum;
}

/* 
	RowCalc() takes a [] by [6] array and calculates the average and minimum values for each row upto a total equal to maxRows, it also contains a pointer to a variable to store any numbers 90 and above.
*/
void RowCalc(float table[][6], int maxRows, int* ninetyGreater)
{
	// Declare variables.
	int r, c;
	// Cicle through the rows reseting the correct result row to the start for each loop.
	for (r = 0; r < maxRows; r++)
	{
		// Set the row minimum entry index to the first result of that row.
		table[r][(numberOfTests+1)] = table[r][0];
		// Set the row sum entry index to zero.
		table[r][numberOfTests] = 0;
		// Cicle through the columns updating the sum an minimum values for each column.
		for (c = 0; c < numberOfTests; c++)
		{
			// If the current entry is greater then or equal to ninety increase the ninetyGreater pointer.
			if (table[r][c] >= 90)
			{
				*ninetyGreater += 1;
			}
			// Update the sum entry for that row with the current row and column entry.
			table[r][numberOfTests] += table[r][c];
			// If the current row and column entry is less then the minimum entry index set the minimum equal to the current row and column.
			if (table[r][c] < table[r][(numberOfTests+1)])
			{
				table[r][(numberOfTests+1)] = table[r][c];
			}
		}
		// At the end of every row update the row sum to be divided by the amount of tests.
		table[r][numberOfTests] /= numberOfTests;
	}	
}

/*
	ColumnCalc takes a [] by [6] array and calculates the average and minimum values for each column based on the amount of rows equal to maxRows.
*/
void ColumnCalc(float table[][6], int maxRows)
{
	// Declare variables.
	int r, c;
	// Cicle through the columns reseting the sum and minimum entrys to zero and the start of each column respectively.
	for (c = 0; c < numberOfTests+2; c++)
	{
		// Set the column minimum entry to the first entry of that column.
		table[(numberOfStudents+1)][c] = table[0][c];
		// Set the column sum entry to zero.
		table[numberOfStudents][c] = 0;
		// Cicle through each row upto a total equal to maxRows.
		for (r = 0; r < maxRows; r++)
		{
			// Increase the sum entry by the current row and column.
			table[numberOfStudents][c] += table[r][c];
			// if the current row and column is less then the minimum entry update the minimum to the current row and column.
			if (table[r][c] < table[(numberOfStudents+1)][c])
			{
				table[(numberOfStudents+1)][c] = table[r][c];
			}
		}
		// At the end of every column update the column sum to be divided by maxRows.
		table[numberOfStudents][c] /= maxRows;
	}
}
