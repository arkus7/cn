#pragma once
#include <string>
class Parameter
{
public:
	Parameter();
	Parameter(std::string name, std::string value);
	~Parameter();
	// Returns a Parameter name.
	std::string getName();
	// Returns a Parameter value.
	std::string getValue();
	void setName(std::string name);
	void setValue(std::string value);
private:
	std::string name;
	std::string value;
public:
	// Returns name + value in a string.
	std::string getParameter();
};

