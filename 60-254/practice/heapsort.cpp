#include <iostream>
#define MAX 500
void heapsort(int [], int);
void heapify(int [], int);
void swap(int*, int*);
void siftDown(int[], int, int);
void print(int[], int);
int removeMin();
using namespace std;
int hi[10];
int size = 10;
int main(int argc, char* argv[])
{
	hi[0] = 4;
	hi[1] = 3;
	hi[2] = 5;
	hi[3] = 6;
	hi[4] = 7;
	hi[5] = 3;
	hi[6] = 10;
	hi[7] = 4;
	hi[8] = 7;
	hi[9] = 4;
	print(hi, size);
	cout << "min " << removeMin() << endl;
	print(hi, size);
	return 0;
}

int removeMin()
{
	cout << hi[0] << " " << hi[size-1] << " ";
	swap(&hi[0], &hi[size-1]);
	size--;
	return hi[size];
}

void heapsort(int list[], int max)
{
	heapify(list, max);
	int end = max -1;
	while (end > 0)
	{
		swap(&list[end], &list[0]);
		end--;
		siftDown(list, 0, end);
	}
}


void heapify(int list[], int max)
{
	int start = (max -2)/2;
	while (start >= 0)
	{
		siftDown(list, start, max -1);
		start -= 1;
	}
}

void swap (int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void siftDown(int list[], int min, int max)
{
	int root = min;
	while (root * 2 + 1 <= max)
	{
		int child = root * 2 + 1;
		if (child +1 <= max && list[child] >= list[child +1])
		{
			child++;
		}
		if (list [root] >= list[child])
		{
			swap (&list[root], &list[child]);
			root = child;
		}
		else
		{
			return;
		}
	}
}

void print(int l[], int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << l[i] << endl;
	}
}
