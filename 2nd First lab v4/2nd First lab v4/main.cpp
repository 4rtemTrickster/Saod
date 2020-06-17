#include <iostream>
#define SIZE (2*m+1)

template<typename T>
void bubble_sort(T array[], std::size_t size)
{
	for (std::size_t idx_i = 0; idx_i < size - 1; idx_i++)
		for (std::size_t idx_j = 0; idx_j < size - idx_i - 1; idx_j++)
			if (array[idx_j + 1] < array[idx_j])
				std::swap(array[idx_j], array[idx_j + 1]);
}

int main()
{
	int m;
	int* arr = nullptr;

	std::cout << "Enter m:";
	std::cin >> m;

	arr = new int[SIZE];

	std::cout << "Enter the nubers:" << std::endl;
	for (size_t i = 0; i < SIZE; i++)
		std::cin >> arr[i];

	std::cout << "You enter:";
	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	bubble_sort(arr, SIZE);

	std::cout << "Sorted:";
	for (size_t i = 0; i < SIZE; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "Med is: " << arr[m];


	return 0;
}