/*
 * Node.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */

#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>
#include <iterator>

#include "basic_node.h"

namespace MTL {
template <typename T>
struct Node : public basic_node {
public:
	T item;
	Node(T item, Node<T>* next)
	{
		this->item = item;
		this->next = next;
	}

	class iterator : public basic_node_iterator
	{
	public:
		iterator(Node<T>* initial = NULL): basic_node_iterator(initial){}
		T& operator*(void) const;
	};
};
} /* namespace MTL */
#include "NodeIterator.tpp"
#endif /* NODE_H_ */
