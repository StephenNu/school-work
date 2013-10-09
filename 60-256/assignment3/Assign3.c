#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 500
void itoa (int, char*);
int length(char*);
void swap (char*, char*);
int main()
{
	int m, k, i = 0, sum = 0;
	char b, t_char[MAX];
	double avg = 0.0;
	long int check;

	int fpout = open("output.dat", O_CREAT | O_RDWR | O_TRUNC, 0700);
	int fp = open("input.dat", O_RDONLY);
	if (fpout == -1 || fp == -1)
	{
		perror("file opening error "); exit(1);
	}
	else
	{
		while ((check = read(fp, &b, 1)) > 0 && b != ' ')
		{
			t_char[i++] = b;
		}
		if (check == -1)
		{
			perror("reading problem "); exit(2);
		}
		t_char[i] = '\n';
		m = atoi(t_char);
		i = 0;
		while ((check = read(fp, &b, 1)) > 0 && b != '\n')
		{
			t_char[i++] = b;
		}
		if (check == -1)
		{
			perror("reading problem "); exit(2);
		}
		t_char[i] = '\n';
		for (k = 0; k < m; k++)
		{
			int pid = fork();
			char average[MAX];
			if (pid == 0)
			{
				sum = 0;
				b = ' ';
				i = 0;
				while (b != '\n')
				{
					read(fp, &b, 1);
					if (b == ' ' || b == '\n')
					{
						t_char[i] = '\n';
						i = 0;
						sum += atoi(t_char);
					}
					else
					{
						t_char[i++] = b;
					}
				}
				printf("Child %d Sum = %d\n", k+1, sum);
				itoa(sum, average);
				if (write(fpout, average, length(average)) != length(average))
				{
					perror("writing problem "); exit(3);	
				} 
				exit(0);
			}
			else if (pid == -1)
			{
				printf("unable to fork.\n");
			}
			else
			{
				wait();
			}
		}
		lseek(fpout, SEEK_SET, 0);
		i = 0;
		while ((check = read(fpout, &b, 1)) > 0)
		{
			if (b == '\n')
			{
				t_char[i] = b;
				avg += (double)atoi(t_char);
				i = 0;
			}
			else
			{
				t_char[i++] = b;
			}
		}
		printf("Parent Average = %0.2lf\n", avg/m);
	}
	return 0;
}

int length(char *str)
{
	int count;
	for (count = 0; *(str + count) != '\n'; ++count);
	return ++count;
}

void itoa(int i, char* input)
{
	int k = 10;
	char *str = input, *back;
	while (i != 0)
	{
		*str = (char)(((int)'0')+ i%k);
		back = str;
		while (back != input)
		{
			swap (back, back-1);
			--back;
		}
		i /= k;
		str++;
	}
	*str = '\n';
}

void swap (char* a, char *b)
{
	char c = *a;
	*a = *b;
	*b = c;
}
