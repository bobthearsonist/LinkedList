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
bool List<T>::empty(void) const
{
	return head == NULL;
}

template <typename T>
const T& List<T>::peek(void) const
{
	return head->item;
}

//my insert has an insert of O(N), on top of the O(N) of setting the input iterator
//to the desired location, from iterating to find --iterator, making insert an O(N^2) operation.
template <typename T>
/*iterator*/ void List<T>::insert(iterator where, /*TODO const*/T& item)
{
	//todo check that interator is within container!
	
	//we need the node prior to the current location
	iterator prev = head;
	for (iterator i = head; i != where;++i)
	{
		prev = i;
	}
	if(prev == this->begin())
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
void List<T>::remove(void)
{
	assert(!empty());
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}
} /* namespace MTL */
