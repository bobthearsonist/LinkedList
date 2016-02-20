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

template <typename T>
void List<T>::insert(T item)
{
	head = new Node<T>(item,head);
	count++;
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
