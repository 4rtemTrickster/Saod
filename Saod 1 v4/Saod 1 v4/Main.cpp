#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> c;

std::vector<int> Merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> Merged;

	for (size_t i = 0; i < a.size(); i++)
		Merged.push_back(a.at(i));
	for (size_t i = 0; i < b.size(); i++)
		Merged.push_back(b.at(i));

	return Merged;
}

void insertionSort(std::vector<int> &Vector) 
{
	int	temp; 
	int	item; // индекс предыдущего элемента
	for (int counter = 1; counter < Vector.size(); counter++)
	{
		temp = Vector.at(counter); 
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && Vector.at(item) > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			Vector.at(item + 1) = Vector.at(item); 
			Vector.at(item) = temp;
			item--;
		}
	}
}

void ShellSort()
{
	int i, j, step;
	int tmp;
	for (step = c.size() / 2; step > 0; step /= 2)
		for (i = step; i < c.size(); i++)
		{
			tmp = c.at(i);
			for (j = i; j >= step; j -= step)
			{
				if (tmp < c.at(j - step))
					c.at(j) = c.at(j - step);
				else
					break;
			}
			c.at(j) = tmp;
		}
}

void Myqsort(int b, int e)
{
	int l = b, r = e;
	int tmp;
	int piv = c[(l + r) / 2]; // Опорный элемент средний
	while (l <= r)
	{
		while (c[l] < piv)
			l++;
		while (c[r] > piv)
			r--;
		if (l <= r)
		{
			tmp = c.at(l++);
			c.at(l - 1) = c.at(r--);
			c.at(r+1) = tmp;
		}
	}
	if (b < r)
		Myqsort(b, r);
	if (e > l)
		Myqsort(l, e);
}

void UnDup(std::vector<int> &Vector)
{
	for (size_t i = 0; i < Vector.size() - 1; i++)
		while (Vector.at(i) == Vector.at(i + 1))
			Vector.erase(Vector.begin() + (i + 1));
}

int main()
{
	std::vector<int> a = { 1, 2, 3, 4, 6};
	std::vector<int> b = { 1, 2, 4, 7, 8 };


	std::cout << "a[] = ";
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << a.at(i);
		std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "b[] = ";
	for (size_t i = 0; i < b.size(); i++)
	{
		std::cout << b.at(i);
		std::cout << " ";
	}
	std::cout << std::endl;



	c = Merge(a, b);
	//insertionSort(c);
	//Myqsort(0, c.size() - 1);
	ShellSort();
	UnDup(c);


	std::cout << "c[] = ";
	for (size_t i = 0; i < c.size(); i++)
	{
		std::cout << c.at(i);
		std::cout << " ";
	}
	std::cout << std::endl;



	system("pause");
	return 0;
}