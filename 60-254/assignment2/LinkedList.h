#include "Node.h"
#include "LinkedNodeIterator.h"

template <class T>
class LinkedList
{
private:
	Node<T> _head;
	Node<T> _tail;
	int _size;
public:
	LinkedList ();
	~LinkedList ();
	

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	void push_front(const T&);
	void push_back(const T&);
	void replace(T&, const T&);
	
	void pop_front();
	void pop_back();
	void remove(LinkedNodeIterator<T>);

	LinkedNodeIterator<T> begin();
	LinkedNodeIterator<T> end();
	
	bool empty() const;
	int size() const;
	
	T& operator[](int);
	const T& operator[](int) const;	
};

template <class T>
LinkedList<T>::LinkedList ()
	:  _size(0)
{
	this->_head.set_next(&this->_tail);
	this->_tail.set_previous(&this->_head);
}

template <class T>
LinkedList<T>::~LinkedList ()
{
	Node<T>* next_object = this->_head.next();
	while (this->_size != 0)
	{
		this->pop_front();
		next_object = this->_head.next();
	}
}

template <class T>
T& LinkedList<T>::front()
{
	return this->_head.next()->element();
}

template <class T>
T& LinkedList<T>::back()
{
	return this->_tail.previous()->element();
}

template <class T>
void LinkedList<T>::push_front(const T& element)
{
	Node<T>* const front = new Node<T>(element, &this->_head, this->_head.next());
	this->_head.next()->set_previous(front);
	this->_head.set_next(front);
	this->_size++;
}

template <class T>
void LinkedList<T>::push_back(const T& element)
{
	Node<T>* const back = new Node<T>(element, this->_tail.previous(), &this->_tail);
	this->_tail.previous()->set_next(back);
	this->_tail.set_previous(back);
	this->_size++;
}

template <class T>
void LinkedList<T>::replace(T& position, const T& value)
{
	position = value;
}

template <class T>
void LinkedList<T>::pop_front()
{
	if (this->_size != 0)
	{
		Node<T>* const front = this->_head.next();
		this->_head.set_next(front->next());
		front->next()->set_previous(&this->_head);
		delete[] front;
		this->_size--;
	}
}
// n for singlely
template <class T>
void LinkedList<T>::pop_back()
{
	if (this->_size != 0)
	{
		Node<T>* const back = this->_tail.previous();
		this->_tail.set_previous(back->previous());
		back->previous()->set_next(&this->_head);
		delete[] back;
		this->_size--;
	}
}

template <class T>
void LinkedList<T>::remove(LinkedNodeIterator<T> node)
{
	if (node == this->begin())
	{
		this->pop_front();
	}
	else if (node == this->end()) // goes one past end to change.
	{
		this->pop_back();
	}
	else
	{
		node._current->previous()->set_next(node._current->next());
		node._current->next()->set_previous(node._current->previous());	  
		delete[] node._current;
		this->_size--;
	}
}


template <class T>
LinkedNodeIterator<T> LinkedList<T>::begin()
{
	LinkedNodeIterator<T> beginning(this->_head.next());
	return beginning;
}

template <class T>
LinkedNodeIterator<T> LinkedList<T>::end()
{
	LinkedNodeIterator<T> end(this->_tail.previous());
	return end;
}

template <class T>
bool LinkedList<T>::empty() const
{
	if (this->_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
int LinkedList<T>::size() const
{
	return this->_size;
}


template<class T>
T& LinkedList<T>::operator[](int index)
{
	if(index >= 0)
	{
		Node<T>* node = this->_head.next();

		while(index > 0)
		{
			node = node->next();
			--index;
		}
		
		return node->element();
	}
	else
	{
		return this->_head.element();
	}
}

template<class T>
const T& LinkedList<T>::operator[](int index) const
{
	if(index >= 0)
	{
		Node<T>* node = this->_head.next();

		while(index > 0)
		{
			node = node->next();
			--index;
		}

		return node->element();
	}
	else
	{
		return this->_head.element();
	}
}
