/*
 * linkedlist.h
 *
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
  DLink(T, DLink<T> *);
  DLink(const DLink<T> &);

  T value;
  DLink<T> *next = 0;

  friend class DList<T>;
  friend class ListIterator<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val) {}

template <class T>
DLink<T>::DLink(T val, DLink *nxt) : value(val), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) {}

template <class T>
class DList
{
public:
  DList();
  DList(const DList<T> &) throw(OutOfMemory);
  ~DList();

  void addFirst(T) throw(OutOfMemory);
  void insertion(T) throw(OutOfMemory);

  T removeFirst() throw(NoSuchElement);
  T deleteAt(int) throw(IndexOutOfBounds);

  bool update(int, T) throw(IndexOutOfBounds);
  int search(T) const;

  bool empty() const;
  std::string toString() const;

  DLink<T> *head = 0;

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
void DList<T>::addFirst(T val) throw(OutOfMemory)
{
  DLink<T> *newLink = new DLink<T>(val, head);

  if (newLink == 0)
  {
    throw OutOfMemory();
  }

  head = newLink;
  size++;
}

template <class T>
void DList<T>::insertion(T val) throw(OutOfMemory)
{
  DLink<T> *p, *newLink = new DLink<T>(val);

  if (newLink == 0)
  {
    throw OutOfMemory();
  }

  if (empty())
  {
    addFirst(val);
    return;
  }

  p = head;
  while (p->next != 0)
  {
    p = p->next;
  }

  newLink->next = 0;
  p->next = newLink;
  size++;
}

template <class T>
T DList<T>::removeFirst() throw(NoSuchElement)
{
  DLink<T> *p = head;

  if (empty())
  {
    throw NoSuchElement();
  }

  head = p->next;
  T val = p->value;

  delete p;
  size--;

  return val;
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

  DLink<T> *p = head;

  if (index >= size || index < 0)
  {
    throw IndexOutOfBounds();
  }

  for (int pos = 0; pos < index; pos++)
  {
    p = p->next;
  }

  p->value = val;

  return false;
}

template <class T>
int DList<T>::search(T val) const
{

  DLink<T> *p = head;

  int pos = 0;
  while (p != 0)
  {
    if (p->value == val)
    {
      return pos;
    }
    pos++;
    p = p->next;
  }

  return -1;
}

template <class T>
T DList<T>::deleteAt(int index) throw(IndexOutOfBounds)
{

  DLink<T> *q, *p = head;
  int val;

  if (index == 0)
  {
    return removeFirst();
  }

  if (index >= size || index < 0)
  {
    throw IndexOutOfBounds();
  }

  for (int pos = 0; pos < index - 1; pos++)
  {
    p = p->next;
  }

  q = p->next;
  p->next = q->next;
  val = q->value;
  delete q;

  return val;
}

#endif /* LINKEDLIST_H_ */
