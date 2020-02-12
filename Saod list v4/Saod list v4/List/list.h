#pragma once

namespace my_list
{
	template<typename T1>
	class list
	{
		template<typename T2>
		class node
		{
		public:
			T2 data;
			node *ptr_next;
			
			node(T2 data = T2(), node* ptr_next = nullptr);
		};

		node<T1> *head;
		size_t size = 0;
		
	public:

		list();
		~list();


		void push_back(T1 data);
		void push_front(T1 data);
		T1 pop_front();
		T1 pop_back();
		void delete_front();
		void remove(size_t index); 
		void insert(T1 data, size_t index);
		void clear();

		T1& operator[](const size_t index);
		bool operator <(list<T1> const &other);
		bool operator >(list<T1> const &other);
		//list<T1>& operator=(const list<T1> &other);

		static void sort(list<T1>  &first, list<T1>  &second);
		

		size_t get_size() const;
	};

	
}
