/*
	Name: Stephen Nusko
	ID: 103693282
	Date 16/02/2012
	Purpose: To showcase the use of Structures in C. with the assignment for lab6 for 141.
*/

// Import required libraries, and define MAX_SIZE.
#include <string.h>
#include <stdio.h>
#define MAX_SIZE 51

// struct wordStruct is a structure that stores a single char array (string) of size MAX_SIZE, and also should contain the length of the string stored.
struct wordStruct {
	char Word[MAX_SIZE];
	int length;
};

// Define WordStruct such that when it is seen it will be replaced by struct wordStruct by the complier.
typedef struct wordStruct WordStruct;


void sortWords(WordStruct wordList[], int size);
void printToScreen(WordStruct wordList[], int size);
void printToFile(WordStruct wordList[], int size);

int main()
{
	char inputerString[] = "the cat in the hat jumped over the lazy fox done";	// Define the input string as per the lab assignment.
	char delims[] = " ", *word;													// set the splits in the sentence and declare a pointer to store the tokens.
	int numWords = 0;															// Store the number of words found.
	WordStruct wordList[MAX_SIZE];												// Declare a list of type WordStruct.

	word = strtok(inputerString, delims);										// Get the first token and store the address into word.
	
	// While the current token is not equal to done continue.
	while (strcmp(word, "done") != 0)
	{
		strcpy(wordList[numWords].Word, word);				// Copy the current token into the wordList array.
		wordList[numWords].length = strlen(word);			// Copy the length of the word into the wordList array.
		word = strtok(NULL, delims);					// Get the next token.
		numWords++;																// Increase the number of words by one.
	}
	
	printToScreen(wordList, numWords);											// Print the array of wordStructs to the screen.
	sortWords(wordList, numWords);												// Sort the array into alphabetical order.
	printToFile(wordList, numWords);											// Print the array of wordStructs to the file.
	// End the program.
	return 0;
}

/*
	Definition:
		printToScreen will print the array of WordStructs up to the inputted size to the screen.
	Input:
		An array of WordStructs, and the number of words in the array.
	Output:
		The contents of wordList will be printed to the screen.
*/
void printToScreen(WordStruct wordList[], int size)
{
	int i;								// A counter variable.
	// While there are more wordStucts to be printed continue.
	for (i = 0; i < size; i++)
	{
		printf("%s, %d\n", wordList[i].Word, wordList[i].length);
	}

}

/*
	Definition:
		printToFile will print the array of WordStructs up to the inputted size to the file wlist.txt.
	Input:
		An array of WordStructs, and the number of words in the array.
	Output:
		The contents of wordList will be printed to the file wlist.txt.
*/
void printToFile(WordStruct wordList[], int size)
{
	int i;									// A counter variable.
	FILE *outfile;							// Declare a file pointer.
	outfile = fopen("wlist.txt", "w");		// Open the file for writing.
	if (outfile != NULL)					// Check if the file opening was successful.
	{
		// While there are more WordStruct to print to the file
		for (i = 0; i < size; i++)
		{
			fprintf(outfile, "%s %d\n", wordList[i].Word, wordList[i].length);
		}
		fclose(outfile);					// close the file when done.
		printf("\nSuccesfully printed to the file \"wlist.txt\".\n");
	}
	else									// If there was an error notifiy the user.
	{
		printf("\nUnknown error opening the file, ending the program.\n");
	}
}

/*
	Definition:
		sortWords will sort the wordStruct's in the wordList into alphabetical order.
	Input:
		An array of WordStructs, and the number of words in the array.
	Output:
		sortWords will sort the wordStruct's in the wordList into alphabetical order.
*/
void sortWords(WordStruct wordList[], int size) 
{
	int i, j;													// Counter variabe to go through the list.
	WordStruct temp;
	for(i = 0; i < size; ++i)									// Go through the entire list once.
	{
		for(j = i + 1; j < size; ++j)							// Go through the unsorted list looking for the min.
		{
			if(strcmp(wordList[i].Word, wordList[j].Word) > 0)	// if the current is less then the lowest unsorted swap them.
			{
				temp = wordList[i];
				wordList[i] = wordList[j];
				wordList[j] = temp;
			}
		}
	}
}
