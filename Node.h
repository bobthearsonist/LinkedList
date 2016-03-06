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
	T item;
	Node(T item, Node<T>* next)
	{
		this->item = item;
		this->next = next;
	}
};
} /* namespace MTL */

namespace MTL{
template <typename T>
class iterator : basic_node_iterator
{
public:
	iterator(Node<T>* initial = NULL);
	T& operator*(void) const;
	T& operator++(void);
private:
	basic_node* current;
};
} /* namespace MTL */
#include "NodeIterator.tpp"
#endif /* NODE_H_ */
