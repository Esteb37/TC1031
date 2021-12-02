#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>
#include "coordinate.h"
#include "dlist.h"

template <class T>
class Heap
{
private:
	Coordinate<T> *data;
	unsigned int size;
	unsigned int count;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);
	Coordinate<T> *origin;

public:
	Heap();
	Heap(unsigned int, Coordinate<T> &);
	Heap(DList<T>, unsigned int);
	~Heap();
	bool empty() const;
	bool full() const;
	void add(Coordinate<T>);
	Coordinate<T> remove();
	void clear();

	void setOrigin(Coordinate<T> &);
	void setSize(int);

	std::string toString() const;

	unsigned int getSize() { return size; }
	unsigned int getCount() { return count; }
};

template <class T>
Heap<T>::Heap()
{
	size = 0;
	data = new Coordinate<T>[size];
	count = 0;
}

template <class T>
Heap<T>::Heap(unsigned int sze, Coordinate<T> &orgn) : origin(orgn)
{
	size = sze;
	data = new Coordinate<T>[size];
	count = 0;
}

template <class T>
Heap<T>::Heap(DList<T> path, unsigned int index)
{
	origin = path.get(index);
	size = path.size();
	data = new Coordinate<T>[size];
	count = 0;
}

template <class T>
Heap<T>::~Heap()
{
	delete[] data;
	data = 0;
	size = 0;
	count = 0;
}

template <class T>
bool Heap<T>::empty() const
{
	return (count == 0);
}

template <class T>
bool Heap<T>::full() const
{
	return (count == size);
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const
{
	return (pos - 1) / 2;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const
{
	return ((2 * pos) + 1);
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const
{
	return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j)
{
	Coordinate<T> aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos)
{
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;

	if (le <= count && origin->getDistance(data[le]) < origin->getDistance(data[min]))
	{
		min = le;
	}
	if (ri <= count && origin->getDistance(data[ri]) < origin->getDistance(data[min]))
	{
		min = ri;
	}
	if (min != pos)
	{
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
void Heap<T>::add(Coordinate<T> val)
{
	unsigned int pos;

	pos = count;
	count++;
	while (pos > 0 && origin->getDistance(val) < origin->getDistance(data[parent(pos)]))
	{
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
Coordinate<T> Heap<T>::remove()
{
	Coordinate<T> aux = data[0];

	data[0] = data[--count];
	heapify(0);
	return aux;
}

template <class T>
void Heap<T>::clear()
{
	count = 0;
}

template <class T>
std::string Heap<T>::toString() const
{
	std::stringstream aux;

	aux << "\nOrigin: ";
	aux << origin->toString() << "\n\n";

	int lineLength = 1;
	int linePos = 0;

	for (unsigned int i = 0; i < count; i++)
	{
		if (i != 0)
		{
			aux << " ";
		}

		aux << data[i].toString();

		if (++linePos == lineLength)
		{
			lineLength *= 2;
			linePos = 0;
			aux << "\n";
		}
	}
	return aux.str();
}

template <class T>
void Heap<T>::setOrigin(Coordinate<T> &orgn)
{
	origin = &orgn;
};

template <class T>
void Heap<T>::setSize(int sze)
{
	size = sze;
	data = new Coordinate<T>[size];
};

#endif /* HASH_H_ */