#include <iostream>
#include "Stack.hpp"
#include <string>
using namespace::std;
Stack <char,200> fun;
bool checkInput(char in);
int main()
{
	string str;
	bool valid = true;
	cout << "please input a string to match" << endl;
	cin >> str;
	for (int i = 0; i < str.length() && valid; i++) // n + 1 time complexity
	{
		valid  = checkInput(str[i]);		// max comparisons in function is 3 called n times so n + 3.
	}
	if (valid && fun.isEmpty())			// constant time
	{
		cout << "valid" << endl;		// constant time.
	}
	else
	{
		cout << "not valid" << endl;
	}
	// Therefore the worst case is 2n + (k) where k is a constant 
	// therefore we have O(n).
	return 0;
}

bool checkInput(char in)
{
	char top = ' ';
	bool check = true;
	if (in == '(' || in == '{' || in == '[')
	{
		fun.push(in);
	}
	else if (in == ')' || in ==  '}' || in == ']') {
		if (fun.isEmpty())
		{
			return false;
		}
		else
		{
			top = fun.pop();
			if (in == ')' && top == '(')
			{
				return true;
			}
			else if (in == '}' && top == '{')
			{
				return true;
			}
			else if (in == ']' && top == '[')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	
	}
	else if (!isdigit(in) && (in != ' ' && in != '/' && in != '+' && in != '-' && in != '*'))
	{
		return false;
	}
	return true;
}
