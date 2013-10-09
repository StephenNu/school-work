template <class T>
class TreeNode {
private:
	T _element;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode<T>* _parent;
public:
	TreeNode(const T&);
	
	TreeNode<T>* left();
	TreeNode<T>* right();
	TreeNode<T>* parent();
	T& element();
	const T& element() const;
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
TreeNode<T>* TreeNode<T>::left()
{
	return this->_left;
}

template <class T>
TreeNode<T>* TreeNode<T>::right()
{
	return this->_right;
}

template <class T>
TreeNode<T>* TreeNode<T>::parent()
{
	return this->_parent;
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



