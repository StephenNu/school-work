#include <stdio.h>			// Import the libraries.

int main()					// Start the program/.
{
	int a = 7; // an int equal to 7
	int *aPtr; // a pointer to an int.
	aPtr = &a; // set the point to the location of a (7)
	printf("%p\n", &a); // prints the memory address of a
	printf("%p\n", aPtr); // prints the memory address of a that was stored in the pointer.
	printf("%p\n", &aPtr); // prints the memory address of the pointer.
	printf("%d\n", a); // prints the value (7) stored in a
	printf("%d\n", *aPtr); // prints the value (7) stored in the in the pointer int.
	printf("%p\n", *&aPtr); // prints the memory address of the location the pointer points too (a).
	printf("%p\n", &*aPtr); //Prints the memory address of the location the pointer points too (a).
	printf("%d\n", *&a); // prints the value (7) stored in a
	//printf("%d", &*a); // You can't get the value a points to first, since it already is that, and then get the address.
	return 0;			// Return 0.
}