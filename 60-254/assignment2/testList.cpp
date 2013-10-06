#include <iostream>
#include "LinkedList.h"
using namespace std;

int main ()
{
	LinkedList<int> work;
	work.push_front(2);
	work.push_back(4);
	cout << work.front() << " " << work.back() << endl;
	work.pop_front();
	cout << work.front() << " " << work.back() << endl;
	work.push_front(6);
	work.pop_back();
	cout << work.front() << " " << work.back() << endl;
	work.replace(work.front(), 7);
	cout << work.front() << " " << work.back() << endl;
	work.push_front(8);
	work.push_front(9);
	LinkedNodeIterator<int> position = work.begin();
	++position;
	cout << work.front()  <<  " "  << *position << " " << work.back() << endl;
	work.remove(position);
	position = work.begin();
	++position;
	cout << work.front() << " " << *position << " " << work.back() << endl;
	work[1] = 2;
	cout << "hi" << work[1] << endl;
	return 0;
}
