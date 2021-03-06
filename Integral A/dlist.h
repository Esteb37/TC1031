
#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include "coordinate.h"

template <class T>
class DList;

template <class T>
class Coordinate;

template <class T>
class DListIterator;

template <class T>
class DLink
{
private:
	DLink(Coordinate<T>);
	DLink(Coordinate<T>, DLink<T> *, DLink<T> *);
	DLink(const DLink<T> &);

	Coordinate<T> value;

	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
	friend class DListIterator<T>;
};

template <class T>
DLink<T>::DLink(Coordinate<T> val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(Coordinate<T> val, DLink *prev, DLink *nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) {}

template <class T>
class DList
{
public:
	DList();
	DList(const DList<T> &);
	~DList();

	void addFirst(Coordinate<T>);
	void add(Coordinate<T>);
	Coordinate<T> &getFirst() const;
	Coordinate<T> removeFirst();
	Coordinate<T> &getLast() const;
	Coordinate<T> removeLast() const;
	int length() const;
	Coordinate<T> &get(int) const;
	bool contains(Coordinate<T>) const;
	bool empty() const;
	void clear();
	std::string toString() const;
	void operator=(const DList &);

	bool set(int, Coordinate<T>);
	int indexOf(Coordinate<T>) const;
	int lastIndexOf(Coordinate<T>) const;
	Coordinate<T> remove(int);
	bool removeFirstOcurrence(Coordinate<T>);
	bool removeLastOcurrence(Coordinate<T>);

	void addBefore(DListIterator<T> &, T);
	void addAfter(DListIterator<T> &, T);
	T removeCurrent(DListIterator<T> &);

private:
	DLink<T> *head = 0;
	DLink<T> *tail = 0;
	int size = 0;

	friend class DListIterator<T>;
};

template <class T>
DList<T>::DList() {}

template <class T>
DList<T>::~DList()
{
	clear();
}

template <class T>
bool DList<T>::empty() const
{
	return size == 0;
}

template <class T>
int DList<T>::length() const
{
	return size;
}

template <class T>
bool DList<T>::contains(Coordinate<T> val) const
{
	DLink<T> *p;

	p = head;
	while (p != 0)
	{
		if (p->value == val)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
Coordinate<T> &DList<T>::getFirst() const
{
	return head->value;
}

template <class T>
Coordinate<T> &DList<T>::getLast() const
{
	return tail->value;
}

template <class T>
void DList<T>::addFirst(Coordinate<T> val)
{
	DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty())
	{
		head = newLink;
		tail = newLink;
	}
	else
	{
		newLink->next = head;
		head->previous = newLink;
		head = newLink;
	}
	size++;
}

template <class T>
void DList<T>::add(Coordinate<T> val)
{
	DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty())
	{
		head = newLink;
		tail = newLink;
	}
	else
	{
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
Coordinate<T> DList<T>::removeFirst()
{

	DLink<T> *p = head;
	Coordinate<T> val;

	val = p->value;

	if (head == tail)
	{
		head = 0;
		tail = 0;
	}
	else
	{
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return val;
}

template <class T>
Coordinate<T> &DList<T>::get(int index) const
{
	int pos;
	DLink<T> *p;

	if (index == 0)
	{
		return getFirst();
	}

	p = head;
	pos = 0;
	while (pos != index)
	{
		p = p->next;
		pos++;
	}

	return p->value;
}

template <class T>
void DList<T>::clear()
{
	DLink<T> *p, *q;

	p = head;
	while (p != 0)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
std::string DList<T>::toString() const
{
	std::stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0)
	{
		aux << p->value.toString();
		if (p->next != 0)
		{
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
DList<T>::DList(const DList<T> &source)
{
	DLink<T> *p, *q;

	if (source.empty())
	{
		size = 0;
		head = 0;
		tail = 0;
	}
	else
	{
		p = source->head;
		head = new DLink<T>(p->value);

		q = head;

		p = p->next;
		while (p != 0)
		{
			q->next = new DLink<T>(p->value, q, 0);

			p = p->next;
			q = q->next;
		}
		size = source->size;
	}
}

template <class T>
void DList<T>::operator=(const DList<T> &source)
{
	DLink<T> *p, *q;

	clear();
	if (source.empty())
	{
		size = 0;
		head = 0;
		tail = 0;
	}
	else
	{
		p = source->head;
		head = new DLink<T>(p->value);

		q = head;

		p = p->next;
		while (p != 0)
		{
			q->next = new DLink<T>(p->value, q, 0);
			if (q->next == 0)

				p = p->next;
			q = q->next;
		}
		size = source->size;
	}
}

template <class T>
bool DList<T>::set(int index, Coordinate<T> val)
{
	int pos;
	DLink<T> *p;

	p = head;
	pos = 0;
	while (pos != index)
	{
		p = p->next;
		pos++;
	}

	p->value = val;
	return true;
}

template <class T>
int DList<T>::indexOf(Coordinate<T> val) const
{
	int index;
	DLink<T> *p;

	index = 0;
	p = head;
	while (p != 0)
	{
		if (p->value == val)
		{
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

template <class T>
int DList<T>::lastIndexOf(Coordinate<T> val) const
{
	int index;
	DLink<T> *p;

	index = size - 1;
	p = tail;
	while (p != 0)
	{
		if (p->value == val)
		{
			return index;
		}
		index--;
		p = p->previous;
	}
	return -1;
}

template <class T>
Coordinate<T> DList<T>::remove(int index)
{
	int pos;
	Coordinate<T> val;
	DLink<T> *p;

	if (index == 0)
	{
		return removeFirst();
	}

	p = head;
	pos = 0;
	while (pos != index)
	{
		p = p->next;
		pos++;
	}

	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0)
	{
		p->next->previous = p->previous;
	}
	size--;

	delete p;

	return val;
}

template <class T>
bool DList<T>::removeFirstOcurrence(Coordinate<T> val)
{

	DLink<T> *p;

	p = head;

	while (p->next != 0)
	{
		p = p->next;

		if (val == p->value)
		{

			if (p->previous == 0)
			{
				head = p->next;
				p->next->previous = p->previous;
			}
			else
			{
				p->previous->next = p->next;
			}

			if (p->next != 0)
			{
				p->next->previous = p->previous;
			}
			size--;

			delete p;
			return true;
		}
	}
	return false;
}

template <class T>
bool DList<T>::removeLastOcurrence(Coordinate<T> val)
{
	DLink<T> *p;

	p = tail;

	while (p->previous != 0)
	{
		p = p->previous;

		if (val == p->value)
		{

			if (p->previous == 0)
			{
				head = p->next;
				p->next->previous = p->previous;
			}
			else
			{
				p->previous->next = p->next;
			}

			if (p->next != 0)
			{
				p->next->previous = p->previous;
			}
			size--;

			delete p;
			return true;
		}
	}

	return false;
}

// NO
template <class T>
void DList<T>::addBefore(DListIterator<T> &itr, T val)
{
	DLink<T> *newLink;

	// between
	if (itr.previous != 0)
	{
		newLink->next = itr.current;
		itr.current->previous = newLink;

		itr.previous->next = newLink;
		newLink->previous = itr.previous;

		itr.previous = itr.previous->next;
		size++;
		// start
	}
	else
	{
		addFirst(val);
		itr.previous = head;
		itr.current = itr.previous->next;
	}
}

template <class T>
void DList<T>::addAfter(DListIterator<T> &itr, T val)
{
	DLink<T> *newLink;

	// between
	if (itr.current != 0)
	{
		newLink->next = itr.current->next;
		itr.current->next->previous = newLink;

		itr.current->next = newLink;
		newLink->previous = itr.current;
		size++;
		// end
	}
	else if (itr.previous != 0)
	{
		itr.previous->next = newLink;
		newLink->previous = itr.previous;

		itr.current = newLink;
		size++;
		// start
	}
	else
	{
		addFirst(val);
		itr.current = head;
		itr.previous = 0;
	}
}

template <class T>
T DList<T>::removeCurrent(DListIterator<T> &itr)
{
	T val;

	if (itr.previous == 0)
	{
		head = itr.current->next;
		itr.current->next->previous = 0;
	}
	else
	{
		itr.previous->next = itr.current->next;
		itr.current->next->previous = itr.previous;
	}

	val = itr.current->value;
	delete itr.current;
	itr.current = 0;

	return val;
}

template <class T>
class DListIterator
{
public:
	DListIterator(DList<T> *);
	DListIterator(const DListIterator<T> &);

	bool begin();
	bool end();
	Coordinate<T> &operator()();
	bool operator++();
	void operator=(T);

private:
	DLink<T> *current;
	DLink<T> *previous;
	DList<T> *theList;

	friend class DList<T>;
};

template <class T>
DListIterator<T>::DListIterator(DList<T> *aList) : theList(aList)
{
	begin();
}

template <class T>
DListIterator<T>::DListIterator(const DListIterator<T> &source) : theList(source.theList)
{
	begin();
}

template <class T>
bool DListIterator<T>::begin()
{
	previous = 0;
	current = theList->head;
	return (current != 0);
}

template <class T>
Coordinate<T> &DListIterator<T>::operator()()
{
	return current->value;
}

template <class T>
bool DListIterator<T>::end()
{
	if (current == 0)
	{
		if (previous != 0)
		{
			current = previous->next;
		}
	}
	return (current == 0);
}

template <class T>
bool DListIterator<T>::operator++()
{
	if (current == 0)
	{
		if (previous == 0)
		{
			current = theList->head;
		}
		else
		{
			current = previous->next;
		}
	}
	else
	{
		previous = current;
		current = current->next;
	}
	return (current != 0);
}

template <class T>
void DListIterator<T>::operator=(T val)
{
	current->value = val;
}

#endif /* DLIST_H_ */
