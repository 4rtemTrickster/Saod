#include "MyTable.h"

namespace MyTable
{
	std::vector<Table::Kword> Table::kw_vector;

	uint count_str(std::string str_big, std::string str_little)
	{
		std::string tmp;
		std::stringstream ss;
		uint counter = 0;

		ss << str_big;

		while (ss >> tmp)
			if (tmp == str_little)
				counter++;
		return counter;
	}

	Table::String::String(std::string str)
	{
		std::stringstream ss;
		std::string tmp_str;
		this->str = str;
		std::vector<std::string> used;


		ss << str;

		while (ss >> tmp_str)
		{
			auto it = std::find(kw_vector.begin(), kw_vector.end(), tmp_str);
			if (it != kw_vector.end() && (std::find(used.begin(), used.end(), tmp_str) == used.end()))
			{
				this->kwMap.emplace(*it, count_str(str, tmp_str));
				used.push_back(tmp_str);
				tmp_str.clear();
			}
		}

	}

	uint Table::String::searchKeyWord(std::string str)
	{
		for (auto var : this->kwMap)
			if (var.first == str)
				return var.second;
		return 0;
	}

	void Table::AddKeyWordToKeyWordVector(std::string kword, std::vector<uint> id)
	{
		Kword tmp(kword, id);
		kw_vector.emplace_back(tmp);
	}

	void Table::PrintKeyWordsList()
	{
		for (auto var : kw_vector)
			var.PrintWord();
		std::cout << std::endl;
	}

	void Table::ProcessNewString(std::string str)
	{
		static uint string_id = 0;
		String tmp(str);
		this->StringMap.emplace(string_id++, tmp);
	}

	void Table::countKword(std::string kw)
	{
		uint counter = 0;
		if (std::find(kw_vector.begin(), kw_vector.end(), kw) != kw_vector.end())
		{
			for (auto var : StringMap)
			{
				String tmp = var.second;
				counter += tmp.searchKeyWord(kw);
			}

			std::cout << counter << std::endl;
		}
		else
			std::cout << kw << "Is not a key word!" << std::endl;
	}

	void Table::Kword::PrintWord()
	{
		std::cout << this->kw_str << " ";
	}

}
