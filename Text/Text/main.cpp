#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>

const char* mark = "MARK";
char space[] = " ";

void tusk()
{
	std::fstream fin;
	std::string tmp_string;
	std::string tmp_word;
	std::string desired_string;

	size_t pre_count = 0;
	size_t post_count = 0;

	std::list<std::string> result;
	bool flag = false;
	bool mark_flag = false;


	try
	{
		fin.open("Text.txt");

		while (!fin.eof())
		{
			std::getline(fin, tmp_string);



			std::stringstream x;
			x << tmp_string;

			while (x >> tmp_word)
			{
				if (tmp_word == mark)
				{
					tmp_word = "*MARK*";
					flag = true;
					mark_flag = true;
				}
				desired_string += tmp_word;
				desired_string += " ";
			}


			if (flag)
			{
				result.push_back(desired_string);
				flag = false;
			}
			else
			{
				if (!mark_flag)
				{
					if (pre_count < 2)
					{
						result.push_back(desired_string);
						pre_count++;
					}
					else
					{
						result.pop_front();
						result.push_back(desired_string);
					}
				}

				if (mark_flag && post_count < 2)
				{
					result.push_back(desired_string);
					post_count++;
				}
			}

			desired_string.clear();
			tmp_string.clear();
		}

		for (auto ret : result)
			std::cout << ret << std::endl;

		fin.close();
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}


int main()
{
	

	tusk();
	

	system("pause");
	return 0;
}