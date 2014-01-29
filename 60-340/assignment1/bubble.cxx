#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

template <typename FwdIter>
void bubble_sort(FwdIter first, FwdIter last)
{
	bool sorted = false;
	while (!sorted)
	{
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


template <typename T>
void print(T input)
{
	cout << input << " ";
}

int main()
{
	string input;
	list<string> words;
	while (cin >> input)
	{
		words.push_back(input);
	}
	bubble_sort<std::list<string>::iterator>(begin(words), end(words));
	for_each(begin(words), end(words), print<string>);
	cout << endl;
	return 0;
}
