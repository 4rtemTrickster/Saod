#include <iostream>
#include "unordered_map.hpp"
#include <time.h>
#include <fstream>

#define REWRITE

int main()
{
	srand(time(NULL));

	ska::unordered_map<int, int> myMap;
	int i = 0;
	int tmp;

	std::fstream fs;

	try
	{
		fs.open("read.txt",std::ios_base::in | std::ios_base::out);

#ifdef REWRITE
		for (size_t i = 0; i < 20; i++)
			fs << rand() % 10 << " ";
#endif
		fs.seekg(0);
		while (fs >> tmp)
		{
			myMap.emplace(i, tmp);
			i++;
		}

		fs.close();

	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	ska::flag = true;

	if ( myMap.end() == myMap.find(5) )
		std::cout << "Not fiend" << std::endl;


	return 0;
}