#include "Deque.h"
#include <iostream>


template <typename T>
my_deque::deque<T>::deque()
{
	this->count_of_elements_ = 1;
	this->arr_ = static_cast<T*>(std::malloc(sizeof(T)*this->count_of_elements_));
	this->arr_[0] = static_cast<T>(NULL_ELEMENT);
}

template <typename T>
my_deque::deque<T>::~deque()
{
	std::free(this->arr_);
	this->arr_ = nullptr;
}

template <typename T>
my_deque::my_error my_deque::deque<T>::push_back(T value)
{
	try
	{
		if (this->arr_[0] == NULL_ELEMENT)
		{
			this->arr_[0] = value;
			return GOOD;
		}

		T *tmp = static_cast<T*>(std::malloc(sizeof(T)*this->count_of_elements_));
		for (size_t i = 0; i < this->count_of_elements_; i++)
			tmp[i] = this->arr_[i];

		this->arr_ = static_cast<T*>(std::realloc(this->arr_, sizeof(T)*++this->count_of_elements_));

		for (size_t i = 0; i < this->count_of_elements_ - 1; i++)
			this->arr_[i] = tmp[i];

		this->arr_[this->count_of_elements_ - 1] = value;

		std::free(tmp);

		return GOOD;
	}
	catch (...)
	{
		return ERROR;
	}
}

template <typename T>
my_deque::my_error my_deque::deque<T>::push_front(T value)
{
	try
	{
		if (this->arr_[0] == NULL_ELEMENT)
		{
			this->arr_[0] = value;
			return GOOD;
		}

		T *tmp = static_cast<T*>(std::malloc(sizeof(T)*this->count_of_elements_));
		for (size_t i = 0; i < this->count_of_elements_; i++)
			tmp[i] = this->arr_[i];

		this->arr_ = static_cast<T*>(std::realloc(this->arr_, sizeof(T)*++this->count_of_elements_));

		this->arr_[0] = value;

		for (size_t i = 1, j = 0; j < this->count_of_elements_ - 1; i++, j++)
			this->arr_[i] = tmp[j];

		std::free(tmp);
		return  GOOD;


	}
	catch (...)
	{
		return  ERROR;
	}
}

template <typename T>
T my_deque::deque<T>::pop_back()
{
	if (this->arr_[this->count_of_elements_ - 1] == NULL_ELEMENT)
		return static_cast<T>(ERROR);

	T *tmp = static_cast<T*>(std::malloc(sizeof(T) * this->count_of_elements_));
	T ret_el;
	ret_el = this->arr_[this->count_of_elements_ - 1];

	for (size_t i = 0; i < this->count_of_elements_ - 1; i++)
		tmp[i] = this->arr_[i];

	this->arr_ = static_cast<T*>(std::realloc(this->arr_, sizeof(T) * --this->count_of_elements_));

	for (size_t i = 0; i < this->count_of_elements_; i++)
		this->arr_[i] = tmp[i];

	delete[] tmp;
	return ret_el;
}

template <typename T>
T my_deque::deque<T>::pop_front()
{
	if (this->arr_[this->count_of_elements_ - 1] == NULL_ELEMENT)
		return static_cast<T>(ERROR);
	
	T *tmp = static_cast<T*>(std::malloc(sizeof(T) * this->count_of_elements_));
	T ret_el;
	ret_el = this->arr_[0];

	for (size_t i = 1, j = 0; j < this->count_of_elements_ -1; i++, j++)
		tmp[j] = this->arr_[i];

	this->arr_ = static_cast<T*>(std::realloc(this->arr_, sizeof(T) * --this->count_of_elements_));

	for (size_t i = 0; i < this->count_of_elements_; i++)
		this->arr_[i] = tmp[i];

	delete[] tmp;
	return ret_el;
}

template <typename T>
T my_deque::deque<T>::look_at_front()
{
	if (this->arr_[this->count_of_elements_ - 1] == NULL_ELEMENT)
		return static_cast<T>(ERROR);
	return this->arr_[0];
}

template <typename T>
T my_deque::deque<T>::look_at_back()
{
	if (this->arr_[this->count_of_elements_ - 1] == NULL_ELEMENT)
		return static_cast<T>(ERROR);
	return this->arr_[count_of_elements_ - 1];
}

template <typename T>
size_t my_deque::deque<T>::size()
{
	if (this->arr_[0] == NULL_ELEMENT)
		return 0;
	return this->count_of_elements_;
}

template <typename T>
my_deque::my_error my_deque::deque<T>::clear()
{
	try
	{
		std::free(this->arr_);
		this->arr_ = static_cast<T*>(std::malloc(sizeof(T)));
		count_of_elements_ = 1;
		this->arr_[0] = NULL_ELEMENT;
		return GOOD;
	}
	catch (...)
	{
		return ERROR;
	}
}