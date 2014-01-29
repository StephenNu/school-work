#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

// bubble sort all values between first to last
template <typename FwdIter>
void bubble_sort(FwdIter first, FwdIter last)
{
	bool sorted = false;
	while (!sorted)
	{
		// Assume list is sorted until you find evidence otherwise.
		sorted = true;
		for (FwdIter lead = next(first), follow = first; next(lead) != last; lead = next(lead), follow = next(follow))
		{
			if (*follow > *lead)
			{
				iter_swap(follow, lead);
				sorted = false;
			}
		}
	}
}

// print out the inputted value.
template <typename T>
void print(T input)
{
	cout << input << " ";
}

int main()
{
	string input;
	list<string> words;
	// Until an error or EOF read in a string
	while (cin >> input)
	{
		words.push_back(input);
	}
	// bubble_sort with the iterators of the current container.
	bubble_sort<decltype(words)::iterator>(begin(words), end(words));
	// print out all values in the container.
	for_each(begin(words), end(words), print<string>);
	cout << endl;
	return 0;
}
