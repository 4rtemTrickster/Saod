#pragma once
#include <list>

template<typename T>
class Tree
{
public:
	class Node
	{
	private:
		T data_;
		std::list<Node*> next_nodes_list_;

	public:
		Node(const T& data);

		friend class Tree;
	};

	void add_node(const T& data, Node *node);

	      Node *get_root()       { return root_; }
	const Node *get_root() const { return root_; }

private:
	Node *root_ = nullptr;
	
};

template <typename T>
Tree<T>::Node::Node(const T& data)
	: data_(data)
{
}

template <typename T>
void Tree<T>::add_node(const T& data, Node *node)
{
	if(this->root_ == nullptr)
		this->root_ = new Node(data);
	else
		node->next_nodes_list_.push_back(new Node(data));
}
