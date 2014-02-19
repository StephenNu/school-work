#include <iostream>
#include "bool_array.h"

using namespace std;


int main()
{
	using namespace std;

	bool_array<13> test;

	std::cout << "The following is the default constructor and should be all zeros." << std::endl;
	for (unsigned i=0; i != 13; ++i)
		std::cout << i << ": " << test[i] << '\n';

	std::cout << "The following outputs the current value then sets to true, and outputs the result" << std::endl
		<< "it then prints all the bools to ensure no values where changed by mistake" << std::endl;
	for (unsigned i=0; i != 13; ++i)
	{
		std::cout << i << ": " << test[i] << "; ";
		test[i] = true;
		std::cout << test[i] << '\n';
		for (unsigned k=0; k != 13; std::cout << test[k] << " ", ++k);
		std::cout << std::endl;
	}
	if (test[4])
	{
		std::cout << "The 4th bool is true, as it should be" << std::endl;
	}
	else
	{
		std::cout << "The 4th bool is false, and it shouldn't be" << std::endl;
	}

	std::cout << "The following outputs the current value then sets to false, and outputs the result" << std::endl
		<< "it then prints all the bools to ensure no values where changed by mistake" << std::endl;
	for (unsigned i=0; i != 13; ++i)
	{
		std::cout << i << ": " << test[i] << "; ";
		test[i] = false;
		std::cout << test[i] << '\n';
		for (unsigned k=0; k != 13; std::cout << test[k] << " ", ++k);
		std::cout << std::endl;

	}
	if (test[4])
	{
		std::cout << "The 4th bool is true, and it shouldn't be" << std::endl;
	}
	else
	{
		std::cout << "The 4th bool is false, as it should be" << std::endl;
	}

	std::cout << "\n\n";
}
