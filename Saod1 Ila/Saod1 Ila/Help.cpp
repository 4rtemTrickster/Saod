#include "Help.h"


void ReadData(Student *arr, size_t CountOfStudents)
{
	std::ifstream fin;

	fin.open("Data.txt");

	for (size_t i = 0; !fin.eof() && i < CountOfStudents; i++)
	{
		fin >> arr[i].Name;
		fin >> arr[i].Surname;
		for (size_t j = 0; j < 3; j++)
			fin >> arr[i].MarksArr[j];
	}

	fin.close();
}

void average(Student *arr, size_t CountOfStudents)
{
	for (size_t i = 0; i < CountOfStudents; i++)
	{
		for (size_t j = 0; j < 3; j++)
			arr[i].Average += arr[i].MarksArr[j];
		arr[i].Average /= 3;
	}
}

void insertionSort(Student *arrayPtr, int length, Mode mode)
{
		Student temp; 
		int item; // индекс предыдущего элемента 
		size_t sw;
		switch (mode)
		{
		case AV:
			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива 
				item = counter - 1; // индекс предыдущего элемента массива 
				while (item >= 0 && arrayPtr[item].Average < temp.Average) // пока индекс не равен 0 и предыдущий элемент массива больше текущего 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		case NAME:
			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива 
				item = counter - 1; // индекс предыдущего элемента массива 
				while (item >= 0 && arrayPtr[item].Name[0] > temp.Name[0]) // пока индекс не равен 0 и предыдущий элемент массива больше текущего 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		case SNAME:
			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива 
				item = counter - 1; // индекс предыдущего элемента массива 
				while (item >= 0 && arrayPtr[item].Surname[0] > temp.Surname[0]) // пока индекс не равен 0 и предыдущий элемент массива больше текущего 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		case MARK:
			do
			{
				std::cout << "Введите по какой оценке отсортировать:\n1-Программирование\n2-Архитектура ЭВМ\n3-Физкультура" << std::endl;
				std::cin >> sw;
			} while (sw < 1 || sw > 3);

			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива 
				item = counter - 1; // индекс предыдущего элемента массива 
				while (item >= 0 && arrayPtr[item].MarksArr[sw] < temp.MarksArr[sw]) // пока индекс не равен 0 и предыдущий элемент массива больше текущего 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		}

}

void PrintStudentsArr(Student *arr, size_t CountOfStudents)
{
	system("cls");
	for (size_t i = 0; i < CountOfStudents; i++)
	{
		std::cout << arr[i].Name << " " << arr[i].Surname << std::endl;
		std::cout << "Оценки: ";
		for (size_t j = 0; j < 3; j++)
			std::cout << " " << arr[i].MarksArr[j];
		
		std::cout << "\nСредний балл:" << arr[i].Average;
		std::cout << std::endl << std::endl;
	}
}