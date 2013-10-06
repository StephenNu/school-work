#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
void Insertion_sort(int* , int*);
void Quicksort(int*,  int*);
void fill(int[] , int);
void print(int[], int);
void swap(int*, int*);
using namespace std;

int main(int argc, char *argv[])
{
	int A[100000];
	int B[10];
	int choice;
	clock_t start;
	srand(time(NULL));
	cout << "please input 1 for inputing and insertion.\n2 for inputting quicksort.\n3 for random fill and both sort.\n0 to exit\n> ";
	cin >> choice;
	while (choice != 0)
	{
	switch (choice)
	{
		case 1:
		{
			cout << "input up to 10 numbers to sort" << endl;
			for (int i = 0; i < 10; i++)
			{
				cin >> *(B+i);
			}
			start = clock();
			print(B, 10);
			Insertion_sort(B, B+10);
			print(B, 10);
			start = clock() - start;
			cout << "time taken: " << (double)start/CLOCKS_PER_SEC << " seconds"  << endl;
			break;
		}
		case 2:
		{
			cout << "input up to 10 numbers to sort" << endl;
			for (int i = 0; i < 10; i++)
			{
				cin >> *(B+i);
			}
			start = clock();
			print(B, 10);
			Quicksort(B, B+10);
			print(B, 10);
			start = clock() - start;
			cout << "time taken: " << (double)start/CLOCKS_PER_SEC << " seconds"  << endl;
			break;

		}
		case 3:
		{
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
	}
	cout << "please input 1 for inputing and insertion.\n2 for inputting quicksort.\n3 for random fill and both sort.\n0 to exit\n> ";
	cin >> choice;
	}
	return 0;
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
