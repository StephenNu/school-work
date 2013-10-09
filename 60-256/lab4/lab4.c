#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200
void reverse(FILE *, FILE *);
long findNewLine(FILE *, long start);
int main (int argc, char* argv[])
{
	FILE *f1, *f2;
	if (argc == 0)
	{
		exit(9);
	}
	f1 = fopen(argv[1], "r");
	if (f1 == NULL)
	{
		perror("opening file 1");
		exit(1);
	}
	f2 = fopen(argv[2], "w");
	if (f1 == NULL)
	{
		perror("opening file 2");
		exit(2);
	}
	reverse(f1, f2);
	exit(0);
}

void reverse(FILE *f1, FILE *f2)
{
	char in[MAX_SIZE];
	long i = findNewLine(f1, -2);
	while (i != SEEK_SET)
	{
		fseek(f1, i, SEEK_END);
		fgets(in, MAX_SIZE, f1);
		fputs(in, f2);
		i = findNewLine(f1, i-2);
	}
	fseek(f1, 0, SEEK_SET);
	fgets(in, MAX_SIZE, f1);
	fputs(in, f2);
	fflush(f2);
}

long findNewLine(FILE *f1, long i)
{
	char check;
	fseek(f1, i, SEEK_END);
	fread(&check, 1, 1, f1);
	while (check != '\n')
	{	
		if (ftell(f1) == 1)
		{
			return SEEK_SET;
		}
		fseek(f1, --i, SEEK_END);
		fread(&check, 1, 1, f1);
	}
	return ++i;
}
