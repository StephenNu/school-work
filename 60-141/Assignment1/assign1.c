/*
	Name: Stephen Nusko
	ID#: 103693282
	Purpose: To take the input of the upper left and lower right corners of a rectangle, followed by the inputting of points to be checked if they are within any of the rectangles.
*/
#include <stdio.h>														// Required library
// Define the size of the array and the point which will stop the input of points to be checked.
#define ROWS 10
#define COLS 4
#define finalValue 9999.9

int getRectangle(double Rectangles[4][ROWS]);
void processPointsInRect(int totalRect, double rectData[][ROWS]);

// Start the main program, which will call the function to get the rectangle coordinates, and then call the function to gather and process points.
int main(void)
{
	// Declare the rectangle array.
	double rectangles[10][ROWS];
	// Declare and gather the rectangles returning the number of rectangles inputted. 
	int totalRect = getRectangle(rectangles);
	// Call processPointsInRect to gather X and Y points and then check if they are inside any rectangles.
	processPointsInRect(totalRect, rectangles);
	// Print a thank you.
	printf("\nThank you for using the software\n");
	// End the program.
	return 0;
}
/*
	Definition:
		The function getRectangles prompts and gathers the input for the upper left and lower right corner of a rectangle and then stores it.
	Input:
		The array rectangles will store the input and should be inputted first the upper left followed by the lower right points.
	Output:
		The array will be filled with rectangle shapes as many as the value in total. The function will return the total amount that were entered as an int.
*/
int getRectangle(double rectangles[][ROWS])
{
	// Declare the variables needed to count the total and control the loops.
	int total = 0, i;
	char shape = ' ';
	// Prompt for input, and explain how to exit.
	printf("\nPlease input an r representing the shape, followed by the X and Y coords of the upper left and then the X and Y of the bottom right.\n");
	printf("Once you are finished input a single '*' to finish inputing shapes\n");
	// Gather the char to represent the shape, and if its equal to r gather the X and Y points, and continue until either an '*' is inputted or the total goes over the size of ROWS.
	do
	{
		scanf("%c", &shape);
		if (shape == 'r')
		{
			for (i = 0; i < COLS; i++)
			{
				scanf("%lf", &rectangles[i][total]);
			}
			total++;
			printf("Please input another shape or '*' if you are finished\n");
		}
	} while(shape != '*' && total < ROWS);
	// Return the total amount of rectangles inputted.
	return total;
}
/*
	Definition:
		The function processPointsInRect, take the total number of rectangles to be processed in order using the data stored in rectData.
	Input:
		The totalrect should be the number of rectanges that were inputted into rectData.
	Output:
		The function will continue to output the prompts for x and y points and then tell them if its inside any of the rectangles stored in rectData.
*/
void processPointsInRect(int totalRect, double rectData[][ROWS])
{
	// Declare the counter variables, and the variables for the X and Y points.
	double pointX = 0.0, pointY = 0.0;
	int count = 1, i, j = 0;

	// Prompt for input of the X and Y coordinates.
	printf("\nPlease input the next X and Y coordinates.\n");
	scanf("%lf %lf", &pointX, &pointY);
	// While the X and Y of the point inputted is not equal to the the final value continue gathering and checking the points.
	while (pointX != finalValue && pointY != finalValue)
	{
		for (i = 0; i < totalRect; i++)
		{
			// Check if the points are within the rectangle, and print the message if its true.
			if (pointX > rectData[0][i] && pointX < rectData[2][i] && pointY < rectData[1][i] && pointX > rectData[3][i])
				{
					printf("\npoint %d is inside the figure %d\n", count, i+1);
					j = 1;
				}
		}
		// If the point was inside reset j to 0, otherwise print that there was no results.
		if (j)
		{
			j = 0;
		}
		else
		{
			printf("\npoint %d was not contained in any figure.\n", count);
		}
		// Increase the number of points processed by one.
		count++;
		// Prompt for input of the X and Y coordinates.
		printf("\nPlease input the next X and Y coordinates.\n");
		scanf("%lf %lf", &pointX, &pointY);
	}
}

