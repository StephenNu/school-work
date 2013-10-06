#include <stdio.h>
#include <math.h>

int main(void) 
{
	int num_d, num_b, decimalnum, quotient, remainder,power2;
	printf("type the decimal number you want to convert to binary:\t");
	scanf("%d", &num_d);
	power2 = 0;
	num_b = 0;
	decimalnum = num_d;
	step5: quotient = num_d/2;
		remainder = num_d % 2;
		num_b = num_b + (remainder * pow(10, power2));
		if (quotient != 0) {
			num_d = quotient;
			power2 = power2 + 1;
			goto step5;
		}
	printf("binary equivalent of %d is %d.\n", decimalnum, num_b);
	return 0;
}

