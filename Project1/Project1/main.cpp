#include <iostream>
#include "Deque.h"
#include "Deque.cpp"



int main()
{

	my_deque::deque<int> my;

	if (my.push_back(5) == my_deque::ERROR)
		std::cout << "!!!" << std::endl;
	if (my.push_back(6) == my_deque::ERROR)
		std::cout << "!!!" << std::endl;
	if (my.push_back(7) == my_deque::ERROR)
		std::cout << "!!!" << std::endl;

	my.clear();

	if (my.push_back(5) == my_deque::ERROR)
		std::cout << "!!!" << std::endl;
	if (my.push_back(6) == my_deque::ERROR)
		std::cout << "!!!" << std::endl;
	if (my.push_back(7) == my_deque::ERROR)
		std::cout << "!!!" << std::endl;

	std::cout << my.look_at_front() << " " << my.look_at_back() << std::endl;

	my.push_front(3);

	std::cout << my.look_at_front() << " " << my.look_at_back() << std::endl;

	std::cout << my.pop_front() << std::endl;

	std::cout << my.look_at_front() << " " << my.look_at_back() << std::endl;

	system("pause");
	return 0;
}