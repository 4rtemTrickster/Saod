#pragma once

#include  <iostream>
#include <vector>


template<typename T1>
class tree
{
private:
	template<typename T2>
	class node
	{
	private:
		T2 data_;
		std::vector<node<T2>*> pointers_;
		node<T2> *parent_ptr_;
		size_t number_of_descendants_;
	public:
		node(node<T2> *parent_ptr, T2 data = T2(), size_t number_of_descendants = 0, std::vector<node*> pointers = std::vector<node*>());
	};

	node<T1> *root_ = nullptr;

public:
	tree();

	void add_node(T1 data, size_t number_of_descendants, node<T1> *ptr = nullptr);
	
};