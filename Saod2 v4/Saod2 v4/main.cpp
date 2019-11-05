#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 

//#define DEBUG

int main()
{
	setlocale(LC_ALL, "ru");

	std::ifstream fin;
	std::vector<int> arr;
	char *tmpS = new char[100];
	int tmpInt;
	int res = 0;



	fin.open("Data.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> tmpS;
#ifdef DEBUG
			std::cout << "Alive" << std::endl;
#endif // DEBUG
			tmpInt = std::atoi(tmpS);

			if (tmpInt)
				arr.push_back(tmpInt);
		}

		fin.close();

		delete[] tmpS;
		tmpS = nullptr;

		for (size_t i = 0; i < arr.size(); i++)
		{
			std::cout << arr.at(i) << " ";
			res += arr.at(i);
		}

		std::cout << std::endl << "Ответ: " << res << std::endl;
	}
	else
		std::cout << "Ошибка открытия файла!" << std::endl;
	





	system("pause");
	return 0;
}