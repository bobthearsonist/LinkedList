/*
 * List.h
 *
 *  Created on: Feb 18, 2016
 *      Author: Martin
 */

#ifndef LIST_H_
#define LIST_H_

#include "Node.h"

namespace MTL {

template<typename T>
class List {
public:
	List<T>();
	~List();

	Node* head;
	Node* tail;

private:

};

} /* namespace MTL */
#include "List.tpp"
#endif /* LIST_H_ */
