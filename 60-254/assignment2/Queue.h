#include "LinkedList.h"

template <class T>
class Queue
{
private:
	LinkedList<T> _data;
public:
	Queue ();
	
	T& front();
	const T& front () const;
	
	void enqueue (const T&);
	void dequeue ();

	int size () const;
	bool empty () const;
};

template <class T>
Queue<T>::Queue()
	: _data()
{
}

template <class T>
T& Queue<T>::front()
{
	return this->_data.front();
}

template <class T>
const T& Queue<T>::front() const
{
	return _data.front();
}

template <class T>
void Queue<T>::enqueue(const T& element)
{
	this->_data.push_back(element);
}

template <class T>
void Queue<T>::dequeue()
{
	this->_data.pop_front();
}

template <class T>
int Queue<T>::size () const
{
	return this->_data.size();
}

template <class T>
bool Queue<T>::empty() const
{
	return this->_data.empty();
}
