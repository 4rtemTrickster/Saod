#include "Help.h"


int main()
{
	setlocale(LC_ALL, "ru");

	size_t CountOfStudents;
	size_t sw;

	do
	{
		std::cout << "Введите кол-во студентов(Не больше 10):";
		std::cin >> CountOfStudents;
	} while (CountOfStudents < 1 || CountOfStudents > 10);


	Student *StudentArr = new Student[CountOfStudents];
	
	ReadData(StudentArr, CountOfStudents);
	average(StudentArr, CountOfStudents);

	do
	{
		std::cout << "Выберите действие:\n1-Отсортировать по среднему баллу\n2-Сортировка по имени\n3-Сорировка по Фамилии\n4-Сортировка по предмету\n0-Выход из программы";
		std::cin >> sw;

		switch (sw)
		{
		case 1:
			insertionSort(StudentArr, CountOfStudents, AV);
			PrintStudentsArr(StudentArr, CountOfStudents);
			break;
		case 2:
			insertionSort(StudentArr, CountOfStudents, NAME);
			PrintStudentsArr(StudentArr, CountOfStudents);
			break;
		case 3:
			insertionSort(StudentArr, CountOfStudents, SNAME);
			PrintStudentsArr(StudentArr, CountOfStudents);
			break;
		case 4:
			insertionSort(StudentArr, CountOfStudents, MARK);
			PrintStudentsArr(StudentArr, CountOfStudents);
			break;
		}
	} while (sw);
	


	system("pause");
	return 0;
}