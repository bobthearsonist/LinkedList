/*
 * List.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */

#ifndef LIST_H_
#define LIST_H_

#include "Node.h"

namespace MTL {

template<typename T>
class List {
public:
	List<T>();
	List<T>(Node<T>);
	List<T>(const List<T>&);
	~List();

	Node<T>* head;

	//list operations
	bool empty(void) const;
	int size(void) const;
	void clear(void);

	//item operations
	void push_front(/*TODO const*/ T& item) { insert(head, item); };
	void pop_front(void);
	T& front(void);

	//iterator operations
	class iterator : public Node<T>::iterator {
	public:
		iterator(Node<T>* initial = NULL) : Node<T>::iterator(initial) {}
	};
	/*TODO iterator*/void insert(iterator where, /*TODO const*/ T& item);

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(NULL); }

private:
	//unsigned means it can never be negative so we dont have to check
	unsigned int count;

};

} /* namespace MTL */
#include "List.tpp"
#endif /* LIST_H_ */
