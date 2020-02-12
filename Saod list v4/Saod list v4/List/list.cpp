#include "list.h"

template <typename T1>
template <typename T2>
my_list::list<T1>::node<T2>::node(T2 data, node* ptr_next)
{
	this->data = data;
	this->ptr_next = ptr_next;
}

template <typename T1>
my_list::list<T1>::list()
{
	this->head = nullptr;
}

template <typename T1>
my_list::list<T1>::~list()
{
	this->clear();
}

template <typename T1>
void my_list::list<T1>::push_back(T1 data)
{
	if (this->head == nullptr)
		this->head = new node<T1>(data);
	else
	{
		node<T1> *current = this->head;

		while (current->ptr_next != nullptr)
			current = current->ptr_next;

		current->ptr_next = new node<T1>(data);
	}

	++this->size;
}

template <typename T1>
void my_list::list<T1>::push_front(T1 data)
{
	this->head = new node<T1>(data, this->head);
	++this->size;
}

template <typename T1>
T1 my_list::list<T1>::pop_front()
{
	if (this->head == nullptr)
		throw std::runtime_error("head == nullptr");

	T1 ret = this->head->data;

	node<T1> *tmp = this->head;

	this->head = this->head->ptr_next;
	delete tmp;
	--this->size;

	return ret;
}

template <typename T1>
T1 my_list::list<T1>::pop_back()
{
	if (this->head == nullptr)
		throw std::runtime_error("head == nullptr");

	node<T1> *prev = this->head;

	for (size_t i = 0; i < this->size - 2; i++)
		prev = prev->ptr_next;

	node<T1> *ret = prev->ptr_next;

	T1 ret_data = ret->data;

	delete ret;

	prev->ptr_next = nullptr;

	--this->size;

	return ret_data;
}

template <typename T1>
void my_list::list<T1>::delete_front()
{
	if (this->head == nullptr)
		throw std::runtime_error("head == nullptr");

	node<T1> *tmp = this->head;

	this->head = this->head->ptr_next;

	delete tmp;
	--this->size;
}

template <typename T1>
void my_list::list<T1>::remove(size_t index)
{
	if (index == 0)
		this->delete_front();
	else
	{
		node<T1> *prev = this->head;

		for (size_t i = 0; i < index - 1; i++)
			prev = prev->ptr_next;

		node<T1> *to_del = prev->ptr_next;

		prev->ptr_next = to_del->ptr_next;

		delete to_del;

		--this->size;
	}
}

template <typename T1>
void my_list::list<T1>::insert(T1 data, size_t index)
{
	if (index > this->size)
		throw std::runtime_error("out of range");

	if (index == 0)
		this->push_front(data);
	else
	{
		node<T1> *prev = this->head;

		for (size_t i = 0; i < index - 1; i++)
			prev = prev->ptr_next;

		prev->ptr_next = new node<T1>(data, prev->ptr_next);

		++this->size;
	}
}

template <typename T1>
void my_list::list<T1>::clear()
{
	while (this->size)
		this->delete_front();
}

template <typename T1>
T1& my_list::list<T1>::operator[](const size_t index)
{
	if (index > this->size)
		throw std::runtime_error("out of range!");

	size_t counter = 0;
	node<T1> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->ptr_next;
		++counter;
	}
}

template <typename T1>
bool my_list::list<T1>::operator<(list<T1> const& other)
{
	return this->size < other.size;
}

template <typename T1>
bool my_list::list<T1>::operator>(list<T1> const& other)
{
	return this->size > other.size;
}


template <typename T1>
void my_list::list<T1>::sort(list<T1>  &first, list<T1>  &second)
{
	list<T1> ret;
	int n1 = 0;
	int n2 = 0;
	size_t len1 = first.size;
	size_t len2 = second.size;

	while (len1 && len2)
	{
		if (first[n1] < second[n2])
		{
			ret.push_back(first[n1]);
			n1++;
			--len1;
		}
		else
		{
			ret.push_back(second[n2]);
			n2++;
			--len2;
		}
	}
	if (len1 == 0)
	{
		for (size_t i = 0; i < len2; i++)
			ret.push_back(second[n2++]);
	}
	else if (len2 == 0)
	{
		for (size_t i = 0; i < len1; i++)
			ret.push_back(first[n1++]);
	}

	for (size_t i = 0; i < ret.size; i++)
		std::cout << ret[i] << " ";
}

template <typename T1>
size_t my_list::list<T1>::get_size() const
{
	return this->size;
}
