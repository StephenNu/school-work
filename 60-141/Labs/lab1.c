/* 
	Nusko, Stephen
	ID: 103693282
	Lab Exercise # 2
	Date: Jan 10th 1012
	Purpose: Create a program with one main that solves 8 different problems once using recursive and once with a non-recursive method.
	Also allowing these functions to be called by an interactive menu.
*/
#include <stdio.h>

/* function prototypes */
int sum(int n);				// Gathers the sum of n + all the numbers below it to 0.
int sumR(int n);			// Gathers the sum of n + all the numbers below it to 0.
int sum2(int n);			// Gathers the sum of sq(n +1) + the sq of all numbers below (n + 1) and returns.
int sum2R(int n);			// Gathers the sum of sq(n +1) + the sq of all numbers below (n + 1) and returns.
int fib(int n);				// fib(n): Returns the nth Fibonacci number.
int fibR(int n);			// fib(n): Returns the nth Fibonacci number.
int gcdR(int x, int y);			// Returns the greatest common denominator of the of the two integers entered.
int gcd(int x, int y);			// Returns the greatest common denominator of the of the two integers entered.
int power(int a, int b);		// Returns a raised to the power of b.
int powerR(int a, int b);		// Returns a raised to the power of b.
void print(int n);			// Prints out the numbers starting from n and decreasing and stoping at 1.
void printR(int n);			// Prints out the numbers starting from n and decreasing and stoping at 1.
void drawTriangle(int n);		// Prints out a triangle of *s starting at the top with length n and decreasing each step down before stoping at 0.
void drawTriangleR(int n);		// Prints out a triangle of *s starting at the top with length n and decreasing each step down before stoping at 0.
void drawTriangle2(int n);		// Prints out a triangle of *s starting at the top with length 1 and decreasing each step down before stoping at n.
void drawTriangle2R(int n);		// Prints out a triangle of *s starting at the top with length 1 and decreasing each step down before stoping at n.

/* Main Program Routine */
int main(void)
{
	int choice = 0;			// Variable to store the user's choice
	do 
	{
		// Display the menu choices to the user, and prompt for input.
		printf("1) use sum(n) with loops function\n");
		printf("2) use sumR(n) with recursive function\n");
		printf("3) use sum2(n) with loops function\n");
		printf("4) use sum2R(n) with recursive function\n");
		printf("5) use fib(n) with loops function\n");
		printf("6) use fibR(n) with recursive function\n");
		printf("7) use gcd(x, y) with loops function\n");
		printf("8) use gcdR(x, y) with recursive function\n");
		printf("9) use power(a, b) with loops function\n");
		printf("10) use powerR(a, b) with recursive function\n");
		printf("11) use print(n) with loops function\n");
		printf("12) use printR(n) with recursive function\n");
		printf("13) use drawTriangle(n) with loops function\n");
		printf("14) use drawTriangleR(n) with recursive function\n");
		printf("15) drawTriangle2(n) with loops function\n");
		printf("16) drawTriangle2R(n) with recursive function\n");
		printf("Please input the desired function's number, 0 if you no longer wish to continue\n");
		// Read user input.
		scanf("%d", &choice);
		// Check which number was inputted.
		switch (choice)
		{
		case 1:
		{
			// Gather the required information and call sum(n).
			int n, result;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			result = sum(n);
			printf("Result is %d\n", result);
			break;
		}
		case 2:
		{
			// Gather the required information and call sumR(n).
			int n, result;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			result = sumR(n);
			printf("Result is %d\n", result);
			break;
		}
		case 3:
		{
			// Gather the required information and call sum2(n).
			int n, result;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			result = sum2(n);
			printf("Result is %d\n", result);
			break;
		}
		case 4:
		{
			// Gather the required information and call sum2R(n).
			int n, result;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			result = sum2R(n);
			printf("Result is %d\n", result);
			break;
		}
		case 5:
		{
			// Gather the required information and call fib(n).
			int n, result;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			result = fib(n);
			printf("Result is %d\n", result);
			break;
		}
		case 6:
		{
			// Gather the required information and call fibR(n).
			int n, result;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			result = fibR(n);
			printf("Result is %d\n", result);
			break;
		}
		case 7: 
		{
			// Gather the required information and call gcd(x, y).
			int x, y, result;
			printf("Please input x and then y as positive integers\n");
			scanf("%d %d", &x, &y);
			result = gcd(x, y);
			printf("Result is %d\n", result);
			break;
		}
		case 8: 
		{
			// Gather the required information and call gcdR(x, y).
			int x, y, result;
			printf("Please input x and then y as positive integers\n");
			scanf("%d %d", &x, &y);
			result = gcdR(x, y);
			printf("Result is %d\n", result);
			break;
		}
		case 9:
		{
			// Gather the required information and call power(a, b).
			int x, y, result;
			printf("Please input a and then b as positive integers\n");
			scanf("%d %d", &x, &y);
			result = power(x, y);
			printf("Result is %d\n", result);
			break;
		}
		case 10:
		{
			// Gather the required information and call powerR(a, b).
			int x, y, result;
			printf("Please input a and then b as positive integers\n");
			scanf("%d %d", &x, &y);
			result = powerR(x, y);
			printf("Result is %d\n", result);
			break;
		}
		case 11:
		{
			// Gather the required information and call print(n).
			int n;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			print(n);
			break;
		}
		case 12:
		{
			// Gather the required information and call printR(n).
			int n;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			printR(n);
			break;
		}
		case 13:
		{
			// Gather the required information and call drawTriangle(n).
			int n;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			drawTriangle(n);
			break;
		}
		case 14:
		{
			// Gather the required information and call drawTriangleR(n).
			int n;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			drawTriangleR(n);
			break;
		}
		case 15:
		{
			// Gather the required information and call drawTriangle2(n).
			int n;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			drawTriangle2(n);
			break;
		}
		case 16:
		{
			// Gather the required information and call drawTriangle2R(n).
			int n;
			printf("Please input the value of n as a positive integer\n");
			scanf("%d", &n);
			drawTriangle2R(n);
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
	definition
		Sum(n): gathers the sum of n + all the numbers below it to 0.
	input
		A positive integer that is 1 or higher, and n must be 
		small enough so that the return value is still an int.
	output
		will return the sum of n plus all numbers below. (example: 1 + 2 + 3 .... + n)
*/
int sum(int n)
{
	int total = 0, i;
	for (i = 1; i <= n; i++)
	{
		total += i;
	}
	return total;
}
/*
	definition
		(Recursive) SumR(n): gathers the sum of n + all the numbers below it to 0.
	input
		A positive integer that is 1 or higher, and n must be 
		small enough so that the return value is still an int.
	output
		will return the sum of n plus all numbers below. (example: 1 + 2 + 3 .... + n)
*/
int sumR(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + sumR(n-1);
	}
}
/*
	definition
		Sum2(n): gathers the sum of sq(n +1) + the sq of all numbers below (n + 1) and returns.
	input
		A positive integer that is 1 or higher, and n must be 
		small enough so that the return value is still an int.
	output
		will return the sum of sq(n + 1) plus the the square of all numbers below + 1. (example: sq(1 + 1) + sq(2 + 1) .... + sq(n + 1))
*/
int sum2(int n)
{
	int total = 0, i;
	for (i = 1; i <= n; i++)
	{
		total += (i + 1) * (i + 1);
	}
	return total;
}
/*
	definition
		(Recursive) Sum2R(n): gathers the sum of sq(n +1) + the sq of all numbers below (n + 1) and returns.
	input
		A positive integer that is 1 or higher, and n must be 
		small enough so that the return value is still an int.
	output
		will return the sum of sq(n + 1) plus the the square of all numbers below + 1. (example: sq(1 + 1) + sq(2 + 1) .... + sq(n + 1))
*/
int sum2R(int n)
{
	if (n == 1)
	{
		return (1 + 1) * (1 + 1);
	}
	else
	{
		return (((n + 1) * (n + 1)) + sum2R(n-1));
	}
}
/*
	definition
		fib(n): Returns the nth Fibonacci number.
	input
		A positive integer that is 1 or higher, and n must be 
		small enough so that the return value is still an int.
	output
		Will return the nth Fibonacci number which is determined by adding the last two Fibonacci numbers together.
		(example: the 2nd Fibonacci number is made by adding 0 + 1)
*/
int fib(int n)
{
	int i, k = 0, j = 1, fib = 1;
	for (i = 1; i < n; i++)
	{
		fib = k + j;
		k = j;
 		j = fib;
	}
	return fib;
}
/*
	definition
		(recursive) fibR(n): Returns the nth Fibonacci number.
	input
		A positive integer that is 1 or higher, and n must be 
		small enough so that the return value is still an int.
	output
		Will return the nth Fibonacci number which is determined by adding the last two Fibonacci numbers together.
		(example: the 2nd Fibonacci number is made by adding 0 + 1)
*/
int fibR(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if(n == 0)
	{
		return 0;
	}
	else
	{
		return fibR(n-1) + fibR(n-2);
	}
}
/*
	definition
		gcd(x, y): Returns the greatest common denominator of the of the two integers entered.
	input
		Two positive integer that are 1 or higher, and they must be 
		small enough so that the return value is still an int.
	output
		Will return the greatest common denominator of the of the two integers entered.
*/
int gcd(int x, int y)
{
	int temp;
	while (y > 0)
	{	
		temp = x;	
		x = y;
		y = temp%y;
	}	
	return x;
}
/*
	definition
		(recursive) gcdR(x, y): Returns the greatest common denominator of the of the two integers entered.
	input
		Two positive integer that are 1 or higher, and they must be 
		small enough so that the return value is still an int.
	output
		Will return the greatest common denominator of the of the two integers entered.
*/
int gcdR(int x, int y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return gcdR(y, x%y);
	}
}
/*
	definition
		powerR(a, b): Returns a raised to the power of b.
	input
		Two positive integer that are 1 or higher, and they must be 
		small enough so that the return value is still an int.
	output
		Will return a raised to the power of b. (example a = 2, b = 3: a*a*a = 8)
*/
int power(int a, int b)
{
	int power = 1, i;
	for (i = 0; i < b; i++)
	{
		power *= a;
	}
	return power;
}
/*
	definition
		(recursive) powerR(a, b): Returns a raised to the power of b.
	input
		Two positive integer that are 1 or higher, and they must be 
		small enough so that the return value is still an int.
	output
		Will return a raised to the power of b. (example a = 2, b = 3: a*a*a = 8)
*/
int powerR(int a, int b)
{
	if (b == 1)
	{
		return a;
	}
	else
	{
		return a*powerR(a, b-1);
	}
}
/*
	definition
		printR(n): Prints out the numbers starting from n and decreasing and stoping at 1.
	input
		A positive integer that is 1 or higher, and n must be small enough to be an int.
	output
		Will print out the numbers starting from n and decreasing and stoping at 1. 
		(example n = 5: 5 4 3 2 1)
*/
void print(int n)
{
	int i;
	for (i = n; i > 0; i--)
	{
		printf("%d ", i);
	}
	printf("\n");
}
/*
	definition
		(recursive) printR(n): Prints out the numbers starting from n and decreasing and stoping at 1.
	input
		A positive integer that is 1 or higher, and n must be small enough to be an int.
	output
		Will print out the numbers starting from n and decreasing and stoping at 1. 
		(example n = 5: 5 4 3 2 1)
*/
void printR(int n)
{
	if (n == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("%d ", n);
		printR(n-1);
	}
}
/*
	definition
		drawTriangle(n): Prints out a triangle of * starting at the top 
		with length n and decreasing each step down before stoping at 0.
	input
		A positive integer that is 1 or higher, and n must be small enough to be an int.
	output
		Prints out a triangle of *s starting at the top 
		with length n and decreasing each step down before stoping at 0.
		(example n = 4:		
			****
			***
			**
			*
		)
*/
void drawTriangle(int n)
{
	int i;
	for (; n > 0; n--)
	{
		for (i = n; i > 0; i--)
		{
			printf("*");
		}	
		printf("\n");
	}
}
/*
	definition
		(recursive) drawTriangleR(n): Prints out a triangle of *s starting at the top 
		with length n and decreasing each step down before stoping at 0.
	input
		A positive integer that is 1 or higher, and n must be small enough to be an int.
	output
		Prints out a triangle of *s starting at the top 
		with length n and decreasing each step down before stoping at 0.
		(example n = 4:		
			****
			***
			**
			*
		)
*/
void drawTriangleR(int n)
{
	int i;
	if (n < 1)
	{
		return;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");
		drawTriangleR(n-1);
	}	
}
/*
	definition
		drawTriangle2(n): Prints out a triangle of *s starting at the top 
		with length 1 and increasing each step down before stoping at n.
	input
		A positive integer that is 1 or higher, and n must be small enough to be an int.
	output
		Prints out a triangle of *s starting at the top 
		with length n and decreasing each step down before stoping at 0.
		(example n = 4:		
			*
			**
			***
			****
		)
*/
void drawTriangle2(int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
/*
	definition
		(recursive) drawTriangle2R(n): Prints out a triangle of *s starting at the top 
		with length 1 and increasing each step down before stoping at n.
	input
		A positive integer that is 1 or higher, and n must be small enough to be an int.
	output
		Prints out a triangle of *s starting at the top 
		with length n and decreasing each step down before stoping at 0.
		(example n = 4:		
			*
			**
			***
			****
		)
*/
void drawTriangle2R(int n)
{
	int i;
	if (n == 1)
	{
		printf("*\n");
		return;
	}
	else
	{
		drawTriangle2R(n-1);
		for (i = 0; i < n; i++)
		{
			printf("*");
		}
		printf("\n");
	}	
}


