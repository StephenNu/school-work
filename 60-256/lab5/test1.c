#include <stdio.h>
#include <unistd.h>

int main() 
{
	int i;
	for (i = 1; i <= 3; i++)
	{
		if (fork() != -1)
			printf("Hello");
	}
}
