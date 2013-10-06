template <class T, std::size_t N = 500>
class Heap 
{
private:
	T _heap[N];
	T _root;
	int _size;
public:
	Heap ();

	void siftDown(int, int);
	void insert(T);
	int removeMin();
	void heapify(int);
	const int size() const;
	const bool isEmpty() const;
	void swap (T*, T*);
	void heapsort();
	void print(int);
	void reverse(int);
	void upHeap();
	void downHeap();
};

template <class T, std::size_t N>
Heap<T,N>::Heap()
	: _root(), _size(0)
{
}
template <class T, std::size_t N>
void Heap<T,N>::siftDown(int min, int max)
{
	int root = min;
	while (root * 2 + 1 <= max)
	{
		int child = root * 2 + 1;
		if (child + 1 <= max && this->_heap[child] >= this->_heap[child + 1])
		{
			++child;
		}
		if (this->_heap[root] >= this->_heap[child])
		{
			swap(&this->_heap[root], &this->_heap[child]);
			root = child;
		}
		else
		{
			return;
		}
	}
}
template <class T, std::size_t N>
void Heap<T,N>::swap(T* a, T* b)
{
	T c = *a;
	*a = *b;
	*b = c;
}
template <class T, std::size_t N>
void Heap<T,N>::upHeap()
{
	T parent = this->_size/2 - 1;
	T newEle = this->_size-1;
	while (parent >= 0)
	{
		if (this->_heap[parent] >=  this->_heap[newEle])
		{
			swap(&this->_heap[parent], &this->_heap[newEle]);
			newEle = parent;
			parent = parent/2 - 1;
			if (parent < 0 && newEle == 1)
				parent = 0;
		}
		else
		{
			return;
		}
	}
}
template <class T, std::size_t N>
void Heap<T,N>::downHeap()
{
	int root = 0;
	while (root * 2 + 1 < this->_size)
	{
		int child = root * 2 + 1;
		if (child + 1 < this->_size && this->_heap[child+1] < this->_heap[child])
		{
			++child;
		}
		if (this->_heap[child] < this->_heap[root])
		{
			swap(&this->_heap[root], &this->_heap[child]);
			root = child;
		}
		else
		{
			return;
		}
	}
}
template <class T, std::size_t N>
void Heap<T,N>::insert(T element)
{
	this->_heap[this->_size++] = element;
	if (this->_size > 1)
		this->upHeap();
}
template <class T, std::size_t N>
void Heap<T,N>::heapify(int max)
{
	int start = (max - 2)/2;
	while (start >= 0)
	{
		siftDown(start, max - 1);
		start -= 1;
	}
}
template <class T, std::size_t N>
int Heap<T,N>::removeMin()
{
	swap(&this->_heap[0], &this->_heap[--this->_size]);
	this->downHeap();
	return this->_heap[this->_size];
}
template <class T, std::size_t N>
const int Heap<T,N>::size() const
{
	return this->_size;
}
template <class T, std::size_t N>
const bool Heap<T,N>::isEmpty() const
{
	return (this->_size == 0);
}


template <class T, std::size_t N>
void Heap<T,N>::print(int size)
{
	std::cout << "start: ";
	for (int i = 0; i < size; i++)
		std::cout << this->_heap[i] << " ";
	std::cout << "end" << std::endl;
}

template <class T, std::size_t N>
void Heap<T,N>::reverse(int size)
{
	int middle = size/2;
	for (int i = 0; i < middle; i++)
	{
		swap(&this->_heap[i], &this->_heap[--size]);
	}
}
