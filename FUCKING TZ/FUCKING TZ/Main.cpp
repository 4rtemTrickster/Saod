#include "MyTable.h"

std::vector <std::string> text =
{
	"First line KeyWord1 lalalala",
	"Second line dont contains KeyWord2 ketwords KeyWord2",
	"Third line contains 2 key word's KeyWord2 and keyWord3"
};

std::vector<std::string> kwstr_vector = { "KeyWord1" , "KeyWord2", "keyWord3" };

int main()
{
	MyTable::Table::AddKeyWordToKeyWordVector(kwstr_vector[0], { 0 });
	MyTable::Table::AddKeyWordToKeyWordVector(kwstr_vector[1], { 2,3 });
	MyTable::Table::AddKeyWordToKeyWordVector(kwstr_vector[2], { 2,3 });

	MyTable::Table::PrintKeyWordsList();

	MyTable::Table mt;

	mt.ProcessNewString(text[0]);
	mt.ProcessNewString(text[1]);
	mt.ProcessNewString(text[2]);

	mt.countKword(kwstr_vector[1]);

	return 0;
}