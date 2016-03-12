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

	bool empty(void) const;
	const T& peek(void) const;
	int size(void) const;

	void insert(T item);
	void remove(void);

	class iterator : public Node<T>::iterator {
		iterator(Node<T>* = NULL) : Node<T>::iterator(Node<T>*) {}
	};

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(NULL); }

private:
	unsigned int count;

};

} /* namespace MTL */
#include "List.tpp"
#endif /* LIST_H_ */
