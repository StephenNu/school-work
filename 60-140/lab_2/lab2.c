#include      <stdio.h>
int main(void)
{
    // Input data variables:  
	int digit1, digit2; 
  
   // Output data variable are: 
	int final_digit, thousand_digit, hundred_digit, tens_digit, ones_digit; 
	char number_string[4] = "";
 
	// Prompt and read the input of two 4 digit numbers.
	printf("Please enter a 4 digit number\n");
	scanf("%d", &digit1);
	printf("Please enter a second 4 digit number\n");
	scanf("%d", &digit2);
	/* 
		Take the remainder of the each number divided by ten then divided it by 2.
		Next divide the original numbers by 10 and repeat the process storing in order first the digit in the ones, then tens, hundred, finally thousands.
	*/
	ones_digit      =      (digit1%10 +digit2%10)/2;
	digit1                =      digit1/10;
	digit2                =      digit2/10;
	tens_digit      =      (digit1%10 +digit2%10)/2;
	digit1                =      digit1/10;
	digit2                =      digit2/10;
	hundred_digit   =      (digit1%10 +digit2%10)/2;
	digit1                =      digit1/10;
	digit2                =      digit2/10;
	thousand_digit  =      (digit1%10 +digit2%10)/2;
	digit1                =      digit1/10;
	digit2                =      digit2/10;
	// Add all the results into a single new number times each digit by their corresponding place, and proceed to print the results.
	final_digit = (thousand_digit * 1000) + (hundred_digit * 100) + (tens_digit * 10) + ones_digit;
	printf("Adding each digit together then dividing it by 2, and making a new number resulted in %d.\n", final_digit);
	return   0;
}
