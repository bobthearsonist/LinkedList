namespace MTL{

template <typename T>
iterator<T>::iterator(Node<T>* node)
{
	current = node;
}

template <typename T>
T& iterator<T>::operator*(void) const
{
	return static_cast<Node<T>*>(current)->item;
}

}
