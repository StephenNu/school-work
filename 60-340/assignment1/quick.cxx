#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;
template <typename T>
void print(T input)
{
	cout << input << " ";
}

template <typename iter>
iter middle(iter first, iter last)
{
	iter slow = first;
	for (iter fast = first; fast != last; slow = next(slow), fast = next(next(fast)))
	{
		if (next(fast) == last)
		{
			return slow;
		}
	}
	return prev(slow);
}

template <typename Biditer>
void quick_sort(Biditer first, Biditer last)
{
	Biditer pivot = middle<Biditer>(first, last);
	if (next(first) != last && first != last)
	{
		iter_swap(first, pivot);
		Biditer bound = partition(next(first), last, [first](typename Biditer::value_type const& value) { return value < *first; });
		iter_swap(first, prev(bound));
		quick_sort<Biditer>(first, prev(bound));
		quick_sort<Biditer>(bound, last);
	}
}




int main()
{
	string input;
	list<string> words;
	while (cin >> input)
	{
		words.push_back(input);
	}
	quick_sort<std::list<string>::iterator>(begin(words), end(words));
	cout << "final value = ";
	for_each(begin(words), end(words), print<string>);
	cout << endl;
	return 0;
}
