// Import required libriaries.
#include <stdlib.h>
#include <stdio.h>

// The struct point will contain the x and y coordinates of a point as well as a label to identify the point, it should also have a pointer to the next point in the list.
struct point
{
	int x;				// The x coordinate
	int y;				// The y coordinate
	char label[21];			// The label should contain a unique identifier of the point.
	struct point *ptrNext;		// self referential pointer to the next point.
};

typedef struct point Point;

int isEmptyList(Point *ptrF);					// isEmptyList will return 1 if the first pointer is NULL, and 0 if it is not.
void PrintList(Point *ptrF);					// printList will display the entire list to the screen.
void ResetList(Point *ptrF);					// ResetList will free all the memory used in the list.
void AddToBeginning(Point *ptrF, Point *ptrL);			// AddToBeginning will collect then add a new point onto the start of the list.
void AddToEnd(Point *ptrF, Point *ptrL);			// AddToEnd will collect then add a new point onto the end of the list.
void InputRecord(Point *ptrNew);				// InputRecord will collect the required information and set up the inputted Point.
void printToFile(Point *ptrF);					// printToFile will take the list of Points, and save it to a file.
void readFromFile(Point *ptrF);					// readFromFile will take the list of Points read the Points from the file.

Point *ptrFirst = NULL;	// Set the first pointer to NULL.
Point *ptrLast = NULL;	// Set the last pointer to NULL.


void main()
{
	int choice;	// A variable for the user's choice.
	// While the user doesn't select 0 to exit continue.
	do
	{
	printf("1. Add a point at the END of the list.\n"
			"2. Add a point at the BEGINNING of the list.\n"
			"3. Is the list empty?\n"
			"4. Erase all points from the list (reset).\n"
			"5. Display the list.\n"
			"6. Save the list to a sequential file (reset/replace file contents)\n"
			"7. Read the list back from a sequential file (replace current memory content)\n"
			"0. Exit\n"
			"> ");
	scanf("%d", &choice);
	// Switch the user's choice and all the correct function.
	switch (choice)
	{
		case 1:
		{
			AddToEnd(ptrFirst, ptrLast);
			break;
		}
		case 2:
		{
			AddToBeginning(ptrFirst, ptrLast);
			break;
		}
		case 3:
		{
			if (isEmptyList(ptrFirst))
			{
				printf("The list is empty\n");
			}
			else
			{
				printf("The list is not empty\n");
			}
			break;
		}
		case 4:
		{
			ResetList(ptrFirst);
			break;
		}
		case 5:
		{
			PrintList(ptrFirst);
			break;
		}
		case 6:
		{
			printToFile(ptrFirst);
			break;
		}
		case 7:
		{
			readFromFile(ptrFirst);
			break;
		}
		case 0:
		{
			// Thank the user for testing the program since the while loop will end.
			ResetList(ptrFirst);
			printf("\nThank you for using Personal Contact Book v1.0:).\n\n");
			break;
		}
		default:
		{
			// Inform the user there was an incorrect input, and prompt for correct input.
			printf("Incorrect input. Please input a number between 1 and 7, or 0 if you wish to exit");
		}
	}
	}while (choice != 0);
}

/*
	Definition:
		isEmptyList will return 1 if the first pointer is NULL, and 0 if it is not.
	Input:
		The first pointer.
	Output:
		will return 1 if the list is empty or 0 if its not.
*/
int isEmptyList(Point *ptrF)
{
	if (ptrFirst == NULL)
	{
		return 1;
	}
	return 0;
}

/*
	Definition:
		printList will display the entire list to the screen.
	Input:
		The first pointer.
	Output:
		Will display the entire list to the screen.
*/
void PrintList(Point *ptrF)
{
	Point *temp = ptrFirst;	// The point to the current location to print.
	// While we are not done the list continue.
	if (temp == NULL)
	{
		printf("\nNothing to print!\n");
	}
	else
	{
		while (temp != NULL)
		{
			printf("%s, X: %d, Y: %d\n", temp->label, temp->x, temp->y);
			temp = temp->ptrNext;
		}
	}
}

/*
	Definition:
		ResetList will free all the memory used in the list.
	Input:
		The first pointer.
	Output:
		The first and last pointers will be set to NULL and all memory will be freed.
*/
void ResetList(Point *ptrF)
{
	Point * ptrcurr = ptrFirst, *nextNode;	// A pointer to the current pointer to be freed, and the next point in the list.
	// While there are more points to be freed in memory.
	while (ptrcurr != NULL)
	{
		nextNode = ptrcurr->ptrNext;
		free(ptrcurr);
		ptrcurr = nextNode;
	}
	ptrFirst = NULL;
	ptrLast = NULL;
}

/*
	Definition:
		AddToBeginning will collect then add a new point onto the start of the list.
	Input:
		the first and last pointers
	Output:
		The new point will be added to the beginning of the list.
*/
void AddToBeginning(Point *ptrF, Point *ptrL)
{
	Point *ptrNew = (Point*)malloc(sizeof(Point));		// The new point to be added.
	InputRecord(ptrNew);								// Put the required information into the new point.
	// If the first is NULL set up the list, otherwise add it to the front.
	if (ptrFirst == NULL)
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
		ptrLast->ptrNext = NULL;
		ptrFirst->ptrNext = NULL;
	}
	else
	{
		ptrNew->ptrNext = ptrFirst;
		ptrFirst = ptrNew;
	}
}

/*
	Definition:
		AddToEnd will collect then add a new point onto the end of the list.
	Input:
		the first and last pointers
	Output:
		The new point will be added to the end of the list.
*/
void AddToEnd(Point *ptrF, Point *ptrL)
{
	Point *ptrNew = (Point*)malloc(sizeof(Point));		// The new point to be added.
	InputRecord(ptrNew);								// Put the required information into the new point.
	// If the first is NULL set up the list, otherwise place it at the end.
	if (ptrFirst == NULL)
	{
		ptrFirst = ptrNew;
		ptrLast = ptrNew;
		ptrLast->ptrNext = NULL;
		ptrFirst->ptrNext = NULL;

	}
	else if (ptrFirst == ptrLast)
	{
		ptrLast = ptrNew;
		ptrFirst->ptrNext = ptrNew;
	}
	else
	{
		ptrNew->ptrNext = NULL;
		ptrLast->ptrNext = ptrNew;
		ptrLast = ptrNew;
	}
}

/*
	Definition:
		InputRecord will collect the required information and set up the inputted Point.
	Input:
		The Point to be filled in.
	Output:
		The new point will have its information added.
*/
void InputRecord(Point *ptrNew)
{
	printf("please input a label for the point\n");
	scanf("%s", ptrNew->label);
	printf("please input the x coordinates\n");
	scanf("%d", &ptrNew->x);
	printf("please input the y coordinates\n");
	scanf("%d", &ptrNew->y);
	ptrNew->ptrNext = NULL;
}

/*
	Definition:
		printToFile will take the list of Points, and save it to a file.
	Input:
		The first pointer.
	Output:
		The contents will try to save to the file Points.dat, and print the result.
*/
void printToFile(Point *ptrF)
{
	FILE *outfile;									// Declare a file pointer.
	Point *temp = ptrFirst;							// Declare a pointer to the start of the list.
	outfile = fopen("Points.dat", "w");		// Open the file for writing.
	if (temp == NULL)
	{
		printf("Nothing to save\n");
	}
	else
	{
		if (outfile != NULL)							// Check if the file opening was successful.
		{
			// While there are more WordStruct to print to the file
			while (temp != NULL)
			{
				if (temp != ptrLast)
				{
					fprintf(outfile, "%s %d %d\n", temp->label, temp->x, temp->y);
				}
				else
				{
					fprintf(outfile, "%s %d %d", temp->label, temp->x, temp->y);
				}
				temp = temp->ptrNext;
			}
			fclose(outfile);					// close the file when done.
			printf("\nSuccesfully printed to the file \"Points.dat\".\n");
		}
		else									// If there was an error notifiy the user.
		{
			printf("\nUnknown error opening the file, ending the program.\n");
		}
	}
}

/*
	Definition:
		readFromFile will take the list of Points read the Points from the file.
	Input:
		The first pointer.
	Output:
		The contacts will try to be read from the file Points.dat, and print the result.
*/
void readFromFile(Point *ptrF)
{
	FILE *infile;									// Declare a file pointer.
	infile = fopen("Points.dat", "r");			// Open the file for writing.
	ResetList(ptrFirst);

	if (infile != NULL)							// Check if the file opening was successful.
	{
		// While there are more WordStruct to print to the file
		while (!feof(infile))
		{
			Point *ptrNew = (Point*)malloc(sizeof(Point));
			fscanf(infile, "%s %d %d", ptrNew->label, &ptrNew->x, &ptrNew->y);
			if (ptrFirst == NULL)
			{
				ptrFirst = ptrNew;
				ptrLast = ptrNew;
				ptrLast->ptrNext = NULL;
				ptrFirst->ptrNext = NULL;

			}
			else if (ptrFirst == ptrLast)
			{
				ptrLast = ptrNew;
				ptrFirst->ptrNext = ptrNew;
			}
			else
			{
				ptrNew->ptrNext = NULL;
				ptrLast->ptrNext = ptrNew;
				ptrLast = ptrNew;
			}
		}
		fclose(infile);					// close the file when done.
		printf("\nSuccesfully read from the file \"Points.dat\".\n");
	}
	else									// If there was an error notifiy the user.
	{
		printf("\nUnknown error opening the file, ending the program.\n");
	}
}
