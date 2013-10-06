#include "Node.h"

template <typename T>
class LinkedList;

template<class T>
class LinkedNodeIterator
{
friend class LinkedList<T>;
private:
	Node<T>* _current;
public:
	LinkedNodeIterator<T>(Node<T>* const);

	// operators.
	bool operator!=(const LinkedNodeIterator<T>&) const;
	bool operator==(const LinkedNodeIterator<T>&) const;
	LinkedNodeIterator<T>& operator++();
	LinkedNodeIterator<T>& operator--();
	T& operator*();
	const T& operator*() const;
};

template <class T>
LinkedNodeIterator<T>::LinkedNodeIterator(Node<T>* const location)
	: _current(location)
{

}

template <class T>
bool LinkedNodeIterator<T>::operator!=(const LinkedNodeIterator<T>& test) const
{
	return this->_current != test._current;
}

template <class T>
bool LinkedNodeIterator<T>::operator==(const LinkedNodeIterator<T>& test) const
{
	return this->_current == test._current;
}

template <class T>
LinkedNodeIterator<T>& LinkedNodeIterator<T>::operator++()
{
	this->_current = this->_current->next();
	return *this;
}

template <class T>
LinkedNodeIterator<T>& LinkedNodeIterator<T>::operator--()
{
	this->_current = this->_current->previous();
	return *this;
}

template <class T>
T& LinkedNodeIterator<T>::operator*()
{
	return this->_current->element();
}

template <class T>
const T& LinkedNodeIterator<T>::operator*() const
{
	return this->_current->element();
}
