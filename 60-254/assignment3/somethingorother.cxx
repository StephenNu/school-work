#include <iostream>
template<class T>
void swap(T* a, T* b)
{
	T swapSpace = *a;
	*a = *b;
	*b = swapSpace;
}	

template<class T>
void quicksort(T* begin, T* end)
{
	if(begin != end)
	{
		T* lowEnd;
		T* highBegin;

		for(lowEnd = begin, highBegin = end - 1; 
			lowEnd != highBegin; 
			++lowEnd)
		{
			if(*(end - 1) < *lowEnd)
			{
				for(; *highBegin < *(end - 1); --highBegin);
		  		swap<T>(lowEnd, highBegin);	
			}
		}
		swap<T>(lowEnd, end - 1);
		++highBegin;

		quicksort(begin, lowEnd);
		quicksort(highBegin, end);
	}
}

int main(int, char*[])
{
	int* numbers = new int[6]{2, 7, 3, 11, 5, 4};

	quicksort<int>(numbers, numbers + 6);

	for(int* i = numbers; i != numbers + 6; ++i)
	{
		std::cout << *i << ' ';
	}
	std::cout << std::endl;

	delete [] numbers;
}
