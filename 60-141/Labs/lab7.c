/*
	Name: Stephen Nusko
	Id: 103693282
	Date: march 12th
	Purpose: To showcase file writing and printing, along with the use of strutures, and input.
*/

// define and include required libraries.
#include <stdio.h>
#include <ctype.h>
#define MAX 3

// struct employee stores the first, and last names and the worker id for the employee.
struct employee
{
	char firstname[40];			// The first name of the employee.
	char lastname[40];			// Second name of the employee.
	int id;						// The id of the worker.
};


typedef struct employee Employee;

/* Input the employee data interactively from the keyboard */
void InputEmployeeRecord(Employee *ptrEmp);
/* Display the contents of a given Employee record */
void PrintEmployeeRecord(const Employee e[]);
/* Save the contents of the employee record list to the newly created text file specified by FileName */
void SaveEmployeeRecords(const Employee e[], const char *FileName);

void main()
{
	int i;
	Employee e1[MAX];
	for (i = 0; i < MAX; i++)
	{
		InputEmployeeRecord(&e1[i]);
	}
	SaveEmployeeRecords(e1, "employee.dat");
	PrintEmployeeRecord(e1);
}

/*
	Definition:
		Input the employee data interactively from the keyboard 
	Input: 
		The user will input the required data, and the location where it should be saved.
	output: 
		The new employee structure will be saved at the inputted location.
*/
void InputEmployeeRecord(Employee* e1)
{
	printf("Please input the first name\n");
	scanf("%s", e1->firstname);
	printf("Please input the last name\n");
	scanf("%s", e1->lastname);
	printf("Please input the id\n");
	scanf("%d", &e1->id);
}


/* 
	definition:
		Display the contents of a given Employee record 
	input:
		The array of employee structures to be printed, of size MAX.
	output:
		the array's contacts will be printed to the screen.
*/
void PrintEmployeeRecord( const  Employee e[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("Name: %s %s, ID: %d\n", e[i].firstname, e[i].lastname, e[i].id);
	}
}

/* 
	definition:
		Save the contents of the employee record list to the newly created text file specified by FileName.
	input:
		The array to be saved, and the filename to be saved in.
	output:
		The contents of the array will be printed to the file, or the user will be informed of an error.
*/
void SaveEmployeeRecords(const Employee e[], const char *FileName)
{
	int i;
	FILE* file = fopen(FileName, "w");
	if (file != NULL)
	{
		for (i = 0; i < MAX; i++)
		{
			if (i == 0)
			{
				fprintf(file, "%d %s %s", e[i].id, e[i].firstname, e[i].lastname);
			}
			else
			{
				fprintf(file, "\n%d %s %s", e[i].id, e[i].firstname, e[i].lastname);				
			}
		}
		fclose(file);
	}
	else
	{
		printf("File not opened\n");
	}
}
