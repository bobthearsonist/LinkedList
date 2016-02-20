namespace MTL
{
	template <typename T>
	Node<T>::Node(const T& item, Node* next)
	{
		this->item = item;
		this->next_node = next_node;
	}

	template <typename T>
	Node<T>::Node(const Node& node)
	{
		this->item = node.item;
		this->next_node = next_node;
	}

	template <typename T>
	Node<T>::~Node<T>()
	{
		delete item;
		delete next_node;//delete the pointer
	}

	template <typename T>
	void Node<T>::set(T item)
	{
		this->item = item;
	}

	template <typename T>
	void Node<T>::set(Node* next)
	{
		this->next_node = next_node;
	}

	//this is not a const function because the return value can be used to modify the list
	template <typename T>
	Node<T>* Node<T>::next(void)
	{
		return this->next_node;
	}

	template <typename T>
	const Node<T>* Node<T>::next(void) const
	{
		return this->next_node;
	}

	template <typename T>
	T& Node<T>::data(void)
	{
		return this->item;
	}

	template <typename T>
	void Node<T>::operator=(const Node& node)
	{
		this->item = node.item;
		this->next_node = node.next_node;
	}
}
