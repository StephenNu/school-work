template <class T>
class TreeNode {
private:
	T _element;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode<T>* _parent;
	int _height;
public:
	TreeNode(const T&);
	
	void left(TreeNode<T>*);
	void right(TreeNode<T>*);
	TreeNode<T>* left();
	const TreeNode<T>* left () const;
	TreeNode<T>* right();
	const TreeNode<T>* right() const;
	TreeNode<T>* parent();
	const TreeNode<T>*  parent() const;
	T& element();
	const T& element() const;
	int height() const;
	int height(const TreeNode<T>*) const;
	void set_left(TreeNode<T>* const);
	void set_right(TreeNode<T>* const);
	void set_parent(TreeNode<T>* const);

	T& operator*();
	const T& operator*() const;
	
};

template <class T>
TreeNode<T>::TreeNode(const T& element)
	: _element(element), _left(0), _right(0), _parent(0)
{
}
template <class T>
void TreeNode<T>::left(TreeNode<T>* a)
{
	this->_left = a;
}
template <class T>
void TreeNode<T>::right(TreeNode<T>* b)
{
	this->_right = b;
}
template <class T>
TreeNode<T>* TreeNode<T>::left()
{
	return this->_left;
}

template <class T>
const TreeNode<T>* TreeNode<T>::left() const
{
	return this->_left;
}

template <class T>
TreeNode<T>* TreeNode<T>::right()
{
	return this->_right;
}

template <class T>
const TreeNode<T>* TreeNode<T>::right() const
{
	return this->_right;
}

template <class T>
TreeNode<T>* TreeNode<T>::parent()
{
	return this->_parent;
}

template <class T>
const TreeNode<T>* TreeNode<T>::parent() const
{
	return this->_parent;
}

template <class T>
int TreeNode<T>::height() const
{
	int left = 1 + height(this->left()), right = 1 + height(this->right());
	if (left > right)
	{
		return left;
	}
	else 
	{
		return right;
	}
}

template <class T>
int TreeNode<T>::height(const TreeNode<T>* a) const
{	
	if (a == 0)
		return 0;
	else
	{
		int left = 1 + height(this->left()), right = 1 + height(this->right());
		std::cout << "left = " << left << " right = " << right << std::endl;
		if (left > right)

			return left;
		else
			return right;
	}
}
template <class T>
void TreeNode<T>::set_left(TreeNode<T>* const left)
{
	this->_left = left;
}

template <class T>
void TreeNode<T>::set_right(TreeNode<T>* const right)
{
	this->_right = right;
}

template <class T>
void TreeNode<T>::set_parent(TreeNode<T>* const parent)
{
	this->_parent = parent;
}

template <class T>
T& TreeNode<T>::operator*()
{
	return this->_element;
}

template <class T>
const T& TreeNode<T>::operator*() const
{
	return this->_element;
}



