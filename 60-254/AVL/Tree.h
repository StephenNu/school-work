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
	void balance(TreeNode<T>*);
	TreeNode<T>* next(const TreeNode<T>* const) const;
	TreeNode<T>* TreeSearch(const TreeNode<T>* const, const T&) const;

	TreeNode<T>* find_grand_child(TreeNode<T>* const);
	void restructure(TreeNode<T>*);

	bool find(const T&) const;

	void print() const;
	void print_in_order(const TreeNode<T>* const) const;
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
TreeNode<T>* Tree<T>::find_grand_child(TreeNode<T>* const root)
{
	if (root == 0)
	{
		return 0;
	}
	else if (root->right() != 0 && (root->right()->right() != 0 || root->right()->left() != 0))
	{
		if (root->right()->right() != 0)
			return root->right()->right();
		else
			return root->right()->left();
	}
	else if (root->left() != 0 && (root->left()->right() != 0 || root->left()->left() != 0))
	{
		if (root->left()->right() != 0)
			return root->left()->right();
		else
			return root->left()->left();
	}
	else
	{
		return 0;
	}
}

template <class T>
void Tree<T>::restructure(TreeNode<T>* x)
{
	if (x == 0 || x->parent() == 0 || x->parent()->parent() == 0)
	{
		return;
	}
	else
	{
		TreeNode<T>* z = x->parent()->parent(), *a, *b, *c;
		TreeNode<T>* y = x->parent();
		TreeNode<T>* T0, *T1, *T2, *T3;
		if (x == z->left()->right())
		{
			a = y;
			b = x;
			c = z;
			T0 = a->left();
			T1 = b->left();
			T2 = b->right();
			T3 = c->right();
		}
		else if (x == z->right()->right())
		{
			a = z;
			b = y;
			c = x;
			T0 = a->left();
			T1 = b->left();
			T2 = c->right();
			T3 = c->left();
		}
		else if (x == z->right()->left())
		{
			a = z;
			b = y;
			c = x;
			T0 = a->left();
			T1 = b->left();
			T2 = b->right();
			T3 = c->right();
		}
		else
		{
			a = z;
			b = y;
			c = x;
			T0 = a->left();
			T1 = a->right();
			T2 = b->right();
			T3 = c->right();
		}
		a->left(T0);
		a->right(T1);
		c->left(T2);
		c->right(T3);
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
		std::cout << "hello " << this->subSize(new_node) << std::endl;
		this->balance(_root);
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
void Tree<T>::balance(TreeNode<T>* root)
{
	if (root == 0)
	{
		return;
	}
	else if (root->left() != 0 || root->right() != 0)
	{
		if ((this->subSize(root->left()) - this->subSize(root->right())) != 1 || ((this->subSize(root->right()) - this->subSize(root->left()) != 1)))
		{
			TreeNode<T>* grand_child = this->find_grand_child(root);
			this->restructure(grand_child);
		}
	}
	/*else if (root->left() != 0 && this->subSize(root->left()) != 1)
	{
		TreeNode<T>* grand_child = this->find_grand_child(root);
		this->restructure(grand_child);
	}
	else if (root->right() != 0 && this->subSize(root->right()) != 1)
	{
		TreeNode<T>* grand_child = this->find_grand_child(root);
		this->restructure(grand_child);
	}*/
	if (root->left() != 0 || root->right() != 0)
		std::cout << this->subSize(root->left()) << " " << this->subSize(root->right()) << std::endl;
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
TreeNode<T>* Tree<T>::next(const TreeNode<T>* const root ) const
{
	if (root == 0 || root->left() == 0)
		return root;
	else
		return this->next(root->left());
}
template <class T>
TreeNode<T>* Tree<T>::TreeSearch(const TreeNode<T>* const root, const T& key) const
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
void Tree<T>::print_in_order(const TreeNode<T>* const root) const
{
	if (root != 0)
	{
		print_in_order(root->left());
		std::cout <<  " " << *(*root);
		print_in_order(root->right());	
	}
}

template <class T>
bool Tree<T>::find(const T& key) const
{
	TreeNode<T>* find = this->TreeSearch(this->_root, key);
	return find != 0;
}
