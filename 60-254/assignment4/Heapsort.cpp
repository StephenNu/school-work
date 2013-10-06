#include <iostream>
#include "heap.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
int heapSort(Heap<int, 100000>*);
void Insertion_sort(int* , int*);
void Quicksort(int*,  int*);
void fill(int[] , int);
void fill(Heap<int, 100000>*, int);
void print(int[], int);
void swap(int*, int*);
using namespace std;
int main(int argc, char *argv[])
{
	Heap<int, 100000> hi;
	int choice = 9, temp, A[100000], B[10], size;
	clock_t start;
	srand(time(NULL));
	while (choice != 0)
	{
		cout << "plase input 1 for inputting\nplease input 2 for random fill\nplease input 0 to exit" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "input 10 numbers: " << endl;
				for (int i = 0; i < 10; i++)
				{
					cin >> temp;
					hi.insert(temp);
				}
				size = heapSort(&hi);
				hi.print(size);
				break;
			}
			case 2:
			{
				start = clock();
				fill(&hi, 100000);
				heapSort(&hi);
				start = clock() - start;
				std::cout << "heapsort time taken: " << (double)start/CLOCKS_PER_SEC << " seconds" << std::endl;
				start = clock();
				fill(A, 100000);
				Insertion_sort(A,A+100000);
				start = clock() - start;
				cout << "insertion sort time taken: " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
				start = clock();
				fill(A, 100000);
				Quicksort(A, A+100000);
				start = clock() - start;
				cout << "quicksort time taken: " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
				start = clock();
				fill(&hi, 10);
				hi.print(10);
				heapSort(&hi);
				hi.print(10);
				start = clock() - start;
				std::cout << "heapsort time taken: " << (double)start/CLOCKS_PER_SEC << " seconds" << std::endl;			
				start = clock();
				fill(B, 10);
				print(B, 10);
				Insertion_sort(B, B+10);
				print(B, 10);
				start = clock() - start;
				cout << "time taken: " << (double)start/CLOCKS_PER_SEC << " seconds"  << endl;
				start = clock();
				fill(B, 10);
				print(B, 10);
				Quicksort(B, B+10);
				print(B, 10);
				start = clock() - start;
				cout << "time taken: " << (double)start/CLOCKS_PER_SEC << " seconds" << endl;
				start = clock();
				break;
			}
			case 0:
			{
				break;
			}
		}
	}
	return 0;
}

int heapSort(Heap<int, 100000>* hi)
{
	int size = hi->size(), i = 0;
	while (hi->size() > 0)
	{
		hi->removeMin();
	}
	hi->reverse(size);
	return size;
}

// n^2 worst
// n best
void Insertion_sort(int* stuff, int* max)
{
	for (int* i = stuff; i <= max; i++)
	{
		for (int* k = i; k > stuff; k--)
		{
			if (*k <= *(k-1))
			{
				swap(k, k-1);
			}
			else
			{
				break;
			}
		}
	}
}
// n^2 worst
// n log n best
void Quicksort(int* min, int* max)
{
	int* pivot = max -1;
	if (min != max)
	{
		int* low;
	        int* high;
		
		for (low = min, high = max-1;
			       	low != high;
			       	++low)
		{
			if (*pivot < *low )
			{
				for (; *high < *pivot; --high);
				swap(low, high);
			}
		}
		swap(low, pivot);
		++high;

		Quicksort(min, low);
		Quicksort(high, max);
	}
}

void fill(int stuff[], int max)
{
	for (int i = 0; i < max; i++)
	{
		stuff[i] = rand() % max + 1;
	}
}

void fill(Heap<int, 100000> *hi, int max)
{
	for (int i = 0; i < max; i++)
	{
		hi->insert(rand() % max + 1);
	}
}

void print(int stuff[], int max)
{
	cout << "start: ";
	for (int i = 0; i < max; i++)
	{
		cout << stuff[i] << " ";
	}
	cout << "end." << endl;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
