#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

// print out the inputted value.
template <typename T>
void print(T input)
{
	cout << input << " ";
}

// Find the middle between iterator first and last. (assumes they will cross).
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


// Quick sort all values between first and last. (assumes they will cross).
template <typename Biditer>
void quick_sort(Biditer first, Biditer last)
{
	if (next(first) != last && first != last)
	{
		// Set the middle element as the pivot.
		Biditer pivot = middle<Biditer>(first, last);
		// Put the pivot out of the way of the partition.
		iter_swap(first, pivot);
		// Parition from first + 1 to last, around the value at first.
		Biditer bound = partition(next(first), last, [first](typename Biditer::value_type const& value) { return value < *first; });
		// Put the pivot back to the location it should go.
		iter_swap(first, prev(bound));
		// quick_sort the lower half.
		quick_sort<Biditer>(first, prev(bound));
		// quick_sort the upper half.
		quick_sort<Biditer>(bound, last);
	}
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
	quick_sort<decltype(words)::iterator>(begin(words), end(words));
	// print out all values in the container.
	for_each(begin(words), end(words), print<string>);
	cout << endl;
	return 0;
}
