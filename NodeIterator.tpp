#include "Node.h"
namespace MTL{

template <typename T>
T& Node<T>::iterator::operator*(void) const
{
	return static_cast<Node<T>*>(current)->item;
}

}
