/*
 * Node.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */

#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>

namespace MTL {

template <typename T>
class Node {
public:
	Node<T>(const T&, Node*);
	~Node<T>();

	void set(const T);
	void set(Node*);

	T get(void) const;
	Node* get(void);
	Node* get(void) const;

private:
	T item;
	Node* next;
};

template <typename T>
T Node<T>::get(void) const
{
	return this->item;
}
} /* namespace MTL */
#include "Node.tpp"
#endif /* NODE_H_ */
