#include <iostream>
#include "systemtree.h"
int main()
{
	Tree<int> r;
	r.insert(8);
	r.insert(4);
	r.insert(6);
	r.insert(9);
	r.insert(16);
	r.insert(10);
	r.insert(12);
	r.insert(11);
	r.insert(13);
	r.insert(5);
	r.insert(7);
	std::cout << "left:";
	r.print_op(1);
	std::cout << "right:";
	r.print_op(0);

	return 0;
}
