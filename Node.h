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
struct Node : protected basic_node {
	T item;
};
} /* namespace MTL */

namespace MTL{
template <typename T>
class iterator : basic_node_iterator
{
public:
	iterator(Node<T>* initial = NULL);
	T& operator*(void) const;
private:
	basic_node* current;
};
} /* namespace MTL */
#include "NodeIterator.tpp"
#endif /* NODE_H_ */
