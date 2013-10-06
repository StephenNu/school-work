/*
	Name: Stephen Nusko
	ID: 103693282
	Date: 28/02/2012
	Lab exam 2
	Purpose:
*/

#include <stdlib.h> 
#include <stdio.h>
#define ROWS 5
#define COLS 10
#define TRAPS 3

void InitializeMaze(char data[][COLS]);			// InitializeMaze randomally fills the inputted array with 6 possible choices of D, U, R, L, G, and T (up to a max of three Ts).
int DoTrace(char data[][COLS], int x, int y);		// DoTrace follows the maze direction until its conclusion in either gold, traps, stuck after 10, or outside of the maze.
void PrintResults(char data[][COLS], int moves);	// PrintResults will take the array, and print the contents, and the result of the player's choice.

void main()
{
	char A[ROWS][COLS];				// The two-diminsional array to store the shape of the maze.
	int startX, startY;				// The starting x and y coordinates.
	int num_moves = 0;				// The total number of moves it took.

	// Get the starting location, fill the array, trace the steps, print the results.
	scanf("%d%d", &startX, &startY);
	InitializeMaze(A);
	num_moves = DoTrace(A, startX, startY);
	PrintResults(A, num_moves);
}

/*
	Definition:
		InitializeMaze randomally fills the inputted array with 6 possible choices of D, U, R, L, G, and T (up to a max of three Ts).
	Input:
		A two diminsional array.
	Output:
		The array will be filled with random selection of charactors from D, U, R, L, G and possiblely up to three Ts.
*/
void InitializeMaze(char data[][COLS])
{
	// Two counter variables, a random value to access the possible array, and the total amount of traps already in the array.
	int i, j, value, totalTraps = 0;
	char possible[6] = {'D', 'U', 'R', 'L', 'G', 'T' };	// The possible choices to fill the maze with.
	
	srand ( time(NULL) );
	// While there are more entries to visit continue.
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			value = rand() % 6;
			// If the random value is equal to T increase the amount of traps in the maze.
			if (possible[value] == 'T')
			{
				totalTraps++;
				// If the totalTraps is greater then the allowed number, continue getting a new value until it is no longer T.
				if (totalTraps > TRAPS)
				{
					while (possible[value] == 'T')
					{
						value = rand() % 6;
					}
				}
			}
			data[i][j] = possible[value];
		}
	}
}

/*
	Definition:
		DoTrace follows the maze direction until its conclusion in either gold, traps, stuck after 10, or outside of the maze.
	Input:
		A two diminsional array, and the starting x and y coordinates.
	Output:
		Will return based on moves,
			a) The total number of moves it took to get to the gold.
			b) The negative value of the number of moves it took to get to a trap.
			c) 0 if the player is still stuck after 10 moves.
			d) 15 if the player exited the maze.
*/
int DoTrace(char data[][COLS], int x, int y)
{
	int totalMoves = 0;				// The total number of moves made.
	// While the totalMoves is less then 10 continue.
	while (totalMoves <= 10)
	{	
		// If the current x and y is inside the array follow the directions.
		if (x > 0 && x < ROWS && y > 0 && y < COLS)
		{
			switch (data[x][y])
			{
			case 'D':
			{
				totalMoves++;
				y++;
				break;
			}
			case 'U':
			{
				totalMoves++;
				x--;			
				break;
			}
			case 'R':
			{
				totalMoves++;
				y++;
				break;			
			}
			case 'L':
			{
				totalMoves++;
				y--;
				break;			
			}
			case 'G':
			{
				return totalMoves;
			}
			case 'T':
			{
				return totalMoves * -1;
			}
			}
		}
		// Otherwise return 15 to show outside of the array.
		else 
		{
			return 15;
		}
	}
	// If the while loop failed reset totalMoves to zero to show the player is stuck.
	totalMoves = 0;
	return totalMoves;
}

/*
	Definition:
		PrintResults will take the array, and print the contents, and the result of the player's choice.
	Input:
		A two diminsional array, and the result of the moves from the starting location.
	Output:
		The contents of the array will be printed to the screen and depending on the value of moves, the outcome of the player's choice will be displayed.
*/
void PrintResults(char data[][COLS], int moves)
{
	int i, j;			// counter variables.
	// While there are more entries to print continue.
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%c", data[i][j]);
		}
		printf("\n");
	}
	// Check the result stored in moves, and print the correct response.
	if (moves < 0)
	{
		printf("Trap found in %d moves\n", moves*-1);
	}
	else if (moves == 0)
	{
		printf("Still stuck after 10 moves\n");
	}
	else if (moves == 15)
	{
		printf("We exited the maze\n");
	}
	else
	{
		printf("Gold found in %d moves\n", moves);
	}
}
