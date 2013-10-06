#include <iostream>
#include "Tree.h"
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	Tree<int> t;
	clock_t start;
	for (int i = 1; i <= 15; i++)
	{
		t.insert(i);
	}
	t.print();
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		t.find(1);
	}
	start = clock() - start;
	cout << "find 1 took on avg " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
	start = clock();
	for (int i = 0; i < 1000000; i++)
	{
		t.find(15);
	}
	start = clock() - start;
	cout << "find 1 took on avg " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
	t.remove(5);
	t.print();
	t.remove(15);
	t.print();
	t.remove(1);
	t.print();
	t.insert(2);
	t.print();
	Tree<int> r;
	r.insert(8);
	r.insert(4);
	r.insert(12);
	r.insert(2);
	r.insert(6);
	r.insert(10);
	r.insert(14);
	r.insert(1);
	r.insert(3);
	r.insert(5);
	r.insert(7);
	r.insert(9);
	r.insert(11);
	r.insert(13);
	r.insert(15);
	r.print();
	start = clock();
	for (int i = 0; i < 10000; i++)
	{
		r.find(1);
	}
	start = clock() - start;
	cout << "find 1 took on avg " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
	start = clock();
	for (int i = 0; i < 10000; i++)
	{
		r.find(15);
	}
	start = clock() - start;
	cout << "find 1 took on avg " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
	r.remove(8);
	r.print();
	return 0;
}
