#include <iostream>
#include "Queue.h"
using namespace std;
Queue<int> stuff;
int main ()
{
	int check = 1, input;
	while (check)
	{
		cout << "please input 1 to enqueue another input" << endl;
		cout << "please input 2 to dequeue all elements" << endl;
		cout << "please input 0 to exit :";
		cin >> check;
		switch (check)
		{
			case 1:
			{
				cout << "enter the number to enqueue :";
				cin >> input;
				stuff.enqueue(input);		
				break;
			}
			case 2:
			{
				while (!stuff.empty())
				{
					cout << stuff.front() << endl;
					stuff.dequeue();
				}
				cout << "the queue is now empty." << endl;
				break;
			}
			case 0:
			{
				cout << "good-bye" << endl;
				break;	
			}
		}
	}
	return 0;
}
