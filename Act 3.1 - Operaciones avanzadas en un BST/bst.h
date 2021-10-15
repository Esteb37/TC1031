#include <string>
#include <sstream>
#include <iostream>

template <class T>
class BST;

template <class T>
class Node
{
private:
	T value;
	Node *left, *right;

	Node<T> *succesor();

public:
	Node(T);
	Node(T, Node<T> *, Node<T> *);
	void add(T);
	bool find(T);
	void inorder(std::stringstream &) const;
	void preorder(std::stringstream &) const;
	void postorder(std::stringstream &) const;
	void levelorder(std::stringstream &) const;
	void print(std::stringstream &) const;
	void ancestors(std::stringstream &, T val) const;
	void whatlevelamI(int &, T) const;
	int depth() const;
	friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
		: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val)
{
	if (val < value)
	{
		if (left != 0)
		{
			left->add(val);
		}
		else
		{
			left = new Node<T>(val);
		}
	}
	else
	{
		if (right != 0)
		{
			right->add(val);
		}
		else
		{
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val)
{
	if (val == value)
	{
		return true;
	}
	else if (val < value)
	{
		return (left != 0 && left->find(val));
	}
	else if (val > value)
	{
		return (right != 0 && right->find(val));
	}
	return false;
}

template <class T>
void Node<T>::ancestors(std::stringstream &aux, T val) const
{

	if (val < value)
	{
		aux << value << " ";
		if (left != 0)
			left->ancestors(aux, val);
	}
	else if (val > value)
	{
		aux << value << " ";
		if (right != 0)
			right->ancestors(aux, val);
	}
}

template <class T>
void Node<T>::whatlevelamI(int &level, T val) const
{

	if (val < value)
	{
		if (left != 0)
			left->whatlevelamI(level, val);
	}
	else if (val > value)
	{
		if (right != 0)
			right->whatlevelamI(level, val);
	}
	level++;
}

template <class T>
void Node<T>::print(std::stringstream &aux) const
{
	aux << value << " ";
}

template <class T>
void Node<T>::levelorder(std::stringstream &aux) const
{

	if (left != 0)
	{
		left->print(aux);
	}
	if (right != 0)
	{
		right->print(aux);
	}

	if (left != 0)
	{
		left->levelorder(aux);
	}
	if (right != 0)
	{
		right->levelorder(aux);
	}
}

template <class T>
Node<T> *Node<T>::succesor()
{
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0)
	{
		if (right != 0)
		{
			right = 0;
		}
		return ri;
	}

	if (left->right == 0)
	{
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0)
	{
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const
{
	if (left != 0)
	{
		left->inorder(aux);
	}
	if (aux.tellp() != 1)
	{
		aux << " ";
	}
	aux << value;
	if (right != 0)
	{
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const
{
	aux << value;
	if (left != 0)
	{
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0)
	{
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const
{

	if (left != 0)
	{
		left->postorder(aux);
	}

	if (right != 0)
	{
		right->postorder(aux);
	}

	aux << value << " ";
}

template <class T>
int Node<T>::depth() const
{
	int right_count = -1;
	int left_count = -1;
	int higher_count = -1;

	if (left != 0)
	{
		left_count = left->depth();
	}

	if (right != 0)
	{
		right_count = right->depth();
	}

	higher_count = (left_count > right_count) ? left_count : right_count;
	return (higher_count + 1);
}

template <class T>
class BST
{
private:
	Node<T> *root;

public:
	BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	std::string inorder() const;
	std::string preorder() const;
	std::string postorder() const;
	std::string levelorder() const;
	std::string visit() const;
	int height() const;
	std::string ancestors(T) const;
	int whatlevelamI(T) const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const
{
	return (root == 0);
}

template <class T>
void BST<T>::add(T val)
{
	if (!empty())
	{
		if (!root->find(val))
		{
			root->add(val);
		}
	}
	else
	{
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const
{
	if (!empty())
	{
		return root->find(val);
	}
	else
	{
		return false;
	}
}

template <class T>
std::string BST<T>::ancestors(T val) const
{
	std::stringstream aux;

	aux << "[";
	if (!empty() && root->find(val))
	{
		root->ancestors(aux, val);
		aux.seekp(-1, std::ios_base::end);
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) const
{
	int level = 0;

	if (!empty())
	{
		root->whatlevelamI(level, val);
	}

	return level;
}

template <class T>
std::string BST<T>::inorder() const
{
	std::stringstream aux;

	aux << "[";
	if (!empty())
	{
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const
{
	std::stringstream aux;

	aux << "[";
	if (!empty())
	{
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::postorder() const
{
	std::stringstream aux;

	aux << "[";
	if (!empty())
	{
		root->postorder(aux);
	}
	aux.seekp(-1, std::ios_base::end);
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::levelorder() const
{
	std::stringstream aux;

	aux << "[";
	if (!empty())
	{
		root->print(aux);
		root->levelorder(aux);
	}
	aux.seekp(-1, std::ios_base::end);
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::visit() const
{
	return preorder() + "\n" + inorder() + "\n" + postorder() + "\n" + levelorder();
}

template <class T>
int BST<T>::height() const
{
	return empty() ? 0 : root->depth() + 1; //cause of the -1
}