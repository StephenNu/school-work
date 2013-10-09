#ifndef _NODE_T_
#define _NODE_T_

template <class T>
class Node 
{
private:
	T _element;
	Node<T>* _previous;
	Node<T>* _next;
public:
	Node ();
	Node (const T&, Node<T>* const, Node<T>* const);
	
	T& element();
	const T& element() const;

	Node<T>*  next();
	Node<T>*  previous();
	void set_next(Node<T>* const);
	void set_previous(Node<T>* const);
};

template <class T>
Node<T>::Node() 
	: _element(), _previous(0), _next(0)
{
}

template <class T>
Node<T>::Node(const T& element, Node<T>* const previous, Node<T>* const next)
	: _element(element), _previous(previous), _next(next)
{
}

template <class T>
T& Node<T>::element()
{
	return this->_element;
}

template <class T>
const T& Node<T>::element() const
{
	return this->_element;
}

template <class T>
Node<T>* Node<T>::next()
{
	return this->_next;
}

template <class T>
Node<T>* Node<T>::previous()
{
	return this->_previous;
}

template <class T>
void Node<T>::set_next(Node<T>* const next)
{
	this->_next = next;
}

template <class T>
void Node<T>::set_previous(Node<T>* const previous)
{
	this->_previous = previous;
}

#endif
