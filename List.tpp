/*
 * List.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */
#include <cassert>
namespace MTL {

template <typename T>
List<T>::List()
{
	count = 0;
	head = NULL;
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
	clear();
}

template <typename T>
bool List<T>::empty(void) const
{
	return count == 0;
}

template <typename T>
void List<T>::check_underflow(void)
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
	return head->item;
}

//my insert has an insert of O(N), on top of the O(N) of setting the input iterator
//to the desired location, from iterating to find --iterator, making insert an O(N^2) operation.
template <typename T>
/*iterator*/ void List<T>::insert(iterator where, const T& item)
{
	//todo check that interator is within container!
	
	//we need the node prior to the current location
	iterator prev = begin();
	for (iterator i = begin(); i != where;++i)
	{
		prev = i;
	}
	if (prev == this->begin())
	{
		head = new Node<T>(item, head);
	}
	else
	{
		basic_node* pNext = prev.getNode()->next;
		prev.getNode()->next = new Node<T>(item, where.getNode());
	}
	
	count++;
	
	//return prev;
}

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
	Node<T>* temp = head;
	head = static_cast<Node<T>*>(head->next);
	delete temp;
	
	//if it was all done properly decrement the count
	--count;
}

template <typename T>
void List<T>::clear(void)
{
	//valid for empty list so no checking is done
	while(count)
	{
		pop_front();
	}
}

} /* namespace MTL */
