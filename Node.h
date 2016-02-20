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
class Node : basic_node {
public:
	Node<T>(const T&, Node*);
	Node<T>(const Node&);
	~Node<T>();

	void set(const T);
	void set(Node*);
	T& data(void);
	Node<T>* next(void);

	//const T& get(void) const;
	//const Node<T>* get(void) const;
	//Node<T>* get(void) const;


	void operator=(const Node&);

private:
	T item;
	Node<T>* next_node;
};
} /* namespace MTL */
#include "Node.tpp"

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
