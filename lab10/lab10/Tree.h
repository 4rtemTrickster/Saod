#pragma once
#include <list>

template<typename T1>
class Tree
{
public:
	template<typename T2>
	class Node
	{
	private:
		T2 data_;
		std::list<Node*> next_nodes_list_;

	public:
		Node(T2 data);
	};

	void add_node(T1 data, Node<T1>& node);

	Node<T1>& get_root();

private:
	Node<T1> *root_ = nullptr;
	
};

template <typename T1>
template <typename T2>
Tree<T1>::Node<T2>::Node(T2 data)
{
	this->data_ = data;
}

template <typename T1>
void Tree<T1>::add_node(T1 data, Node<T1>& node)
{
	if(this->root_ == nullptr)
		this->root_ = new Node<T1>(data);
	else
		node->next_nodes_list_.push_back(new Node<T1>(data));
}

template <typename T1>
typename Tree<T1>::template Node<T1>& Tree<T1>::get_root()
{
	return this->root_;
}