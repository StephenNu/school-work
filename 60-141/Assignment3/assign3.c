/*
	Name: Stephen Nusko
	ID: 103693282
	Date: March 6th 2012
	Purpose: To store a contact address book, and to provide saving and loading functionality.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NAME 40
#define ADDRESS 100
#define POSTAL 7
#define NUMBER 11
#define MAX 10

/*
	struct Contact stores the required needed to store a Contact in a contact book.
*/
struct Contact {
	char firstName[NAME];						// A char array of size NAME for the firstname.
	char lastName[NAME];						// A char array of size NAME for the lastname.
	char address[ADDRESS];						// A char array of size ADDRESS that will store the contact's address.
	char postalCode[POSTAL];					// A char array of size POSTAL that will store the contact's postal code.
	char phoneNum[NUMBER];						// A char array of size NUMBER that will store the contact's phone number.
};

typedef struct Contact Contact;

Contact addContact();							// addContact will return a fully filled contact data type, through the input taken from the user.
Contact readContact();							// readContact will read the all the needed Contact information from the inputted FILE.
void printContact(Contact data);				// printContact will display to the screen the inputted Contact data.

void printToFile(Contact dataList[], int size);	// printToFile will take an array of Contacts and the number of contacts in the array, and save it to a file.
int readFromFile(Contact dataList[]);			// readFromFile will take an array of Contacts read the contacts from the file.

void formatPhoneNumber(char data[]);			// formatPhoneNumber will display the phone number with the required () and -s needed.
void formatPostalCode(char data[]);				// formatPostalCode will display the Postal code with the required - as needed.
int isValidPhoneNumber(char data[]);			// isValidPhoneNumber will check if the inputted phone number is indeed valid for the standard ontario phone numbers.
int isValidPostalCode(char data[]);				// isValidPostalCode will check if the inputted postal code is indeed valid.
void encodeSpace(char data[]);					// encodeSpace takes a char array and make all '_' be replaced by ''
void decodeSpace(char data[]);					// encodeSpace takes a char array and makes all spaces be replaced by '_'.
void WordCap(char data[]);						// WordCap will make all new words start with a captial letter.

void addInOrder(Contact data[], Contact newEntry, int numEntries);			// addInOrder will store the new entry into its correct alphabetical order.
int searchContacts(int size, Contact* data, char name[], int results[]);	// searchContacts will take an an array of Contacts and check if the lastname ever occurs in the list.
int moveForward(int current, int size);										// moveForward will increase the location in the array by one.
int moveBackward(int current, int size);									// moveBackward will decrease the location in the array by one.
int deleteContact(int size, Contact* data, char name[]);					// deleteContact will take the array of Contacts and the name to be deleted, and ask the user if its the one they wish to delete. (It will only delete one at a time).
		
		
int main(void)
{
	Contact info[MAX];
	int choice = 0, location = 0, length = 0;										// A variable to store the user choice in the menu.
	char additional = 'y';
	printf("\n*** Personal Contact Book v1.0 ***\n");
	do 
	{
		// Display the menu choices to the user, and prompt for input.
		printf("\n1) Add new contact.\n");
		printf("2) Display current contact.\n");
		printf("3) Search for a contacts.\n");
		printf("4) Save contacts to file.\n");
		printf("5) Load contacts from file.\n");
		printf("6) Move to the next entry.\n");
		printf("7) Move to the previous entry.\n");
		printf("8) Search then delete an item.\n");
		printf("9) Exit.\n");
		// Read user input.
		scanf("%d", &choice);
		// Check which number was inputted.
		switch (choice)
		{
		case 1:
		{
			// Add a new contact.
			if (length < MAX)
			{
				addInOrder(info, addContact(), length);
				length++;
				// While they wish to continue adding contacts.
				while (additional == 'y' && length < MAX)
				{
					printf("Do you wish to add another contact?\n");
					scanf("%c", &additional);
					scanf("%c", &additional);
					if (length < MAX && additional == 'y')
					{
						addInOrder(info, addContact(), length);
						length++;
					}
					else
					{
						break;
					}
				}
				if (length == MAX)
				{
						printf("\nThe list is now full.\n");
				}
				additional = 'y';
			}
			else
			{
				printf("To many contacts saved, perhaps there are some that can be deleted?\n");
			}
			break;
		}
		case 2:
		{
			// Print the current Contact.
			printContact(info[location]);
			break;
		}
		case 3:
		{
			// Search for an entry.
			char search[NAME];
			int found[MAX], k, num;
			printf("Please input the last name to search for\n");
			scanf("%s", search);
			num = searchContacts(length, info, search, found);
			printf("%d records were found\n", num);
			for (k = 0; k < num; k++)
			{
				printContact(*(info+found[k]));
			}
			break;
		}
		case 4:
		{
			// Print the contacts to the file.
			printToFile(info, length);
			break;
		}
		case 5:
		{
			// read from the file.
			length = readFromFile(info);
			break;
		}
		case 6:
		{
			// Move forward by one.
			location = moveForward(location, length);
			break;
		}
		case 7:
		{
			// Move backward by one.
			location = moveBackward(location, length);
			break;
		}
		case 8:
		{
			// search and delete an entry.
			char search[NAME];
			printf("Please input the last name to search for\n");
			scanf("%s", search);
			length = deleteContact(length, info, search);
			location = 0;
			break;
		}
		case 9:
		{
			// Ask the user if they wish to save.
			char choice;
			printf("Would you like to save before exiting\n");
			scanf("%c", &choice);
			scanf("%c", &choice);
			if (choice == 'y' || choice == 'Y')
			{
				printToFile(info, length);	
			}	
			// Thank the user for testing the program since the while loop will end.
			printf("\nThank you for using Personal Contact Book v1.0:).\n\n");
			break;
		}
		default:
		{
			// Inform the user there was an incorrect input, and prompt for correct input.
			printf("Incorrect input. Please input a number between 1 and 16, or 0 if you wish to exit");
		}
		}
		// If the choice was 6 end the while loop.
	} while (choice != 9);
	// End the program.
	return 0;
}

/*
	Definition:
		addContact will return a fully filled contact data type, through the input taken from the user.
	Input:
		The user will be prompted for all required input.
	Output:
		The function will return a Contact type that will contain all the required information.
*/
Contact addContact()
{
	Contact newContact;					// The new contact to be stored.
	char junk;							// A variable to hold the new line.
	printf("\nAdding new contact:\n");
	printf("First name\t:");
	scanf("%s", newContact.firstName);
	WordCap(newContact.firstName);
	printf("Last name\t:");
	scanf("%s", newContact.lastName);
	WordCap(newContact.lastName);
	printf("Address\t:");
	scanf("%c", &junk);
	fgets(newContact.address, ADDRESS, stdin);
	newContact.address[strlen(newContact.address)-1] = '\0';
	WordCap(newContact.address);
	printf("PostalCode\t:");
	scanf("%s", newContact.postalCode);
	// While the postal code is incorrect ask for a new one.
	while (isValidPostalCode(newContact.postalCode) == 0)
	{
		printf("Invalid postal code try again\t:");
		scanf("%s", newContact.postalCode);
	}
	printf("Phone\t:");
	scanf("%s", newContact.phoneNum);
	// While the phone number is incorrect ask for a new one.
	while (isValidPhoneNumber(newContact.phoneNum) == 0)
	{
		printf("Invalid Phone try again\t:");
		scanf("%s", newContact.phoneNum);
	}
	return newContact;
}

/*
	Definition:
		printContact will display to the screen the inputted Contact data.
	Input:
		The Contact data to be printed.
	Output:
		The function will print the Contact type to the screen.
*/
void printContact(Contact data)
{
	printf("\nFirst name\t:\t%s\n", data.firstName);
	printf("Last name\t:\t%s\n", data.lastName);
	printf("Address\t\t:\t%s\n", data.address);
	formatPostalCode(data.postalCode);
	formatPhoneNumber(data.phoneNum);
	printf("\n");
}

/*
	Definition:
		searchContacts will take an an array of Contacts and check if the lastname ever occurs in the list.
	Input:
		Size is the size of the array, Contact* data is a pointer to the part of the array to be searched, name is the lastname to be searched for, and results store the indexes of the location.
	Output:
		The function will return the number of results, and also an array containing the indexes of the results.
*/
int searchContacts(int size, Contact* data, char name[], int results[])
{
	int i, found = 0, k;			// two counters, and a boolean variable.
	Contact* start = data;
	WordCap(name);
	// while there are more contacts to check continue.
	for (i = 0; i < size; i++)
	{
		if (strcmp((start+i)->lastName, name) == 0)
		{
			results[found] = i;
			found++;
		}
	}
	return found;
}

/*
	Definition:
		isValidPhoneNumber will check if the inputted phone number is indeed valid for the standard ontario phone numbers.
	Input:
		A char array that will contain all the phone number to be checked.
	Output:
		will return 1 if the number is valid, or 0 if not.
*/
int isValidPhoneNumber(char data[])
{
	int i;			// Counter variable
	if (strlen(data) != NUMBER - 1)
	{
		return 0;
	}
	else
	{
		// While there are more numbers to check continue.
		for (i = 0; i < NUMBER-1; i++)
		{
			if (!(isdigit(data[i])))
			{
				return 0;
			}
		}
	}
	return 1;
}

/*
	Definition:
		isValidPostalCode will check if the inputted postal code is indeed valid.
	Input:
		A char array that will contain the postal code to be checked.
	Output:
		will return 1 if the code is valid, or 0 if not.
*/
int isValidPostalCode(char data[])
{
	int i;			// Counter variable.
	if (strlen(data) != POSTAL - 1)
	{
		return 0;
	}
	else
	{
		// While there are more to check continue.
		for (i = 0; i < POSTAL-1; i++)
		{
			if (i % 2 == 0 && isdigit(data[i]))
			{
				return 0;
			}
			else if (i % 2 && isalpha(data[i]))
			{
				return 0;
			}
		}
	}
	return 1;
}

/*
	Definition:
		encodeSpace takes a char array and makes all spaces be replaced by '_'
	Input:
		The char array to be changed.
	Output:
		The array will have all spaces replaced by '_'.
*/
void encodeSpace(char data[])
{
	int i;			// Counter variable.
	// While we are not at the end of the string continue.
	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[i] == ' ')
		{
			data[i] = '_';
		}
	}
}

/*
	Definition:
		encodeSpace takes a char array and make all '_' be replaced by ''
	Input:
		The char array to be changed.
	Output:
		The array will have all '_' changed to a space.
*/
void decodeSpace(char data[])
{
	int i;			// Counter variable.
	// While we are not at the end of the string continue.
	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[i] == '_')
		{
			data[i] = ' ';
		}
	}
}

/*
	Definition:
		formatPhoneNumber will display the phone number with the required () and -s needed.
	Input:
		The phone number to be displayed.
	Output:
		The phone number will be displayed to the screen in the following manner (XXX) XXX-XXXX
*/
void formatPhoneNumber(char data[])
{
	
	int i;			// Counter variable.
	printf("Phone\t\t:\t(");
	// While we are not at the end of the string continue.
	for (i = 0; i < NUMBER; i++)
	{
		if (i == 3)
		{
			printf(") ");
		}
		else if (i == 6)
		{
			printf("-");
		}
		printf("%c", data[i]);
	}
	printf("\n");
}

/*
	Definition:
		formatPostalCode will display the Postal code with the required - as needed.
	Input:
		The postal code to be displayed.
	Output:
		The postal code will be displayed to the screen in the following manner X#X-#X#
*/
void formatPostalCode(char data[])
{
	int i;			// Counter variable.
	printf("Postal Code\t:\t");
	// While we are not at the end of the string continue.
	for (i = 0; i < POSTAL; i++)
	{
		if (i == 3)
		{
			printf("-");
		}
		if (islower(data[i]))
		{
			data[i] = toupper(data[i]);
		}
		printf("%c", data[i]);
	}
	printf("\n");
}

/*
	Definition:
		printToFile will take an array of Contacts and the number of contacts in the array, and save it to a file.
	Input:
		The list to be saved, and the total number of entries in the list.
	Output:
		The contents will try to save to the file contactlist.dat, and print the result.
*/
void printToFile(Contact dataList[], int size)
{
	int i;											// A counter variable.
	FILE *outfile;									// Declare a file pointer.
	outfile = fopen("contactlist.dat", "w");		// Open the file for writing.
	if (outfile != NULL)							// Check if the file opening was successful.
	{
		// While there are more Contacts to print to the file
		for (i = 0; i < size; i++)
		{
			encodeSpace(dataList[i].address);
			fprintf(outfile, "%s %s %s %s %s\n", dataList[i].firstName, dataList[i].lastName, dataList[i].address, dataList[i].postalCode, dataList[i].phoneNum);
		}
		fclose(outfile);					// close the file when done.
		printf("\nSuccesfully printed to the file \"contactlist.dat\".\n");
	}
	else									// If there was an error notifiy the user.
	{
		printf("\nUnknown error opening the file, ending the program.\n");
	}
}

/*
	Definition:
		readFromFile will take an array of Contacts read the contacts from the file.
	Input:
		The list to be loaded into.
	Output:
		The contacts will try to be read from the file contactlist.dat, and print the result.
*/
int readFromFile(Contact dataList[])
{
	int i = 0;											// A counter variable.
	FILE *infile;									// Declare a file pointer.
	infile = fopen("contactlist.dat", "r");		// Open the file for writing.
	if (infile != NULL)							// Check if the file opening was successful.
	{
		// While there are more Contacts to read from the file
		while (!feof(infile) && i < MAX)
		{			
			addInOrder(dataList, readContact(infile), i);
			i++;
		}
		fclose(infile);					// close the file when done.
		printf("\nSuccesfully read from the file \"contactlist.dat\".\n");
		return i;
	}
	else									// If there was an error notifiy the user.
	{
		printf("\nUnknown error opening the file, ending the program.\n");
	}
	return 0;
}

/*
	Definition:
		readContact will read the all the needed Contact information from the inputted FILE.
	Input:
		An already opened FILE pointer from the file to be read from.
	Output:
		Will return a Contact from the file.
*/
Contact readContact(FILE* infile)
{
	Contact newContact;
	fscanf(infile, "%s %s %s %s %s\n", newContact.firstName, newContact.lastName, newContact.address, newContact.postalCode, newContact.phoneNum);
	decodeSpace(newContact.address);
	WordCap(newContact.firstName);
	WordCap(newContact.lastName);
	WordCap(newContact.address);
	return newContact;
}

/*
	Definition:
		addInOrder will store the new entry into its correct alphabetical order.
	Input:
		The newEntry to be added, the Contact array to store it in, and the current number of entries.
	Output:
		The contents will be stored the new entry into its correct alphabetical order.
*/
void addInOrder(Contact data[], Contact newEntry, int numEntries)
{
	int i = numEntries - 1;			// Counter variable.
	Contact temp;					// Temp for the swap of the contacts.
	data[numEntries] = newEntry;	// puts the newEntry into the array.
	// While there are more entries to sort continue.
	while (i >= 0)
	{
		if (strcmp(data[i].lastName, data[i+1].lastName) > 0)
		{
			temp = data[i+1];
			data[i+1] = data[i];
			data[i] = temp;
		}
		else if (strcmp(data[i].lastName, data[i+1].lastName) == 0 && strcmp(data[i].firstName, data[i+1].firstName) > 0)
		{
			temp = data[i+1];
			data[i+1] = data[i];
			data[i] = temp;
		}
		i--;
	}
}

/*
	Definition:
		moveForward will increase the location in the array by one.
	Input:
		The current location, and the size of the array.
	Output:
		will return where the next location the user should go to.
*/
int moveForward(int current, int size)
{
	if (current == size-1)
	{
		return 0;
	}
	else
	{
		return current+1;
	}
}

/*
	Definition:
		moveBackward will decrease the location in the array by one.
	Input:
		The current location, and the size of the array.
	Output:
		will return where the next location the user should go to.
*/
int moveBackward(int current, int size)
{
	if (current == 0)
	{
		printf("%d, %d", current, size);
		return (size-1);
	}
	else
	{
		return current-1;
	}
}

/*
	Definition:
		deleteContact will take the array of Contacts and the name to be deleted, and ask the user if its the one they wish to delete. (It will only delete one at a time).
	Input:
		The size of the array, a pointer to the start of the array, the name of the person to check for.
	Output:
		Will return the new size of the array, if the user decides the found name will be deleted.
*/
int deleteContact(int size, Contact* data, char name[])
{
	int i, results[MAX], found = 0, k, j;		// 3 counter variables, the array of results, and how many were found.
	char choice;								// the user's choice.
	found = searchContacts(size, data, name, results);
	printf("%d records were found\n", found);
	// While there were more found or the user decides to delete the current one.
	for (k = 0; k < found; k++)
	{
		printContact(*(data+results[k]));
		printf("Is this the entry you want to delete?\n");
		scanf("%c", &choice);
		scanf("%c", &choice);
		if (choice == 'y')
		{
			size--;
			break;
		}
	}
	// reposition the array so there are no gaps.
	for (j = results[k]; j < size; j++)
	{
		*(data+j) = *(data+j+1);
	}
	return size;
}

/*
	Definition:
		WordCap will make all new words start with a captial letter.
	Input:
		The char array to be changed.
	Output:
		Every word in the array will now start with a capital letter.
*/
void WordCap(char data[])
{
	int i, space = 1;			// Counter variable, and a boolean to check if there was a space.
	// While there is more in the string continue.
	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[i] == ' ')
		{
			space = 1;
		}
		else if (space && isalpha(data[i]) && islower(data[i]))
		{
			data[i] = toupper(data[i]);
			space = 0;
		}
		else if (!space && isalpha(data[i]) && isupper(data[i]))
		{
			data[i] = tolower(data[i]);
		}
		else
		{
			space = 0;
		}
	}
}
