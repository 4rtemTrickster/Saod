#include <iostream>
#include "Deque/Deque.h"
#include "Deque/Deque.cpp"
#include "Product/Product.h"

void Saod_task()
{
	my_deque::deque<int> my;

	task::product my_product;

	for(size_t i = 0; i < my_product.get_parts_count(); i++)
		if (my_product.get_subparts_status_at(i) != nullptr)
			my.push_back(my_product.get_subpart_id_at(i));

	std::cout << my.look_at_front() << std::endl;
	std::cout << my.look_at_back() << std::endl;
}



int main()
{

	Saod_task();
	
	
	
	system("pause");
	return 0;
}