/*
 * basicnode.h
 *
 *  Created on: Feb 20, 2016
 *      Author: Martin
 */

#ifndef BASIC_NODE_H_
#define BASIC_NODE_H_

namespace MTL {

struct basic_node {
	basic_node * next;
};

class basic_node_iterator
{
	public:
		basic_node_iterator(basic_node* current=NULL)
		{
				this->current = current;
		}

		basic_node_iterator(basic_node_iterator* target)
		{
			this->current = target->current;
		}

		basic_node_iterator& operator++(void)
		{
			current = current->next;
			return *this;
		}

		basic_node_iterator operator++(int)
		{
			basic_node_iterator old(current);
			current = current->next;
			return old;
		}

		bool operator!=(const basic_node_iterator& comparand) const
		{
			return this->current != comparand.current;
		}

		bool operator==(const basic_node_iterator& comparand) const
		{
			return this->current == comparand.current;
		}
	private:
		basic_node* current;
};

} /* namespace MTL */

#endif /* BASIC_NODE_H_ */
