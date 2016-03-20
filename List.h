/*
 * List.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef>
#include "basic_node.h"

namespace MTL {

template<typename T>
class List {

	template <typename T>
	struct Node : basic_node {

		public:
		T item;

		//TODO fancy constructor chaining
		Node() : item() { this->next = NULL; }
		Node(Node<T>* next) : Node() { this->next = next; }
		Node(T& item, Node<T>* next )
		{
			this->item = item;
			this->next = next;
		}
		Node(const T& item, Node<T>* next)
		{
			this->item = item;
			this->next = next;
		}
		Node(T& item, basic_node* next)
		{
			this->item = item;
			this->next = next;
		}
		//this allows the creation of a new node using the position of an iterator without defeating data hiding
		Node(T& item, typename List<T>::iterator it) : Node(item)
		{
			this->next = it.current;
		}
		Node(const T& item, typename List<T>::iterator it) : Node(item)
		{
			this->next = it.current;
		}
	};
public:
	List<T>();
	List<T>(Node<T>);
	List<T>(const List<T>&);
	~List();

	//list operations
	bool empty(void) const;
	int size(void) const;
	void clear(void);

	//item operations
	void push_front(/*TODO const*/ T& item) { insert(begin(), item); };
	void pop_front(void);
	T& front(void);

	//node operations
	//returns a reference to the pointer to the next item of node (so that it can be modified)
	static Node<T>*& next_node(Node<T>* node)
	{
		//blatantly stolen straight from the stl
		return (Node<T>*&)node->next;
	}

	//list iterator class
	class iterator : public basic_node_iterator {
	public:
		iterator(Node<T>* initial = NULL) : basic_node_iterator(initial) {}
		T& operator*(void) const 
		{
			return static_cast<Node<T>*>(current)->item;
		}
		T* operator->(void) const 
		{
			return (**this);
		}
		Node<T>* getNode() const
		{
			return static_cast<Node<T>*>(current);
		}
	};
	//iterator operations
	/*TODO iterator*/void insert(iterator where, T& item);
	//TODO implement const iterator

	iterator begin() { return iterator(this->next_node(head)); }
	iterator end() { return iterator(head); }

	void check_underflow(void) const;

private:
	//unsigned means it can never be negative so we dont have to check
	unsigned int count;
	//the hea
	Node<T>* head;

};

} /* namespace MTL */
#include "List.tpp"
#endif /* LIST_H_ */
