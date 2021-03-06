/*
	Name: Stephen Nusko
	ID: 103693282
	Date: March 6th 2012
	Purpose: To store a contact address book, and to provide saving and loading functionality.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME 40
#define ADDRESS 100
#define POSTAL 7
#define NUMBER 11

/*
	struct Contact stores the required information needed to store a Contact in a contact book.
*/
struct Contact {
	struct Contact* prev;						// A pointer to the previous Contact in the list.
	char firstName[NAME];						// A char array of size NAME for the firstname.
	char lastName[NAME];						// A char array of size NAME for the lastname.
	char address[ADDRESS];						// A char array of size ADDRESS that will store the contact's address.
	char postalCode[POSTAL];					// A char array of size POSTAL that will store the contact's postal code.
	char phoneNum[NUMBER];						// A char array of size NUMBER that will store the contact's phone number.
	struct Contact* next;						// A pointer to the next Contact in the list.
};

typedef struct Contact Contact;

Contact* addContact();							// addContact will return a fully filled contact data type, through the input taken from the user.
Contact* readContact();							// readContact will read the all the needed Contact information from the inputted FILE.
void printContact(Contact *data);				// printContact will display to the screen the inputted Contact data.

void printToFile();								// printToFile will take an array of Contacts and the number of contacts in the array, and save it to a file.
void readFromFile();							// readFromFile will take an array of Contacts read the contacts from the file.

void formatPhoneNumber(char data[]);			// formatPhoneNumber will display the phone number with the required () and -s needed.
void formatPostalCode(char data[]);				// formatPostalCode will display the Postal code with the required - as needed.
int isValidPhoneNumber(char data[]);			// isValidPhoneNumber will check if the inputted phone number is indeed valid for the standard ontario phone numbers.
int isValidPostalCode(char data[]);				// isValidPostalCode will check if the inputted postal code is indeed valid.
void encodeSpace(char data[]);					// encodeSpace takes a char array and make all '_' be replaced by ' '.
void decodeSpace(char data[]);					// encodeSpace takes a char array and makes all spaces be replaced by '_'.
void WordCap(char data[]);						// WordCap will make all new words start with a captial letter.

void addInOrder(Contact* newEntry);						// addInOrder will store the new entry into its correct alphabetical order.
void searchContacts(char name[]);						// searchContacts will take an an array of Contacts and check if the lastname ever occurs in the list.
void moveForward();										// moveForward will increase the location in the array by one.
void moveBackward();									// moveBackward will decrease the location in the array by one.
void deleteContact(char name[]);						// deleteContact will take the array of Contacts and the name to be deleted, and ask the user if its the one they wish to delete. (It will only delete one at a time).
void placeInFront(Contact* front, Contact* newEntry);	// placeInFront will place the newEntry in front of the front Contact in the list.
void ResetList();										// Frees all the allocated memory in the list.

Contact* head = NULL, *current = NULL;			// Declares the start and current to NULL.


int main(void)
{
	int choice = 0;										// A variable to store the user choice in the menu.
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
		printf("9) Reset the list to empty\n");
		printf("0) Exit.\n");
		printf("> ");
		// Read user input.
		scanf("%d", &choice);
		// Check which number was inputted.
		switch (choice)
		{
		case 1:
		{
			// Use scanf to get a word from the input..
			Contact* newContact = addContact();
			printf("Do you wish to add another contact?\n");
			scanf("%c", &additional);
			scanf("%c", &additional);
			addInOrder(newContact);
			while (additional == 'y')
			{
				newContact = addContact();
				addInOrder(newContact);
				printf("Do you wish to add another contact?\n");
				scanf("%c", &additional);
				scanf("%c", &additional);
			}
			break;
		}
		case 2:
		{
			// Use printf to print out the three buffers.
			printContact(current);
			break;
		}
		case 3:
		{
			// Get the required input of a sentence and then print it out in alphabetical word order.
			char name[40];
			printf("\nPlease input the last name that you wish to search for\n");
			scanf("%s", name);
			searchContacts(name);
			break;
		}
		case 4:
		{
			// Reverse Buffer 3.
			printToFile();
			break;
		}
		case 5:
		{
			// Reverse Buffer 3.
			readFromFile();
			break;
		}
		case 6:
		{
			moveForward();
			break;
		}
		case 7:
		{
			moveBackward();
			break;
		}
		case 8:
		{
			// Get the required input of a sentence and then print it out in alphabetical word order.
			char name[40];
			printf("\nPlease input the last name that you wish to delete for\n");
			scanf("%s", name);
			deleteContact(name);
			break;
		}
		case 9:
		{
			ResetList();
			break;
		}
		case 0:
		{
			// Thank the user for testing the program since the while loop will end.
			printf("Would you like to save the list before exiting?\n");
			scanf("%c", &additional);
			scanf("%c", &additional);
			if (additional == 'y' || additional == 'Y')
			{
				printToFile();
			}
			ResetList();
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
	} while (choice != 0);
	// End the program.
	return 0;
}

/*
	Definition:
		addContact will return a fully filled contact data type, through the input taken from the user.
	Input:
		The user will be prompted for all required input.
	Output:
		The function will return a Contact pointer that will contain all the required information.
*/
Contact* addContact()
{
	Contact* newContact;
	char junk;
	newContact = (Contact*)malloc(sizeof(Contact));
	printf("\nAdding new contact:\n");
	printf("First name\t:");
	scanf("%s", newContact->firstName);
	WordCap(newContact->firstName);
	printf("Last name\t:");
	scanf("%s", newContact->lastName);
	WordCap(newContact->lastName);
	printf("Address\t:");
	scanf("%c", &junk);
	fgets(newContact->address, ADDRESS, stdin);
	newContact->address[strlen(newContact->address)-1] = '\0';
	WordCap(newContact->address);
	printf("PostalCode\t:");
	scanf("%s", newContact->postalCode);
	// While the postal code is incorrect ask for a new one.
	while (isValidPostalCode(newContact->postalCode) == 0)
	{
		printf("Invalid postal code try again\t:");
		scanf("%s", newContact->postalCode);
	}
	printf("Phone\t:");
	scanf("%s", newContact->phoneNum);
	// While the phone number is incorrect ask for a new one.
	while (isValidPhoneNumber(newContact->phoneNum) == 0)
	{
		printf("Invalid Phone try again\t:");
		scanf("%s", newContact->phoneNum);
	}
	newContact->next = NULL;
	newContact->prev = NULL;
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
void printContact(Contact *data)
{
	if (data != NULL)
	{
		printf("\nFirst name\t:\t%s\n", data->firstName);
		printf("Last name\t:\t%s\n", data->lastName);
		printf("Address\t\t:\t%s\n", data->address);
		formatPostalCode(data->postalCode);
		formatPhoneNumber(data->phoneNum);
		printf("\n");
	}
	else
	{
		printf("\nThere was no data in this entry\n");
	}
}

/*
	Definition:
		searchContacts will take the last name to check and see if the lastname ever occurs in the list.
	Input:
		name is the lastname to be searched for.
	Output:
		The results of the search will be printed to the screen.
*/
void searchContacts(char name[])
{
	Contact* search = head,*start = NULL;		// Set up pointers that will look through the list.
	int found = 0, i;		// the number found and a counter variable.
	if (search != NULL)
	{
		// While we haven't reached the correct position of the list continue.
		while (strcasecmp(name, search->lastName) > 0)
		{
			search = search->next;
			if (search->next == head)
			{
				break;
			}
		}
		start = search;
		// While the current position is equal to the search name increase the found, and continue.
		while (strcasecmp(name, search->lastName) == 0)
		{
			found++;
			search = search->next;
		}
		printf("Found %d entries\n", found);
		// While there are more results print all the entires found.
		for (i = 0; i < found; i++)
		{
			printContact(start);
			start = start->next;
		}
	}
	else
	{
		printf("\nNo data was found to search\n");
	}
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
	int i;		// Counter variable.
	// While there are more entries to check continue.
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
	int i;		// Counter variable.
	// While there are more entries to check continue.
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
		printToFile will take the list of contacts, and save it to a file.
	Input:
		None
	Output:
		The contents will try to save to the file contactlist.dat, and print the result.
*/
void printToFile()
{
	FILE *outfile;									// Declare a file pointer.
	Contact *temp = head;							// Declare a pointer to the start of the list.
	if (temp != NULL)
	{
		outfile = fopen("contactlist.dat", "w");		// Open the file for writing.
		if (outfile != NULL)							// Check if the file opening was successful.
		{
			// While there are more Contacts to print to the file
			while (temp->next != head)
			{
				encodeSpace(temp->address);
				fprintf(outfile, "%s %s %s %s %s\n", temp->firstName, temp->lastName, temp->address, temp->postalCode, temp->phoneNum);
				temp = temp->next;
			}
			encodeSpace(temp->address);
			// print out the last entry so there is no new line charactor to mess up reading back.
			fprintf(outfile, "%s %s %s %s %s", temp->firstName, temp->lastName, temp->address, temp->postalCode, temp->phoneNum);
			fclose(outfile);					// close the file when done.
			printf("\nSuccesfully printed to the file \"contactlist.dat\".\n");
		}
		else									// If there was an error notifiy the user.
		{
			printf("\nUnknown error opening the file, ending the program.\n");
		}
	}
	else
	{
		printf("\nThere was no data to save to the file.\n");
	}
}

/*
	Definition:
		readFromFile will take the list of contacts read the contacts from the file.
	Input:
		None
	Output:
		The contacts will try to be read from the file contactlist.dat, and print the result.
*/
void readFromFile()
{
	FILE *infile;									// Declare a file pointer.
	Contact *temp;									// Declare a pointer to the temp Contact to be read from the file.
	infile = fopen("contactlist.dat", "r");			// Open the file for writing.
	// Reset the list and free all memory.
	ResetList();

	if (infile != NULL)							// Check if the file opening was successful.
	{
		// While there are more Contacts to read from the file continue.
		while (!feof(infile))
		{
			temp = readContact(infile);	
			addInOrder(temp);
		}
		fclose(infile);					// close the file when done.
		printf("\nSuccesfully read from the file \"contactlist.dat\".\n");
	}
	else									// If there was an error notifiy the user.
	{
		printf("\nUnknown error opening the file, ending the program.\n");
	}
}

/*
	Definition:
		readContact will read all the needed Contact information from the inputted FILE.
	Input:
		An already opened FILE pointer from the file to be read from.
	Output:
		Will return a Contact pointer containing the information from the file.
*/
Contact* readContact(FILE* infile)
{
	Contact* newContact = (Contact*)malloc(sizeof(Contact));			// The Contact to hold all the information from the file.
	fscanf(infile, "%s %s %s %s %s\n", newContact->firstName, newContact->lastName, newContact->address, newContact->postalCode, newContact->phoneNum);
	decodeSpace(newContact->address);
	WordCap(newContact->firstName);
	WordCap(newContact->lastName);
	WordCap(newContact->address);
	return newContact;
}

/*
	Definition:
		placeInFront will place the newEntry in front of the front Contact in the list.
	Input:
		The contact it should be placed in front of and the new entry to be placed in front.
	Output:
		The newEntry will be added in front of the front Contact node.
*/
void placeInFront(Contact* front, Contact * newEntry)
{
	newEntry->next = front;
	newEntry->prev = front->prev;
	front->prev->next = newEntry;
	front->prev = newEntry;
	if (front == head)
	{
		head = newEntry;
	}
}
/*
	Definition:
		addInOrder will store the new entry into its correct alphabetical order.
	Input:
		The newEntry to be added, the Contact array to store it in, and the current number of entries.
	Output:
		The contents will be stored the new entry into its correct alphabetical order.
*/
void addInOrder(Contact *newEntry)
{
	int notDone = 1;				// A loop control variable.
	Contact* temp,* i;				// To pointers to contacts to be used to loop through the list.
	// If the newEntry is NULL inform the user, otherwise find the correct location alphabetically and then add it.
	if (newEntry == NULL)
	{
		printf("\nNo new entry detected\n");
	}
	else
	{
		if (head == NULL)
		{
			head = newEntry;
			head->next = head;
			head->prev = head;
		}
		else if(head->prev == head)
		{
			if (strcmp(head->lastName, newEntry->lastName) > 0)
			{
				placeInFront(head, newEntry);
			}
			else if (strcmp(head->lastName, newEntry->lastName) == 0 && strcmp(head->firstName, newEntry->firstName) > 0)
			{
				placeInFront(head, newEntry);
			}
			else
			{
				newEntry->prev = head;
				newEntry->next = head;
				head->next = newEntry;
				head->prev = newEntry;
			}
		}
		else
		{
			i = head;
			// While the loop is not done and we haven't done a full cicle continue.
			do 
			{
				if (strcmp(i->lastName, newEntry->lastName) < 0)
				{
					i = i->prev;
					notDone = 0;
				} 
				else if (strcmp(i->lastName, newEntry->lastName) == 0 && strcmp(i->firstName, newEntry->firstName) < 0)
				{
					i = i->prev;
					notDone = 0;
				}
				else
				{
					break;
				}
			} while (i != head);
			if (!notDone && i == head)
			{
				placeInFront(i, newEntry);
				head = head->next;
			}
			else
			{
				placeInFront(i, newEntry);
			}
		}
		current = head;
	}
}

/*
	Definition:
		moveForward will increase the location in the list by one.
	Input:
		none.
	Output:
		will increase the user's position in the list to the next location.
*/
void moveForward()
{
	if (current != NULL)
	{
		current = current->next;
	}
	else
	{
		printf("List is empty\n");
	}
}

/*
	Definition:
		moveForward will decrease the location in the list by one.
	Input:
		none.
	Output:
		will increase the user's position in the list to the previous location.
*/
void moveBackward()
{
	if (current != NULL)
	{
		current = current->prev;
	}
	else
	{
		printf("List is empty\n");
	}
}

/*
	Definition:
		deleteContact will take the name to be deleted, and ask the user if its the one they wish to delete. (It will only delete one at a time).
	Input:
		The name of the person to check for.
	Output:
		Either a node will be deleted or nothing will happen based on user choice.
*/
void deleteContact( char name[])
{
	Contact* search = head;					// setup the list pointer to use.
	int found = 0;							// Set up the found variable.
	char choice;							// A char to hold the user's choice about deleting.
	if (search != NULL)
	{
		// While we aren't in the correct spot continue.
		while (strcasecmp(name, search->lastName) > 0)
		{
			search = search->next;
			if (search->next == head)
			{
				break;
			}
		}
		// While it is equal as the user if they wish to delete this contact.
		while (strcasecmp(name, search->lastName) == 0)
		{
			printContact(search);
			printf("Is this the entry you wish to delete?\n");
			scanf("%c", &choice);
			scanf("%c", &choice);
			if (choice == 'Y' || choice == 'y')
			{
				found = 1;
				break;
			}
			search = search->next;
		}
		// If the user decided to delete remove the entry from the list.
		if (found)
		{
			search->prev->next = search->next;
			search->next->prev = search->prev;
			if (current == search)
			{
				current = search->prev;
			}
			if (search == head)
			{
				head = search->next;
			}
			free(search);
		}
	}
	else
	{
		printf("\nNo data was found to search\n");
	}
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
	int i, space = 1;		// The counter variable, and a boolean varable to check if there was a space.
	// While not at the end of the string continue.
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

/*
	Definition:
		ResetList will transverse the entire list and free all the node's memory addresses.
	Input:
		none.
	Output:
		Will free all the memory used by the list nodes.
*/
void ResetList()
{
	Contact * ptrcurr = head, *nextNode;
	if (head != NULL)
	{
		head->prev->next = NULL;
		// While there are more nodes to be freed continue.
		while (ptrcurr != NULL)
		{
			nextNode = ptrcurr->next;
			free(ptrcurr);
			ptrcurr = nextNode;
		}
		head = NULL;
		current = NULL;
	}
}
