#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iterator>

typedef unsigned int uint;

class myTable
{
private:
	class String
	{
	private:
		class Word
		{
		private:
			std::string word; //Key word itself
			std::vector<uint> string_id; //Vector containing line numbers in which it occurs

		public:
			Word(std::string word, std::vector<uint> idVect) :
				word(word), string_id(idVect) {}

			bool operator == (const Word& rword) const { return this->word == rword.word; }
			bool operator != (const Word& rword) const { return this->word != rword.word; }
			bool operator < (const Word& rword) const { return this->word < rword.word; }
			bool operator > (const Word& rword) const { return this->word > rword.word; }

			void Show();

			std::string GetWord() { return this->word; }

		};

		std::string string; //String itself
		std::map<Word, uint> kmap; //Contains keywords and their number in this line

	public:
		String(std::string str) :
			string(str) {}

		void addKword(std::string kWord, uint count, std::vector<uint> idVect);

		uint searchKword(std::string kWord);


	};

	std::map<uint, String> strMap; //Contains strings and their ID

public:

	void addString(String str, uint ID);
	uint search(std::string kWord);
};