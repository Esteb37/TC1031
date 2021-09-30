/*
 * linkedlist.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T>
class DList;
template <class T>
class ListIterator;

template <class T>
class DLink
{
private:
	DLink(T);
	DLink(T, DLink<T> *, DLink<T> *);
	DLink(const DLink<T> &);

	T value;
	DLink<T> *previous = 0;
	DLink<T> *next = 0;

	friend class DList<T>;
	friend class ListIterator<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink *nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) {}

template <class T>
class DList
{
public:
	DList();
	DList(const DList<T> &) throw(OutOfMemory);
	~DList();

	void insertion(T) throw(OutOfMemory);

	T deleteAt(int) throw(IndexOutOfBounds);
	T removeFirst() throw(NoSuchElement);

	bool update(int, T) throw(IndexOutOfBounds);
	int search(T) const;

	bool empty() const;

	std::string toStringBackward() const;
	std::string toStringForward() const;

	DLink<T> *head = 0;
	DLink<T> *tail = 0;

private:
	int size = 0;

	friend class ListIterator<T>;
};

template <class T>
DList<T>::DList() {}

template <class T>
DList<T>::~DList()
{
}

template <class T>
bool DList<T>::empty() const
{
	return size == 0;
}

template <class T>
void DList<T>::insertion(T val) throw(OutOfMemory)
{
	DLink<T> *newLink;

	newLink = new DLink<T>(val);
	if (newLink == 0)
	{
		throw OutOfMemory();
	}

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
DList<T>::DList(const DList<T> &source) throw(OutOfMemory)
{

	DLink<T> *p, *q;

	if (source.empty())
	{
		size = 0;
		head = 0;
	}
	else
	{
		p = source.head;
		head = new DLink<T>(p->value);
		if (head == 0)
		{
			throw OutOfMemory();
		}
		q = head;

		p = p->next;

		while (p != 0)
		{
			q->next = new DLink<T>(p->value);
			if (q->next == 0)
			{
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
		std::cout << size;
	}
}

template <class T>
bool DList<T>::update(int index, T val) throw(IndexOutOfBounds)
{

	int pos;
	DLink<T> *p;

	if (index < 0 || index >= size)
	{
		throw IndexOutOfBounds();
	}

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
int DList<T>::search(T val) const
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
T DList<T>::removeFirst() throw(NoSuchElement)
{

	DLink<T> *p = head;
	T val;

	if (empty())
	{
		throw NoSuchElement();
	}

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
T DList<T>::deleteAt(int index) throw(IndexOutOfBounds)
{

	int pos;
	T val;
	DLink<T> *p;

	if (index < 0 || index >= size)
	{
		throw IndexOutOfBounds();
	}

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
std::string DList<T>::toStringForward() const
{
	std::stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0)
	{
		aux << p->value;
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
std::string DList<T>::toStringBackward() const
{
	std::stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != 0)
	{
		aux << p->value;
		if (p->previous != 0)
		{
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

#endif /* LINKEDLIST_H_ */
