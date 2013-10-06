// Import the required libraries.
#include <stdio.h>
#include <math.h>

// Declare function prototypes.
int BinaryC(int);
void PrintNum(int, int);
int Complement1(int);

// Start the program to convert decimal numbers to binary numbers using 1s complement for negative numbers, only ending and printing a summery when the user inputs 'N'.
int main(void)
{
	// Declare local main variables.
	char more_to_process = 'Y', junk = ' ';
	int readInput = 0, result = 0, sumPos = 0, sumNeg = 0, sum = 0, numPos = 0, numNeg = 0, num = 0;
	
	// Start the main while loop to check if the user wishes to continue.
	while (more_to_process == 'Y')
	{
		// Prompt for the user to input a number to be converted.
		printf("Enter a number to be converted to binary.\n");
		// Scan the number into the variable readInput.
		scanf("%d", &readInput);
		// If the input is a number greater then zero increment the positive sum, and positive num variables, and call the positive binary convert function.
		if (readInput >= 0)
		{
			result = BinaryC(readInput);
			numPos++;
			sumPos += readInput;
		}
		// If the input is a number less then zero increment the negative sum, and negative num variables, and call the negative binary convert function.
		else
		{
			result = Complement1(readInput);
			numNeg++;
			sumNeg += readInput;
		}
		// Increase num by one and sum by the number inputted.
		num++;			
		sum += readInput;
		// Call the PrintNum with the result of the previous decision.
		PrintNum(readInput, result);
		// Prompt for user input regarding the continuation of the program.
		printf("Any more numbers to be converted?\n"); 
		printf("Please type Y to continue and N if you want to stop \n");
		// Clear the junk from the char reader.
		scanf("%c", &junk);
		// Scan in the input from the user.
		scanf("%c",&more_to_process); 
		// Well the user hasn't provided a correct input continue to ask.
		while ((more_to_process != 'Y') && (more_to_process != 'N')) 
		{ 
			/* Discard the end of line character or other characters */
			printf("Please type Y to continue and N if you want to stop \n");
			scanf("%c", &junk);  
			scanf("%c",&more_to_process);	 
		}
	}
	/* Once the user is done inputing numbers. Print a summery of the amount of numbers, negative, positive, and total inputed,
	as well as the sum of negative, positive, and total along with the binary number for each. */
	printf("\nNumber of positive numbers processed = %d   and  %.8d in binary\n", numPos, BinaryC(numPos));
	printf("Number of negative numbers processed = %d  and  %.8d in binary\n", numNeg, BinaryC(numNeg)); 
	printf("Number of all numbers processed = %d and   %.8d  in binary\n", num, BinaryC(num));
	printf("Sum of positive numbers processed = %d and  %.8d   in binary\n", sumPos, BinaryC(sumPos)); 
	// If the sumNeg was never updated use the positive binary convert function.
	if (sumNeg >= 0)
	{
		printf("Sum of negative numbers processed = %d and %.8d in binary\n",sumNeg, BinaryC(sumNeg));
	}	
	// If sumNeg was updated it should be a negative number so call the negative binary convert.
	else
	{
		printf("Sum of negative numbers processed = %d and %.8d in binary\n",sumNeg, Complement1(sumNeg));
	}
	// If the grand total sum is positive call the positive binary convert.
	if (sum >= 0)
	{
		printf("Sum of all numbers processed = %d and %.8d  in binary\n", sum, BinaryC(sum));
	}
	// If the grand total sum is negative call the negative binary convert.
	else
	{
		printf("Sum of all numbers processed = %d and %.8d  in binary\n", sum, Complement1(sum));
	}
	// Print a thank you.
	printf("\nThank You for Using our Binary Conversion Software !!!\n");
	// End the program.
	return 0;
}

// The function BinaryC takes a positive decimal number and converts it to binary
int BinaryC(int num_d) 
{
	// Declare function variables.
	int num_b, quotient, remainder,power2;
	// Set starting values.
	power2 = 0;
	num_b = 0;
	// find the quotient and remainder adding the correct number to binary number variable and cicle through the number until the quotient does not equal 0.
	do 
	{
		quotient = num_d/2;
		remainder = num_d % 2;
		num_b = num_b + (remainder * pow(10, power2));
		num_d = quotient;
		power2 = power2 + 1;
	} while (quotient != 0);
	// Return the finished binary number.
	return num_b;
}

// The function PrintNum is used to print both the decimal number to be converted and the resulting binary number.
void PrintNum(int decimal, int binary)
{
	printf("\nNumber	Binary\n");
	printf("%d	%.8d\n\n", decimal, binary);
}

// The function Complement1 takes a negative number switches it to positive to convert to binary, and then switches all zeros to 1s and all 1s to 0s in the bianry number.
int Complement1(int decimal)
{
	// Declare and set starting values.
	int binary = 0, negBinary = 0, i;
	// Switch the inputted negative number to positive and call the BinaryC function.
	binary = BinaryC((decimal*-1));
	// While the fullsize variable is not the full size of the binary number or is not the full 8 bits a binary number should be continue to add a 1 to each increasing digit space.
	for (i = 1; negBinary < binary || i < 11111111; i *= 10)
	{
		if (binary % 2 == 0)
		{
			negBinary += i*1;
		}
		binary *= .10;
	}
	// Return the number inputted in 1s complement.
	return negBinary;
}


