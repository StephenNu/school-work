#include <stdio.h>
#include <stdlib.h>
#define MAX 256
void flipImage(FILE *, FILE *);
int getCols(char *);
int getLines(char *);

int main (int argc, char* argv[])
{
	FILE *fin, *fout;
	if (argc == 0)
	{
		exit(9);
	}
	fin = fopen(argv[1], "r");
	if (fin == NULL)
	{
		perror("opening read file");
		exit(1);
	}
	fout = fopen(argv[2], "w");
	if (fout == NULL)
	{
		perror("opening writing file");
		exit(2);
	}
	flipImage(fin, fout);
	exit(0);
}

void flipImage(FILE *fin, FILE *fout)
{
	char temp[MAX], *read;
	int i, nCols, nLines, offset;
	fgets(temp, MAX,  fin);
	fputs(temp, fout);
	fgets(temp, MAX,  fin);
	fputs(temp, fout);
	nCols = getCols(temp);
	nLines = getLines(temp);
	fgets(temp, MAX, fin);
	fputs(temp, fout); 
	offset = nCols;
	read = (char*)malloc (sizeof(char)*(nCols+1));
	fseek(fin, -nCols, SEEK_END);
	for (i = 0; i < nLines; i++)
	{
		fread(read, 1, nCols, fin);
		offset += nCols;
		fseek(fin, -offset, SEEK_END);
		fwrite(read, 1, nCols, fout);
	}
	free(read);
}

int getCols(char *string)
{
	int i, cols = 0;
	char number[MAX];
	for (i = 0; string[i] != ' '; i++)
	{
		number[i] = string[i];
	}
	number[i] = '\0';
	cols = atoi(number);
	return cols;
}

int getLines(char *string)
{
	int i, lines = 0, k = 0;
	char number[MAX];
	for (i = 0; string[i] != ' '; i++);
	while (string[i] != '\0')
	{
		number[k] = string[i];
		++k;
		++i;
	}
	number[k] = '\0';
	lines = atoi(number);
	return lines;
}
