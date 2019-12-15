#include "tree.h"

template <typename T1>
template <typename T2>
tree<T1>::node<T2>::node(node<T2> *parent_ptr, T2 data, size_t number_of_descendants, std::vector<node*> pointers)
{
	this->data_ = data;
	this->pointers_ = pointers;
	this->number_of_descendants_ = number_of_descendants;
	this->parent_ptr_ = parent_ptr;
}

template <typename T1>
tree<T1>::tree() {};

template <typename T1>
void tree<T1>::add_node(T1 data, size_t number_of_descendants, node<T1> *ptr)
{
	if (this->root_ == nullptr)
		this->root_ = new node<T1>(this->root_, data, number_of_descendants);
	else
	{
		node<T1> *current = this->root_;


	}
}
