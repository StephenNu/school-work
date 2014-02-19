#include <iostream>
#include "bool_array.h"

using namespace std;

int main()
{
	  bool_array<234> a;  // default constructed
	    bool_array<234> b = a; // copy constructed
	      bool_array<234> c;
	        c = a; // copy assignment operator
		  cout << c.size() << '\n'; // outputs 234
		    cout << c[12] << '\n'; // outputs false/zero unless you've hacked in a non-zero value in bits_
}
