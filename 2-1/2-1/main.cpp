#include <iostream>
#include <ctime>
#include  "heapSort.h"
#include "my_qsort.h"

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	
	const int array_size = 200000; 
	int array1[array_size];
	


	int try_count = 0;
	double all_time = 0;
	int max_trys = 1000;

	std::cout << "Подсчет для heap сортировки, ожидайте!" << std::endl;
	
	while (try_count < max_trys)
	{
		for (int counter = 0; counter < array_size; counter++)
			array1[counter] = rand();
		
		int start_time = clock();
		heapSort(array1, array_size);
		int res_time = clock() - start_time;

		all_time += res_time;
		
		try_count++;
	}

	all_time /= max_trys;

	std::cout << "Итог:" << all_time << std::endl;

	all_time = 0;
	try_count = 0;

	std::cout << "Подсчет для быстрой сортировки, ожидайте!" << std::endl;

	while (try_count < max_trys)
	{
		for (int counter = 0; counter < array_size; counter++)
			array1[counter] = rand();

		int start_time = clock();
		qs(array1, 0, array_size - 1);
		int res_time = clock() - start_time;

		all_time += res_time;

		try_count++;
	}

	all_time /= max_trys;
	std::cout << "Итог:" << all_time << std::endl;


	
	


	system("pause");
	return 0;
}