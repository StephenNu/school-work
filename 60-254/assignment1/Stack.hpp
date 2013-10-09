template <class T, std::size_t N = 10>

class Stack {
	private:
		int _index;
		T _data[N];
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
{
	this->_index--;
	return this->_data[this->_index+1];
}

template <class T, std::size_t N>
void Stack<T,N>::push (T const& newElement)
{
	this->_index++;
	this->_data[this->_index] = newElement;
}

template <class T, std::size_t N>
T const& Stack<T,N>::peek () const
{
	return this->_data[this->_index];
}

template <class T, std::size_t N>
bool Stack<T,N>::isEmpty () const
{
	if (_index == -1)
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
	return _index+1;
}
