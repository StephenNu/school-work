#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define MAX 256
int main (int argc, char* argv[])
{
	char hi;
	int check = 1, fp, fout;
	if (argc != 3)
	{
		printf("usage %s: <input file> <output file>\n", argv[0]);
	}
	else
	{
		fp = open(argv[1], O_RDONLY);
		fout = open(argv[2],O_CREAT | O_WRONLY | O_TRUNC, 0700);
		if (fp == -1 || fout == -1)
		{
			perror("opening problem ");exit(1);
		}
		else
		{
			while (check = read(fp, &hi, 1) > 0)
			{
				if (write(fout, &hi, check) != 1)
				{
					perror("writing problem."); exit(3);
				}
			}
			if (check == -1)
			{
				perror("reading problem."); exit(2);
			}
		}
	}
	exit(0);
}
