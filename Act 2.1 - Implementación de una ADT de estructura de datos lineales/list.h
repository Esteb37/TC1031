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
class List;
template <class T>
class ListIterator;

template <class T>
class Link
{
private:
  Link(T);
  Link(T, Link<T> *);
  Link(const Link<T> &);

  T value;
  Link<T> *next = 0;

  friend class List<T>;
  friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val) {}

template <class T>
Link<T>::Link(T val, Link *nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) {}

template <class T>
class List
{
public:
  List();
  List(const List<T> &) throw(OutOfMemory);
  ~List();

  void addFirst(T) throw(OutOfMemory);
  void insertion(T) throw(OutOfMemory);

  T removeFirst() throw(NoSuchElement);
  T deleteAt(int) throw(IndexOutOfBounds);

  bool update(int, T) throw(IndexOutOfBounds);
  int search(T) const;

  bool empty() const;
  std::string toString() const;

  Link<T> *head = 0;

private:
  int size = 0;

  friend class ListIterator<T>;
};

template <class T>
List<T>::List() {}

template <class T>
List<T>::~List()
{
}

template <class T>
bool List<T>::empty() const
{
  return size == 0;
}

template <class T>
void List<T>::addFirst(T val) throw(OutOfMemory)
{
  Link<T> *newLink = new Link<T>(val, head);

  if (newLink == 0)
  {
    throw OutOfMemory();
  }

  head = newLink;
  size++;
}

template <class T>
void List<T>::insertion(T val) throw(OutOfMemory)
{
  Link<T> *p, *newLink = new Link<T>(val);

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
T List<T>::removeFirst() throw(NoSuchElement)
{
  Link<T> *p = head;

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
std::string List<T>::toString() const
{
  std::stringstream aux;
  Link<T> *p;

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
List<T>::List(const List<T> &source) throw(OutOfMemory)
{

  Link<T> *p, *q;

  if (source.empty())
  {
    size = 0;
    head = 0;
  }
  else
  {
    p = source.head;
    head = new Link<T>(p->value);
    if (head == 0)
    {
      throw OutOfMemory();
    }
    q = head;

    p = p->next;

    while (p != 0)
    {
      q->next = new Link<T>(p->value);
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
bool List<T>::update(int index, T val) throw(IndexOutOfBounds)
{

  Link<T> *p = head;

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
int List<T>::search(T val) const
{

  Link<T> *p = head;

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
T List<T>::deleteAt(int index) throw(IndexOutOfBounds)
{

  Link<T> *q, *p = head;
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
