#include <string>
#include <sstream>
#include <iostream>

template <class T>
class KDTree;

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
	void add(T, int);
	bool find(T, int);
	void print(std::stringstream &) const;
	void remove(T, int);
	void printLevel(std::stringstream &, int level) const;
	int depth() const;
	friend class KDTree<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val, int depth)
{

	int cd = depth % 2;

	int thisCoord = (cd == 0 ? value.getX() : value.getY());
	int otherCoord = (cd == 0 ? val.getX() : val.getY());

	if (otherCoord < thisCoord)
	{
		if (left != 0)
		{
			left->add(val, depth + 1);
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
			right->add(val, depth + 1);
		}
		else
		{
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val, int depth)
{
	int cd = depth % 2;

	int thisCoord = (cd == 0 ? value.getX() : value.getY());
	int otherCoord = (cd == 0 ? val.getX() : val.getY());

	if (val.getDistance(value) == 0)
	{
		return true;
	}
	else
	{
		if (otherCoord < thisCoord)
		{
			return (left != 0 && left->find(val, depth + 1));
		}
		else if (otherCoord > thisCoord)
		{
			return (right != 0 && right->find(val, depth + 1));
		}
	}

	return false;
}

template <class T>
void Node<T>::remove(T val, int depth)
{
	Node<T> *succ, *old;

	int cd = depth % 2;

	int thisCoord = (cd == 0 ? value.getX() : value.getY());
	int otherCoord = (cd == 0 ? val.getX() : val.getY());

	if (otherCoord < thisCoord)
	{
		if (left != 0)
		{
			if (left->value == val)
			{
				old = left;
				succ = left->succesor();
				if (succ != 0)
				{
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			}
			else
			{
				left->remove(val, depth + 1);
			}
		}
	}
	else if (otherCoord > thisCoord)
	{
		if (right != 0)
		{
			if (right->value == val)
			{
				old = right;
				succ = right->succesor();
				if (succ != 0)
				{
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			}
			else
			{
				right->remove(val, depth + 1);
			}
		}
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
}
template <class T>
void Node<T>::print(std::stringstream &aux) const
{
	aux << value.toString() << " ";
}

template <class T>
void Node<T>::printLevel(std::stringstream &aux, int level) const
{

	if (level == 1)
		return print(aux);
	else if (level > 1)
	{
		if (left)
			left->printLevel(aux, level - 1);

		if (right)
			right->printLevel(aux, level - 1);
	}
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
class KDTree
{
private:
	Node<T> *root;

public:
	KDTree();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	int height() const;
	string levelorder() const;
};

template <class T>
KDTree<T>::KDTree() : root(0) {}

template <class T>
bool KDTree<T>::empty() const
{
	return (root == 0);
}

template <class T>
void KDTree<T>::add(T val)
{
	if (!empty())
	{
		if (!root->find(val, 0))
		{
			root->add(val, 0);
		}
	}
	else
	{
		root = new Node<T>(val);
	}
}

template <class T>
bool KDTree<T>::find(T val) const
{
	if (!empty())
	{
		return root->find(val, 0);
	}
	else
	{
		return false;
	}
}

template <class T>
void KDTree<T>::remove(T val)
{
	if (root != 0)
	{
		if (val.getDistance(root->value) == 0)
		{
			Node<T> *succ = root->succesor();
			if (succ != 0)
			{
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		}
		else
		{
			root->remove(val, 0);
		}
	}
}

template <class T>
std::string KDTree<T>::levelorder() const
{
	std::stringstream aux;

	int h = height();

	int i;

	for (i = 1; i <= h; i++)
	{
		root->printLevel(aux, i);
		aux << endl;
	}
	return aux.str();
}

template <class T>
int KDTree<T>::height() const
{
	return empty() ? 0 : root->depth() + 1; // cause of the -1
}
