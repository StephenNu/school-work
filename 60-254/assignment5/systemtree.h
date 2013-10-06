#include "TreeNode.h"
template <class T>
class Tree {
private:
	TreeNode<T>* _root;
public:
	Tree();
	~Tree();
	
	void remove_post_order(TreeNode<T>*);


	void insert(const T&);
	void remove(const T&);

	bool empty() const;
	int size() const;
	int subSize(TreeNode<T>*);

	TreeNode<T>* next(TreeNode<T>*);
	TreeNode<T>* TreeSearch(TreeNode<T>*, const T&) const;

	const bool find(const T&) const;

	void print() const;
	void print_op(int ) const;
	void print_right(const TreeNode<T>*) const;
	void print_left(const TreeNode<T>*) const;
	void print_in_order(const TreeNode<T>*) const;
};

template <class T>
Tree<T>::Tree()
	: _root(0)
{
}
template <class T>
Tree<T>::~Tree()
{
	if (this->_root == 0)
	{
		delete [] this->_root;
	}
	else
	{
		remove_post_order(this->_root->left());
		remove_post_order(this->_root->right());
		delete [] this->_root;
	}

}
template <class T>
void Tree<T>::remove_post_order(TreeNode<T>* root)
{
	if (root == 0)
	{
		delete [] root;
	}
	else
	{
		remove_post_order(root->left());
		remove_post_order(root->right());
		delete [] root;
	}
}
template <class T>
void Tree<T>::insert(const T& element)
{
	TreeNode<T>* new_node = new TreeNode<T>(element);
	if (this->_root == 0)
	{
		this->_root = new_node;
	}
	else
	{
		TreeNode<T>* potential_parent = this->_root;
		while(new_node->parent() == 0)
		{
			if(*(*new_node) < *(*potential_parent))
			{
				if(potential_parent->left() == 0)
				{
					new_node->set_parent(potential_parent);
					potential_parent->set_left(new_node);
				}
				else
				{
					potential_parent = potential_parent->left();
				}
			}
			else
			{
				if (potential_parent->right() == 0)
				{
					new_node->set_parent(potential_parent);
					potential_parent->set_right(new_node);
				}
				else
				{
					potential_parent = potential_parent->right();
				}
			}
		}
	}
}
template <class T>
bool Tree<T>::empty() const
{
	return this->_root == 0;
}
template <class T>
int Tree<T>::size() const
{
	return this->subSize(this->_root);
}
template <class T>
int Tree<T>::subSize(TreeNode<T>* root)
{
	if (root == 0)
	{
		return 0;
	}
	else
	{
		return 1 + this->subSize(root->left()) + this->subSize(root->right());
	}
}
template <class T>
void Tree<T>::remove(const T& key)
{
	TreeNode<T>* to_be_removed = this->TreeSearch(this->_root, key);
	if (to_be_removed != 0)
	{
		if (to_be_removed->parent() == 0)
		{
			if (to_be_removed->left() == 0)
			{
				this->_root = to_be_removed->right();
				delete [] to_be_removed;

			}
			else if (to_be_removed->right() == 0)
			{
				this->_root = to_be_removed->left();
				delete [] to_be_removed;
			}
			else
			{

				TreeNode<T>* next = this->next(to_be_removed->right());
				*(*to_be_removed) = *(*next);
				if (next->parent() == to_be_removed)
				{
					if (next->right() == 0)
					{
						
						next->parent()->set_right(0);
						delete [] next;
					}
					else
					{
						next->parent()->set_right(next->right());
						next->right()->set_parent(next->parent());
						delete [] next;
					}
				}
				else
				{
					next->parent()->set_left(0);
					delete [] next;
				}
			}
		}
		else if (to_be_removed->right() == 0 && to_be_removed->left() == 0)
		{
			if (to_be_removed->parent()->right() == to_be_removed)
			{
				to_be_removed->parent()->set_right(0);
			}
			else
			{
				to_be_removed->parent()->set_left(0);
			}
			delete [] to_be_removed;
		}
		else if(to_be_removed->left() == 0)
		{
			if (to_be_removed->parent()->right() == to_be_removed)
			{
				to_be_removed->parent()->set_right(to_be_removed->right());
				to_be_removed->right()->set_parent(to_be_removed->parent());
			}
			else
			{
				to_be_removed->right()->set_parent(to_be_removed->parent());
				to_be_removed->parent()->set_left(to_be_removed->right());
			}
			delete [] to_be_removed;
		}
		else if(to_be_removed->right() == 0)
		{
			if (to_be_removed->parent()->left() == to_be_removed)
			{
				to_be_removed->parent()->set_left(to_be_removed->left());
				to_be_removed->left()->set_parent(to_be_removed->parent());
			}
			else
			{
				to_be_removed->parent()->set_right(to_be_removed->left());
				to_be_removed->left()->set_parent(to_be_removed->parent());
			}
			delete [] to_be_removed;
		}
		else
		{
			TreeNode<T>* next = this->next(to_be_removed->right());
			*to_be_removed = *next;
			if (next->parent() == to_be_removed)
			{
				if (next->right() == 0)
				{
					next->parent()->set_right(0);
					delete [] next;
				}
				else
				{
					next->parent()->set_right(next->right());
					next->right()->set_parent(next->parent());
					delete [] next;
				}
			}
			else
			{
				next->parent()->set_left(0);
				delete [] next;
			}
		}
	}
}
template <class T>
TreeNode<T>* Tree<T>::next(TreeNode<T>* root)
{
	if (root == 0 || root->left() == 0)
		return root;
	else
		return this->next(root->left());
}
template <class T>
TreeNode<T>* Tree<T>::TreeSearch(TreeNode<T>* root, const T& key) const
{
	if (root == 0)
	{
		return 0;
	}
	else
	{
		if (*(*root) == key)
		{
			return root;
		}
		else 
		{
			TreeNode<T>*left = TreeSearch(root->left(), key);
			if (left != 0)
			{
				return left;
			}
			left = this->TreeSearch(root->right(), key);
			return left;
		}
	}
}
template <class T>
void Tree<T>::print() const
{
	print_in_order(this->_root);
	std::cout << std::endl;
}
template <class T>
void Tree<T>::print_in_order(const TreeNode<T>* root) const
{
	if (root != 0)
	{
		print_in_order(root->left());
		std::cout << " " << *(*root);
		print_in_order(root->right());	
	}
}

template <class T>
const bool Tree<T>::find(const T& key) const
{
	TreeNode<T>* find = this->TreeSearch(this->_root, key);
	return find != 0;
}
template <class T>
void Tree<T>::print_op(int op) const
{
	if (op == 0) // right
	{
		this->print_right(this->_root);
	}
	else if (op == 1) // left
	{
		this->print_left(this->_root);
	}
	else
	{
		std::cout << "error" << std::endl;
	}
	std::cout << std::endl;
}
template <class T>
void Tree<T>::print_right(const TreeNode<T>* root) const
{
	if (root == 0)
	{
		return;
	}
	if (root != this->_root)
		std::cout << " " << *(*root);
	if (root->right() == 0)
	{
		this->print_right(root->left());
	}
	else
	{
		this->print_right(root->right());
	}
}
template <class T>
void Tree<T>::print_left(const TreeNode<T>* root) const
{
	if (root == 0)
	{
		return;
	}
	if (root != this->_root)
	std::cout << " " << *(*root);
	if (root->left() == 0)
	{
		this->print_left(root->right());
	}
	else
	{
		this->print_left(root->left());
	}
}
