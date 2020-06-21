//Для хранения информации о ключевых словах некоторой программы имеется таблица перекрестных ссылок.
//Для каждого слова задан список номеров строк, где оно встречается, 
//а для каждой строки - число образцов данного слова в строке.
//Ключевые слова расположены по алфавиту.
//Построить бинарное дерево для быстрого поиска ключевых слов.
//Составить программу определения общего количества вхождений заданного ключевого слова.
//Обеспечить корректировку дерева поиска для случая удаления ключевого слова из некоторой строки.

#pragma once
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>

namespace MyTable
{
	typedef unsigned int uint;

	class Table
	{
	private:
		class Kword
		{
		private:
			std::string kw_str; //keyword itself
			std::vector<uint> str_id; //vector of lines in which it occurs

		public:
			Kword(std::string kword, std::vector<uint> str_id) :
				kw_str(kword), str_id(str_id) {}

			bool operator == (const Kword& right) const { return this->kw_str == right.kw_str; }
			bool operator != (const Kword& right) const { return this->kw_str != right.kw_str; }
			bool operator > (const Kword& right) const { return this->kw_str > right.kw_str; }
			bool operator < (const Kword& right) const { return this->kw_str < right.kw_str; }

			bool operator == (const std::string& right) const { return this->kw_str == right; }
			bool operator != (const std::string& right) const { return this->kw_str != right; }
			bool operator > (const std::string& right) const { return this->kw_str > right; }
			bool operator < (const std::string& right) const { return this->kw_str < right; }

			void PrintWord();
		};

		class String
		{
		private:
			std::string str;
			std::map<Kword, uint> kwMap;
		public:
			String(std::string str);

			uint searchKeyWord(std::string str);
		};

		static std::vector<Kword> kw_vector; //Contains all possible keywords presented in the table.
		std::map<uint, String> StringMap;

	public:

		static void AddKeyWordToKeyWordVector(std::string kword, std::vector<uint> id);
		static void PrintKeyWordsList();
		void ProcessNewString(std::string str);
		void countKword(std::string kw);

	};

};