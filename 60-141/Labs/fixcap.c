/*
	Name: Stephen Nusko
	Id: 103693282
	Date: march 12th
	Purpose: To showcase file reading, writing and modifing, along with the use of strutures.
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

void PrintEmployeeRecord(const Employee e[]);						// Display the contents of a given Employee record.
void SaveEmployeeRecords(const Employee e[], const char *FileName);	// Save the contents of the employee record list to the newly created text file specified by FileName.
void LoadEmployeeRecords(Employee e[], const char *FileName);		// Load the contents of the employee record list from the inputted text file specified by FileName.
void WordCap(char string[]);										// WordCap captalize the start of every alphabetical word and makes the rest lower case.
void CapNames(Employee e[]);										// CapNames will captialize each name in the array of employee structures.

void main()
{
	int i;
	Employee e1[MAX];
	LoadEmployeeRecords(e1, "employee.dat");
	CapNames(e1);
	SaveEmployeeRecords(e1, "employee.dat");
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

/* 
	definition:
		Load the contents of the employee record list from the inputted text file specified by FileName.
	input:
		The array to be loaded, and the filename to be read from.
	output:
		The contents of the array will be read from the file, or the user will be informed of an error.
*/
void LoadEmployeeRecords(Employee e[], const char *FileName)
{
	int i;
	FILE* file = fopen(FileName, "r");
	char junk;
	if (file != NULL)
	{
		for (i = 0; i < MAX; i++)
		{
			if (i == 0)
			{
				fscanf(file, "%d %s %s", &e[i].id, e[i].firstname, e[i].lastname);
			}
			else
			{
				fscanf(file, "%c %d %s %s", &junk, &e[i].id, e[i].firstname, e[i].lastname);				
			}
		}
		fclose(file);
	}
	else
	{
		printf("File not opened\n");
	}
}

/*
	definition:
		CapNames will captialize each name in the array of employee structures.
	input:
		The array of size MAX to be captialized.
	output:
		The names will be captailized on the first word.
*/
void CapNames(Employee e[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		WordCap(e[i].firstname);
		WordCap(e[i].lastname);
	}
}

/*
	definition:
		WordCap captalize the start of every alphabetical word and makes the rest lower case.
	input:
		The string to be modified.
	output:
		the string will be captalized at the start of evey alphabetical word.
*/
void WordCap(char string[])
{
	int i, firstLetter = 1;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (firstLetter == 1 && isalpha(string[i]))
		{
			string[i] = toupper(string[i]);
			firstLetter = 0;
		}
		else if (string[i] == ' ')
		{
			firstLetter = 1;
		}
		else if (isupper(string[i]))
		{
			string[i] = tolower(string[i]);
		}
	}
}
