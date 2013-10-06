#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char * myfgets(FILE *fp)
{
	char ch;
	long leng;
	int i = 0;
	while (fread(&ch,(sizeof(char)),1, fp) == 1)
	{
		printf(":%c", ch);
		if (ch == '\n')
		{
			break;
		}
	}
	leng = ftell(fp);
	rewind(fp);
	char *hi = (char*)malloc(sizeof(char)*(leng+1));
	while (fread(&ch,sizeof(char), 1, fp) == 1)
	{
		if (ch == '\n')
		{
			hi[i] = '\0';
			break;
		}
		else
		{
			hi[i++] = ch;
		}	
	}
	return hi;
}

int main(int argc, char *argv[])
{
	FILE *fp = fopen("test.dat", "r");
	char *no = myfgets(fp);
	printf("%s", no);
	free(no);
	return 0;
}
