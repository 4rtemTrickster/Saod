#include "Table.h"

void myTable::String::Word::Show()
{
	std::cout << "Word: " << this->word << std::endl;
	std::cout << "String numbers: ";
	for (auto var : this->string_id)
		std::cout << var << " ";
	std::cout << std::endl;
}

void myTable::String::addKword(std::string kWord, uint count)
{
	this->string += kWord;
	this->kmap.emplace(kWord, count);
}

uint myTable::String::searchKword(std::string kWord)
{
	for (auto var : this->kmap)
	{
		Word tmp = var.first;

		if (tmp.GetWord() == kWord)
			return var.second;
	}

	return 0;
}

void myTable::addString(String str, uint ID)
{
	this->strMap.emplace(ID, str);
}

uint myTable::search(std::string kWord)
{
	uint counter = 0;
	for (auto var : this->strMap)
	{
		String tmp = var.second;
		uint tmpCount;
		if (tmpCount == tmp.searchKword(kWord))
			counter += tmpCount;
	}
	return counter;
}
