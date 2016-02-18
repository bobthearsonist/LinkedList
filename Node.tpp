namespace MTL
{
	template <typename T>
	Node<T>::Node(const T& item, Node* next)
	{
		this->item = item;
		this->next = next;
	}

	template <typename T>
	Node<T>::Node(const Node& node)
	{
		this->item = node.item;
		this->next = next;
	}

	template <typename T>
	Node<T>::~Node<T>()
	{
		delete item;
		delete next;//delete the pointer
	}

	template <typename T>
	void Node<T>::set(T item)
	{
		this->item = item;
	}

	template <typename T>
	void Node<T>::set(Node* next)
	{
		this->next = next;
	}

	template <typename T>
	Node* Node<T>::get(void)
	{
		return this->next;
	}

	template <typename T>
	void Node<T>::operator=(const Node& node)
	{
		this->item = node.item;
		this->next = node.next;
	}
}
