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

namespace MTL {

template <typename T>
class Node {
public:
	Node<T>(const T&, Node*);
	Node<T>(const Node&);
	~Node<T>();

	void set(const T);
	void set(Node*);

	T get(void) const;
	Node* get(void);
	Node* get(void) const;

	void operator=(const Node&);

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

namespace MTL{
template <typename T>
class iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
	iterator(Node<T>* initial = NULL);

	T& operator*(void) const;
	bool operator==(const iterator&) const;
	bool operator!=(const iterator&) const;

	iterator& operator++(void);
	iterator operator++(int);
private:
	T* current;
};
} /* namespace MTL */
#include "NodeIterator.tpp"
#endif /* NODE_H_ */
