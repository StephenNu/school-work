#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <cmath>
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
	for (iter fast = first; fast != last; advance(slow, 1), advance(fast, 2))
	{
		if (next(fast) == last)
		{
			return slow;
		}
	}
	return prev(slow);
}


// Quick sort all values between first and last. (assumes they will cross).
template <typename BidiIter>
void quick_sort(BidiIter first, BidiIter last)
{
	if (next(first) != last && first != last)
	{
		// Set the middle element as the pivot.
		BidiIter pivot = middle<BidiIter>(first, last);
		// Put the pivot out of the way of the partition.
		iter_swap(first, pivot);
		// Parition from first + 1 to last, around the value at first.
		BidiIter bound = partition(next(first), last, [first](typename BidiIter::value_type const& value) { return value < *first; });
		// Put the pivot back to the location it should go.
		iter_swap(first, prev(bound));
		// quick_sort the lower half.
		quick_sort<BidiIter>(first, prev(bound));
		// quick_sort the upper half.
		quick_sort<BidiIter>(bound, last);
	}
}




int main()
{
	string input;
	list<decltype(input)> words;
	// Until an error or EOF read in a string
	while (cin >> input)
	{
		words.push_front(input);
	}
	// bubble_sort with the iterators of the current container.
	quick_sort<decltype(words)::iterator>(begin(words), end(words));
	// print out all values in the container.
	for_each(begin(words), end(words), print<decltype(input)>);
	cout << endl;
	return 0;
}
