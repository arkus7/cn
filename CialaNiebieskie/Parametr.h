#pragma once
#include <string>
class Parametr
{
public:
	Parametr();
	~Parametr();
	// Returns a parametr name.
	std::string getName();
	// Returns a parametr value.
	std::string getValue();
	void setName(std::string name);
	void setValue(std::string value);
};

