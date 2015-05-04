#include <iostream>
#include "raii.cxx"
int main()
{
	using namespace std;
	raii<bool> normal{};
	normal[0] = false;
	normal[1] = true;
	cout << "test default set values at [0] and [1] shuld be 0 1 and they are " << normal[0] << " " << normal[1] << endl;
	normal[0] = true;
	normal[1] = false;
	cout << "checked indexing should now be 1 0 they are actaully " << normal[0] << " " << normal[1] << endl;
	raii<bool> copy(normal);

	cout << "copied [0] and [1] elements should be 1 0 they are actually " << copy[0] << " " << copy[1] << endl;
	for (int i = 0; i < 20; ++i)
	{
		cout << copy[i];
	}
	cout << endl;
	raii<bool> move(std::move(raii<bool>()));
	cout <<  "test default set values from move at [0] and [1] shuld be 0 1 and they are actually " << move[0] << " " << move[1] << endl;
	for (int i = 0; i < 20; ++i)
	{
		cout << move[i];
	}
	cout << endl;

	raii<bool> move_assign;
	move_assign = std::move(raii<bool>());
	cout <<  "test default values from move_assign assign should be 0 1 and they are actually " << move_assign[0] << " " << move_assign[1] << endl;
	for (int i = 0; i < 20; ++i)
	{
		cout << move_assign[i];
	}
	cout << endl;

	raii<bool> copy_assign;
	copy_assign = copy;
	cout <<  "test copied value from copy_assign at [0] and [1] should be 1 0 and they are actually " << copy_assign[0] << " " << copy_assign[1] << endl;
	for (int i = 0; i < 20; ++i)
	{
		cout << copy_assign[i];
	}
	cout << endl;

	cout << copy;

	cin >> copy;

	cout << copy;

	cin.setstate(ios_base::badbit);
	cout << ios_base::failbit << " " << ios_base::badbit << " " << ios_base::eofbit << " " << ios_base::goodbit << " " << cin.rdstate()<< endl;
}
