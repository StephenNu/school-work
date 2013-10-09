#include <iostream>
#include <string.h>
#include <ctype.h>
#define MAX 500
using namespace std;
/*
	converts a sentence into pig latin.
*/
// if vowel start add ay to end
// if constant place at end add ay
void spacekittens(char str[]);
void swap(char*, char*);
int main()
{
	char sent[MAX], *token, final[MAX], inter[MAX];
	final[0] = '\0';
	cin.getline(sent, MAX);
	token = strtok(sent, " ,.?:;");
	while (token != NULL)
	{
		strcpy(inter, token);
		spacekittens(inter);
		strcat(final, inter);
		strcat(final, " ");
		token = strtok(NULL, " ,.?:;");
	}	
	cout << "final = " <<  final << endl;
	return 0;
}

void swap(char *a, char* b)
{
	char c = *a;
	*a = *b;
	*b = c;
}

void spacekittens(char str[])
{
	char *i;
	bool changed = false;
	if (*str == 'e' || *str == 'i' || *str == 'a' || *str == 'o' )
	{
		strcat(str, "ay");
	}
	else
	{
		if (isupper(*str))
		{
			*str = tolower(*str);
			changed = true;
		}
		for (i = str+1; *i != '\0'; i++)
		{
			swap(i, i-1);
		}
		strcat(str, "ay");
		if (changed)
		{
			*str = toupper(*str);
		}
	}	
}
