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

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next = 0;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val){}

template <class T>
Link<T>::Link(T val, Link* nxt) :value(val),next(nxt){}

template <class T>
Link<T>::Link(const Link<T> &source) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&) throw (OutOfMemory);
	~List();

	void addFirst(T) throw (OutOfMemory);
	void add(T) throw (OutOfMemory);
	T    getFirst() const throw (NoSuchElement);
	T    removeFirst() throw (NoSuchElement);
	int  length() const;
	T    get(int) const throw (IndexOutOfBounds, NoSuchElement);
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string toString() const;
	void operator= (const List&) throw (OutOfMemory);

	void addBefore(ListIterator<T>&, T) throw (IllegalAction, OutOfMemory);
	void addAfter(ListIterator<T>&, T) throw (IllegalAction, OutOfMemory);
	T    removeCurrent(ListIterator<T>&) throw (IllegalAction);

	bool set(int, T) throw (IndexOutOfBounds);
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	T    remove(int) throw (IndexOutOfBounds);
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);

    Link<T> *head = 0;

private:
	
	int size = 0;

	friend class ListIterator<T>;
};

template <class T>
List<T>::List(){}

template <class T>
List<T>::~List() {
}

template <class T>
bool List<T>::empty() const {
	return size == 0;
}

template <class T>
int List<T>::length() const {
	return size;
}

template <class T>
bool List<T>::contains(T val) const {
	
    Link<T> *p = head;

    while(p!=0){
        if(p->value == val){
            return true;
        }
        p = p->next;
    }

    return false;

}

template <class T>
T List<T>::getFirst() const throw (NoSuchElement) {

    if(empty()){
        throw NoSuchElement();
    }

    Link<T> *first = head;

	return first->value;
}

template <class T>
void List<T>::addFirst(T val) throw (OutOfMemory) {
    Link<T> *newLink = new Link<T>(val,head);

    if(newLink == 0){
        throw OutOfMemory();
    }

    head = newLink;
    size++;
}

template <class T>
void List<T>::add(T val) throw (OutOfMemory) {
    Link<T> *p, *newLink = new Link<T>(val);
    

    if(newLink == 0){
        throw OutOfMemory();
    }

    if(empty()){
        addFirst(val);
        return;
    }

    p = head;
    while(p->next != 0){
        p = p->next;
    }

    newLink->next = 0;
    p->next = newLink;
    size++;
}

template <class T>
T List<T>::removeFirst() throw (NoSuchElement) {
    Link<T> *p = head;

    if(empty()){
        throw NoSuchElement();
    }

	head = p->next;
    T val = p->value;

    delete p;
    size--;

    return val;
}

template <class T>
T List<T>::get(int index) const throw (IndexOutOfBounds, NoSuchElement) {

    Link<T> *p = head;
    
    if(index >= size || index < 0){
        throw IndexOutOfBounds();
    }

    for(int pos = 0; pos < index; pos++){
        p = p->next;
    }

	return p->value;
}

template <class T>
void List<T>::clear() {
    Link<T> *p,*q;
    p = head;
    while(p!=0){
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    size = 0;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

    
	p = head;
    
	aux << "[";
	while (p != 0) {
        
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}

	aux << "]";
    
	return aux.str();
}

template <class T>
List<T>::List(const List<T> &source) throw (OutOfMemory) {

    Link<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
	} else {
		p = source.head;
		head = new Link<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
        
		while(p != 0) {
			q->next = new Link<T>(p->value);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
            
		}
		size = source.size;
        std::cout<<size;
	}
}

template <class T>
void List<T>::operator=(const List<T> &source) throw (OutOfMemory) {
    Link<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
	} else {
		p = source.head;
		head = new Link<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
        
		while(p != 0) {
			q->next = new Link<T>(p->value);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
            
		}
		size = source.size;
        std::cout<<size;
	}
}

template <class T>
void List<T>::addBefore(ListIterator<T> &itr, T val) throw (IllegalAction, OutOfMemory) {
}

template <class T>
void List<T>::addAfter(ListIterator<T> &itr, T val) throw (IllegalAction, OutOfMemory) {
}

template <class T>
T List<T>::removeCurrent(ListIterator<T> &itr) throw (IllegalAction) {
	return 0;
}

template <class T>
bool List<T>::set(int index, T val) throw (IndexOutOfBounds) {

    Link<T> *p = head;

    if(index >= size || index < 0){
        throw IndexOutOfBounds();
    }

    for(int pos = 0; pos<index;pos++){
        p = p->next;
    }

    p->value = val;

	return false;
}

template <class T>
int List<T>::indexOf(T val) const {

    Link<T> *p = head;

    int pos = 0;
    while(p!=0){
        if(p->value == val){
            return pos;
        }
        pos++;
        p=p->next;
    }


	return -1;
}

template <class T>
int List<T>::lastIndexOf(T val) const {
	return -1;
}

template <class T>
T List<T>::remove(int index) throw (IndexOutOfBounds) {

    Link<T> *q, *p = head;
    int val;

    if(index >= size || index < 0){
        throw IndexOutOfBounds();
    }
    
    for(int pos = 0; pos<index-1;pos++){
        p=p->next;
    }
    
    q = p->next;
    p->next = q->next;
    val = q->value;
    delete q;
    
	return val;
}

template <class T>
bool List<T>::removeFirstOcurrence(T val) {
	Link<T> *q, *p = head;

    while(p!=0){
        if(p->next->value == val){
            q = p->next;
            p->next = q->next;
            delete q;
            return true;
        }
        p=p->next;
    }

	return false;
}

template <class T>
bool List<T>::removeLastOcurrence(T val) {
	return false;
}

template <class T>
class ListIterator {
public:
	ListIterator(List<T>*);
	ListIterator(const ListIterator<T>&);

	bool begin();
	bool end();
	T&   operator() () throw (NoSuchElement);
	bool operator++ ();
	void operator= (T) throw (NoSuchElement);

private:
	Link<T> *current;
	Link<T> *previous;
	List<T> *theList;

	friend class List<T>;
};

template <class T>
ListIterator<T>::ListIterator(List<T> *aList) : theList(aList) {
	begin();
}

template <class T>
ListIterator<T>::ListIterator(const ListIterator<T> &source) : theList(source.theList) {
	begin();
}

template <class T>
bool ListIterator<T>::begin() {
	previous = 0;
	current = theList->head;
	return (current != 0);
}

template <class T>
T& ListIterator<T>::operator() () throw (NoSuchElement) {
	if (current == 0) {
		throw NoSuchElement();
	}
	return current->value;
}

template <class T>
bool ListIterator<T>::end() {
	if (current == 0) {
		if (previous != 0) {
			current = previous->next;
		}
	}
	return (current == 0);
}

template <class T>
bool ListIterator<T>::operator++ () {
	if (current == 0) {
		if (previous == 0) {
			current = theList->head;
		} else {
			current = previous->next;
		}
	} else {
		previous = current;
		current = current->next;
	}
	return (current != 0);
}

template <class T>
void ListIterator<T>::operator= (T val) throw (NoSuchElement) {
	if (current == 0) {
		throw NoSuchElement();
	}
	current->value = val;
}

#endif /* LINKEDLIST_H_ */
