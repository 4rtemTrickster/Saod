#include <iostream>
#include "List/list.h"
#include "List/list.cpp"


/*
* Слияние двух упорядоченных массивов
* m1 - Первый массив
* m2 - Второй массив
* len_1 - Длина первого массива
* len_2 - Длина второго массива
* Возвращает объединённый массив
*/
template <typename T>
T* merge(T *m1, T* m2, int len_1, int len_2)
{
	T* ret = new T[len_1 + len_2];
	int n = 0;
	// Сливаем массивы, пока один не закончится
	while (len_1 && len_2) {
		if (*m1 < *m2) {
			ret[n] = *m1;
			m1++;
			--len_1;
		}
		else {
			ret[n] = *m2;
			++m2;
			--len_2;
		}
		++n;
	}
	// Если закончился первый массив
	if (len_1 == 0) {
		for (int i = 0; i < len_2; ++i) {
			ret[n++] = *m2++;
		}
	}
	else { // Если закончился второй массив
		for (int i = 0; i < len_1; ++i) {
			ret[n++] = *m1++;
		}
	}
	return ret;
}

int main()
{
	try
	{
		my_list::list<int> first;
		my_list::list<int> second;
		my_list::list<int> res;

		first.push_back(1);
		first.push_back(3);
		first.push_back(5);

		second.push_back(2);
		second.push_back(4);
		second.push_back(6);

		my_list::list<int>::sort(first, second);

		for (size_t i = 0; i < res.get_size(); i++)
			std::cout << res[i] << std::endl;
	}
	catch (std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}

	system("pause");
	return 0;
}