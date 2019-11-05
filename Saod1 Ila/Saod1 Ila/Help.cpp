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
		int item; // ������ ����������� �������� 
		size_t sw;
		switch (mode)
		{
		case AV:
			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� ������� 
				item = counter - 1; // ������ ����������� �������� ������� 
				while (item >= 0 && arrayPtr[item].Average < temp.Average) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ �������� 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� ������� 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		case NAME:
			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� ������� 
				item = counter - 1; // ������ ����������� �������� ������� 
				while (item >= 0 && arrayPtr[item].Name[0] > temp.Name[0]) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ �������� 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� ������� 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		case SNAME:
			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� ������� 
				item = counter - 1; // ������ ����������� �������� ������� 
				while (item >= 0 && arrayPtr[item].Surname[0] > temp.Surname[0]) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ �������� 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� ������� 
					arrayPtr[item] = temp;
					item--;
				}
			}
			break;
		case MARK:
			do
			{
				std::cout << "������� �� ����� ������ �������������:\n1-����������������\n2-����������� ���\n3-�����������" << std::endl;
				std::cin >> sw;
			} while (sw < 1 || sw > 3);

			for (int counter = 1; counter < length; counter++)
			{
				temp = arrayPtr[counter]; // �������������� ��������� ���������� ������� ��������� �������� ������� 
				item = counter - 1; // ������ ����������� �������� ������� 
				while (item >= 0 && arrayPtr[item].MarksArr[sw] < temp.MarksArr[sw]) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ �������� 
				{
					arrayPtr[item + 1] = arrayPtr[item]; // ������������ ��������� ������� 
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
		std::cout << "������: ";
		for (size_t j = 0; j < 3; j++)
			std::cout << " " << arr[i].MarksArr[j];
		
		std::cout << "\n������� ����:" << arr[i].Average;
		std::cout << std::endl << std::endl;
	}
}