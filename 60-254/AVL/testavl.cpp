#include <iostream>
#include "Tree.h"

int main()
{
	Tree<int> a;
	a.insert(4);
	a.insert(3);
	a.insert(2);
	a.insert(1);
	a.print();
	return 0;
}
