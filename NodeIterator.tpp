namespace MTL{

template <typename T>
iterator<T>::iterator(Node<T>* node)
{
	current = node;
}

template <typename T>
T& iterator<T>::operator*(void) const
{
	//TODO ensure that cast works, do we need to use a keyword to force the order of the
	//members?
	return ((Node<T>*)current)->item;
}

}
