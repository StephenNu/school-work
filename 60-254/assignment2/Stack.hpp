#include "LinkedList.h"
template <class T, std::size_t N = 10>

class Stack {
	private:
		T _index;
		LinkedList<T> _data;
	public:
		Stack ();
		T& pop ();
		void push (T const&);
		T const& peek () const;
		bool isEmpty () const;
		int size () const;
};

template <class T, std::size_t N>
Stack<T,N>::Stack() : _index(-1) 
{
}

template <class T, std::size_t N>
T& Stack<T,N>::pop ()
{// local value
	this->_index  = this->_data.front();
	this->_data.pop_front();
	return this->_index;
}

template <class T, std::size_t N>
void Stack<T,N>::push (T const& newElement)
{
	this->_data.push_front(newElement);
}

template <class T, std::size_t N>
T const& Stack<T,N>::peek () const
{
	return this->_data.front();
}

template <class T, std::size_t N>
bool Stack<T,N>::isEmpty () const
{
	if (this->_data.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T, std::size_t N>
int Stack<T,N>::size () const
{
	return this->_data.size();
}
