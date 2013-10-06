/*
	Name: Stephen Nusko
	ID: 103693282
	Date 14/02/2012
	Purpose: To showcase lab 5's char arrays by reversing normally and recursively, and spliting a sentence into alphabetical order.
*/
// Import required libaries, and define SIZE to be 80.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80


void reverseR(char start[], int first, int last);	// reverseR will take a char array and reverse the order of the string recursively.
void reverse( char *);					// Will reverse the inputed array in place.
void ParseSentence(char wordList[]);			// ParseSentence will take a char array and split any words into a seperate wordlist, it will then call a function to sort into alpabetical order, and then print the words.
void sortWords(char *wordList[], int size);		// Sortwords takes a list of words and the amount of words and sorts them into alpabetical order using a selection sort.
void printWords(char *wordList[], int size);		// Print all the words contained in the inputer word list.
void swapArray(char **first, char **second);		// swapChar will switch the locations of the two chars arrays.
void swapChar(char *first, char *second);		// Swap a *char[] entry with another.
void printBuffer(char *pointer);			// To print out the string starting at the pointer inputted.

int main(void)
{
	// The first buffer set each entry.
	char Buffer1[SIZE] = {'t', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '.', '\0'};
	char Buffer2[SIZE] = "this is the second buffer.";	// Setting the second entry.
	char Buffer3[SIZE], sentence[SIZE];					// Set up the two arrays to store the third buffer, and the sentence to be split.
	char *pBuffer = Buffer3, junk;								// A variable to store a pointer to the array, and a variable to store the line return.
	int choice = 0;										// A variable to store the user choice in the menu.

	do
	{
		// Display the menu choices to the user, and prompt for input.
		printf("\n1) Enter a word into buffer 3.\n");
		printf("2) Print out the three buffers\n");
		printf("3) Enter a sentence to split into alphabetical order\n");
		printf("4) Use the normal function to reverse buffer 3.\n");
		printf("5) Use the recursive function to reverse the buffer 3.\n");
		printf("6) Use a pointer to print out Buffer 3.\n");
		printf("Please input the desired function's number, 0 if you no longer wish to continue\n");
		// Read user input.
		scanf("%d", &choice);
		// Check which number was inputted.
		switch (choice)
		{
		case 1:
		{
			// Use scanf to get a word from the input.
			// I assumed that since scanf is only supposed to get the input up to a space, that it was working correctly.
			printf("Please input a word for buffer 3\n");
			scanf("%s", Buffer3);
			break;
		}
		case 2:
		{
			// Use printf to print out the three buffers.
			printf("\nFirst buffer: %s\n", Buffer1);
			printf("Second buffer: %s\n", Buffer2);
			printf("Third buffer is: %s\n\n", Buffer3);
			break;
		}
		case 3:
		{
			// Get the required input of a sentence and then print it out in alphabetical word order.
			printf("Please input a sentence to be split into alphabetical order\n");
			scanf("%c", &junk);
			fgets(sentence, SIZE, stdin);
			ParseSentence(sentence);
			break;
		}
		case 4:
		{
			// Reverse Buffer 3.
			reverse(pBuffer);
			break;
		}
		case 5:
		{
			// Reverse Buffer 3.
			reverseR(pBuffer, 0, strlen(Buffer3)-1);
			break;
		}
		case 6:
		{
			// Print out Buffer 3.
			printBuffer(pBuffer);
			break;
		}
		case 0:
		{
			// Thank the user for testing the program since the while loop will end.
			printf("\nThank you for testing the programs :).\n\n");
			break;
		}
		default:
		{
			// Inform the user there was an incorrect input, and prompt for correct input.
			printf("Incorrect input. Please input a number between 1 and 16, or 0 if you wish to exit");
		}
		}
		// If the choice was 0 end the while loop.
	} while (choice != 0);
	// End the program.
	return 0;
}

/*
	Definition:
		To print out the string starting at the pointer inputted.
	Input:
		A char pointer pointing to some location in a string, that will hit the '\0' charactor.
	Output:
		The string will be printed to the screen.;
*/
void printBuffer(char *pointer)
{
	char *temp = pointer;			// A variable to hold the pointer so the original is unchanged.
	while (*temp != '\0')			// While there are more to visit print out the current one.
	{
		printf("%c", *temp);
		temp++;
	}
}

/*
	Definition:
		Swap a *char[] entry with another.
	Input:
		Two double char pointers (a list of pointers) to be swaped.
	Output:
		The two list locations will be swaped in memory.
*/
void swapArray(char **first, char **second) {
	char *temp;						// A variable to hold a temperaory value.
	temp = *first;
	*first = *second;
	*second = temp;
}

/*
	Definition:
		Sortwords takes a list of words and the amount of words and sorts them into alpabetical order using a selection sort.
	Input:
		A list of pointers to to char arrays, and the total amount of words in the list.
	Output:
		The words in the list will be sorted into alpabetical order.
*/
void sortWords(char *wordList[], int size) 
{
	int i, j;										// Counter variabe to go through the list.
	for(i = 0; i < size; ++i)						// Go through the entire list once.
	{
		for(j = i + 1; j < size; ++j)				// Go through the unsorted list looking for the min.
		{
		if(strcmp(wordList[i], wordList[j]) > 0)	// if the current is less then the lowest unsorted swap them.
		{
			swapArray(&wordList[i], &wordList[j]);
		}
		}
	}
}

/*
	Definition:
		Print all the words contained in the inputer word list.
	Input:
		A list of pointers to to char arrays, and the total amount of words in the list.
	Output:
		The words in the list will be printed to the screen.
*/
void printWords(char *wordList[], int size)
{
	int i;											// Counter variable to go through the word list.
	for (i = 0; i < size; i++)
	{
			printf("%s\n", wordList[i]);
	}
}

/*
	Definition:
		ParseSentence will take a char array and split any words into a seperate wordlist, it will then call a function to sort into alpabetical order, and then print the words.
	Input:
		A char array containing a string.
	Output:
		The sentence will be printed to the screen in alpabetical order.
*/
void ParseSentence(char data[])
{
	char *wordPtr, *wordList[SIZE];				// A pointer to seperate the words, and a list of pointers to hold the words.
	int counter = 0;							// A counter variable to hold how many words were in the sentence.
	wordPtr = strtok( data, " ,.;" );			// Set the strtok to the array inputted, and the delimiters to a ' ', ',' '.', ';'.
	while( wordPtr != NULL )
	{
		wordList[counter] =  wordPtr;
		wordPtr = strtok( NULL, " ,.;" );
		counter++;
	}
	sortWords(wordList, counter);
	printWords(wordList, counter);
}

/*
	Defintion:
		Will reverse the inputed array in place.
	Input:
		A pointed to the char array.
	Output:
		The array will be in reverse order then when it was inputted.
*/
void reverse( char *data)
{
   char *first = data, *last = data;			// variables to store the locations of the first and last entry in the string.

   while ( *last !='\0')
   {
      last++;
   }
   last--;
   while ( first < last )
   {
      swapChar(first, last);
	  first++;
      last--;
   }
}

/*
	Definition:
		swapChar will switch the locations of the two chars.
	Input:
		Two pointers to a char value.
	Output:
		The values will be swaped in locations.
*/
void swapChar(char *first, char *second)
{
	char temp = *first;					// A variable to store for the swap later.
	*first = *second;
	*second = temp;
}

/*
	Definition:
		reverseR will take a char array and reverse the order of the string recursively.
	Input:
		The char array to be reversed, the first index and the last to be swapped.
	Output:
		The string will be reversed in the array.
*/
void reverseR(char start[], int first, int last)
{
	if (start[first] == '\0' || first >= last)			// If the inputted list is empty, or already past the mid pointer return.
	{
		return;
	}
	else												// Else swap the current first and last, and call the function again with first+1, and last-1.
	{
		swapChar(&start[first], &start[last]);
		reverseR(start, first + 1, last - 1);
		return;
	}
}

