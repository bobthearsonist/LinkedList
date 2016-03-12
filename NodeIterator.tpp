#include "Node.h"
namespace MTL{

template<typename T>
Node<T>::iterator::iterator(Node<T>* initial)
{
	current = initial;
}

template <typename T>
T& Node<T>::iterator::operator*(void) const
{
	return static_cast<Node<T>*>(current)->item;
}

template <typename T>
T& Node<T>::iterator::operator++(void)
{
	return current->next;
}

}
