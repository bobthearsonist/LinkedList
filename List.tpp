/*
 * List.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */
#include <exception>
namespace MTL {

template <typename T>
List<T>::List()
{
	count = 0;
	//TODO make all empy nodes point to themselves
	Node<T>* new_head = new Node<T>();
	new_head->next = new_head;
	head = new_head;
}

template <typename T>
List<T>::List(const List<T>& target)
{
	//TODO implement a range insert
	for (iterator i = target.begin(); i != target.end();++i)
	{
		push_front(*i);
	}
}

template <typename T>
List<T>::~List()
{
	//clear the list
	clear();
	//now free the head
	delete head;
}

template <typename T>
bool List<T>::empty(void) const
{
	return count == 0;
}

template <typename T>
void List<T>::check_underflow(void) const
{
	if (empty())
	{
		throw new std::exception("underflow");
	}
}

//this is a reference to the copy of the item emplaced
template <typename T>
T& List<T>::front(void)
{
	check_underflow();
	return *begin();
}

//insert of O(N) because I am not doubly linked and must find prev
template <typename T>
/*iterator*/ void List<T>::insert(iterator where, const T& item)
{
	//todo check that interator is within container!
	
	Node<T>* where_node = static_cast<Node<T>*>(where.current);

	//we need the node prior to the current location, and must start at the belt buckle to insert at head
	iterator prev = end();
	for (iterator i = begin(); i != end() && i != where;++i,++prev)
	{
		T item = *i;
	}
	
	Node<T>* new_node = new Node<T>(item, where_node);
	Node<T>* prev_node = static_cast<Node<T>*>(prev.current);

	this->next_node(static_cast<Node<T>*>(prev.current)) = new_node;
	
	count++;
	
	//return prev;
}

//Does not include belt buckle node
template <typename T>
int List<T>::size(void) const
{
	return this->count;
}

template <typename T>
void List<T>::pop_front(void)
{
	check_underflow();
	
	//handle deleting the item
	//assignments must be done as a Node to properly delete item
	//TODO see if you can do this without the overhead of the iterator by using head directly
	Node<T>* temp = static_cast<Node<T>*>(begin().current);

	head->next = this->next_node(temp);
	delete temp;
	
	//if it was all done properly decrement the count
	--count;
}

template <typename T>
void List<T>::clear(void)
{
	//valid for empty list so no checking is done
	
	while(!empty())
	{
		pop_front();
	}
}

} /* namespace MTL */
