/*
	Name: Stephen Nusko
	ID: 103693282
	Date 28/02/2012
	Purpose: To see if the computer is able to correctly answer the inputed questions by only taking into account data fields where an ?=???? is seen.

*/
#define SIZE 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	struct ElectricityData, contains all the required information about a certain electrcity properties, like current, voltage, and power.
*/
struct ElectricityData
{
	char concept;			// Concept is a single charactor that represents the type of property, like P for power, or U for voltage, and I for current.
	char prefix;			// prefix will contain the modifier to the unit, i.e M for mega, m for milli, k for kilo
	char unit;				// Unit stores the respective unit the concept is stored in, Ie V for volts.
	char value[SIZE];		// Stores the the value as a string it should contain only number charactors. Up to 
};

// Define EData to be replaced by struct ElectricityData.
typedef struct ElectricityData EData;

void findAnswer(char question[], int counter);
EData returnData(char question[], int index);
void printData(EData answerData);
EData calculateAnswer(EData first, EData second);
double getWattValue(char data);


int main(void)
{
	int flag = 0, counter = 1;						// flag is the amount of times the program should go through the loop, and counter is how many times it has.
	char question[SIZE], junk, answer[SIZE];		// an array to store the question, and store the answers.
	
	// Get the number of questions.
	printf("Enter how many questions to do before exiting.\n");
	flag = atoi(gets(question));
	// While the currect question is less then the total questions you should proceed in getting the sentence and calculating the answer.
	while (counter < flag+1)
	{
		printf("Please input the question.\n");
		gets(question);
		findAnswer(question, counter);
		counter++;

	}
	return 0;
}

/*
	Definition:
		findAnswer will take a string containing the the question.
	Input:
		A char array containing the question, and a char array that will contain the answer.
	Output:
		The question array will still contain the original question, and will print out the correct answer based on the information given.
*/
void findAnswer(char question[], int counter)
{

	int i, k = 0;
	EData information[2], info;
	for (i = 0; question[i] != '\0'; i++)
	{
		if (question[i] == '=')
		{
			information[k] = returnData(question, i);
			k++;
		}
	}
	printf("\nProblem #%d\n", counter);
	printData(calculateAnswer(information[0], information[1]));
	printf("\n");
}

/*
	Definition:
		returnData will take the question and the index which should be an '=' sign, and then construct a new Edata structure.
	Input:
		A char array containing the question, and an index of the '=' sign
	Output:
		returnData will return a EData structure that contains all the information around the '=' in the question array.
*/
EData returnData(char question[], int index)
{
	EData info;
	int y, k;
	if (question[index] == '=')
	{
		info.concept = question[index-1];
		y = index+1;
		k = 0; 
		while(question[y] >= '0' && question[y] <= '9' || question[y] == '.')
		{
			info.value[k] = question[y];
			y++;
			k++;
		}
		info.value[k] = '\0';
		if (question[y+1] >= 'A' && question[y+1] <= 'Z' || question[y+1] >= 'a' && question[y+1] <= 'z')
		{
			info.prefix = question[y];
			info.unit = question[y+1];
		}
		else
		{
			info.prefix = ' ';
			info.unit = question[y];
		}
	}
	else
	{
		printf("\nincorrect Index.\n");
	}
	return info;
}

/*
	Definition:
		printData prints the EData that was inputted.
	Input:
		An EData to be printed to the screen.
	Output:
		The EData will be displayed to the screen.
*/
void printData(EData answerData)
{
	int y;
	char answer[SIZE];
	answer[0] = answerData.concept;
	answer[1] = '=';
	answer[2] = '\0';
	strcat(answer, answerData.value);
	y = strlen(answer);
	if (answerData.prefix != ' ')
	{
		answer[y] = answerData.prefix;
		y++;
	}
	answer[y] = answerData.unit;
	answer[y+1] = '\0';
	printf("%s", answer);
}

/*
	Definition:
		getWattValue returns the number needed to convert it from Mega, kilo, or milli based on the char inputted.	
	Input:
		An char that should be either 'M', 'm', 'k'
	Output:
		Returns the number that is needed 1,000,000.0 for 'M', 0.001 for 'm', 1000 for 'k', otherwise it will return 1.
*/
double getWattValue(char data)
{
	double preValue = 1.0;
	if (data == 'M')
	{
		preValue = 1000000.0;
	}
	else if (data == 'm')
	{
		preValue = 0.001;
	}
	else if (data == 'k')
	{
		preValue = 1000;
	}
	return preValue;
}

/*
	Definition:
		calculateAnswer will take two EData structures, and calculate which forumla it should use.
	Input:
		Two EData structures that will be used to calculate the missing concept.
	Output:
		Will return an EData that will contain the answer.
*/
EData calculateAnswer(EData first, EData second)
{
	EData answer;
	double result;
	double firstValue = atof(first.value) * getWattValue(first.prefix);
	double secondValue = atof(second.value) * getWattValue(second.prefix);
	answer.prefix = ' ';
	
	if (first.concept == 'P' && second.concept == 'I')
	{
		answer.concept = 'U';
		result = (firstValue / secondValue);
		sprintf(answer.value, "%0.2f", result);
		answer.unit = 'V';	
	}
	else if (first.concept == 'I' && second.concept == 'P')
	{
		answer.concept = 'U';
		result = (secondValue / firstValue);
		sprintf(answer.value, "%0.2f", result);
		answer.unit = 'V';
	}
	else if (first.concept == 'U' && second.concept == 'I' || first.concept == 'I' && second.concept == 'U')
	{
		answer.concept = 'P';
		result = firstValue * secondValue;
		sprintf(answer.value, "%0.2f", result);
		answer.unit = 'W';
	}
	else if (first.concept == 'P' && second.concept == 'U')
	{
		answer.concept = 'I';
		result = (firstValue / secondValue);
		sprintf(answer.value, "%0.2f", result);
		answer.unit = 'V';
	}
	else if (first.concept == 'U' && second.concept == 'P')
	{
		answer.concept = 'I';
		result = (secondValue / firstValue);
		sprintf(answer.value, "%0.2f", result);
		answer.unit = 'V';
	}
	return answer;
}
