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
		Node(const Node<T>* next) : Node() { this->next = next; }
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
		//TODO get rid of this conversion constructor
		Node(T& item, basic_node* next)
		{
			this->item = item;
			this->next = next;
		}
		Node(T& item, const basic_node* next)
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
	void push_front(const T& item)
	{
		insert(begin(), item);
	};
	void pop_front(void);
	T& front(void);

	//node operations
	//returns a reference to the pointer to the next item of node (so that it can be modified)
	static Node<T>*& next_node(Node<T>* node)
	{
		//blatantly stolen straight from the stl
		return (Node<T>*&)node->next;
	}

	//list iterator classes
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
	class const_iterator : public const_basic_node_iterator
	{
		const_iterator(const Node<T>* initial = NULL) : const_basic_node_iterator(initial) {}
		const T& operator*(void) const
		{
			const Node<T>* p_node = static_cast<const Node<T>*>(current);
			return p_node->item;
		}
		const T* operator->(void) const
		{
			return (**this);
		}
	};
	//iterator operations
	/*TODO iterator*/void insert(iterator where, const T& item);

	iterator begin() const { return iterator(this->next_node(head)); }
	iterator end() const { return iterator(head); }
	const_iterator cbegin() const { return const_iterator(head->next); }
	const_iterator cend() const { return const_iterator(head); }

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
