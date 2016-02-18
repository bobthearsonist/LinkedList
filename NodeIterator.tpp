namespace MTL{

template <typename T>
iterator<T>::iterator(Node<T>* node)
{
	current = node;
}

template <typename T>
T& iterator<T>::operator*(void) const
{
	return current->item;
}

template <typename T>
bool iterator<T>::operator !=(const iterator<T>& comparand) const
{
	return this->current != comparand.current;
}

template <typename T>
bool iterator<T>::operator==(const iterator<T>& comparand) const
{
	return this->current == comparand.current;
}

template <typename T>
iterator<T> iterator<T>::operator++(int)
{
	iterator<T> old(current);
	current = current->next;
	return old;
}

template <typename T>
iterator<T>& iterator<T>::operator++(void)
{
	current = current->next;
	return *this;
}

}
