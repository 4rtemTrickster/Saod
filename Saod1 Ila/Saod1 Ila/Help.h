#pragma once
#include <iostream>
#include <string>
#include <fstream>

struct Student
{
	std::string Name;
	std::string Surname;

	size_t MarksArr[3];
	double Average = 0;

};

enum Mode
{
	AV,
	NAME,
	SNAME,
	MARK
};

void ReadData(Student *arr, size_t CountOfStudents);
void average(Student *arr, size_t CountOfStudents);
void insertionSort(Student *arrayPtr, int length, Mode mode);
void PrintStudentsArr(Student *arr, size_t CountOfStudents);