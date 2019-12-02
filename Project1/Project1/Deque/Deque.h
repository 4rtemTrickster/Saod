#pragma once


namespace my_deque
{
#define NULL_ELEMENT 9999999

	enum  my_error
	{
		GOOD = 1,
		ERROR = 0
	};

	template<typename T>
	class deque
	{
	private:
		T *arr_;
		size_t count_of_elements_;

	public:
		deque();
		~deque();

		my_error push_back(T value);
		my_error push_front(T value);

		T pop_back();
		T pop_front();
		
		T look_at_front();
		T look_at_back();

		size_t size();
		my_error clear();

	};
}

