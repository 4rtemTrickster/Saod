#pragma once
#include <iostream>
#include <string>

class Object
{
protected:
	unsigned int ID;
	std::string class_name;

public:

	virtual unsigned int get_id()			= 0;
	virtual std::string get_class_name()	= 0;


	virtual std::ostream& operator << (std::ostream& out)	= 0;
	virtual std::istream& operator >> (std::istream& in)	= 0;

};