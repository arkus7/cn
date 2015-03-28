#include "stdafx.h"
#include "Parameter.h"

using namespace std;


Parameter::Parameter()
{
}

Parameter::Parameter(std::string name, std::string value)
{
	this->name = name;
	this->value = value;
}


Parameter::~Parameter()
{
}


// Returns a parameter name.
std::string Parameter::getName()
{
	return name;
}


// Returns a parameter value.
std::string Parameter::getValue()
{
	return value;
}


void Parameter::setName(std::string name)
{
	this->name = name;
}


void Parameter::setValue(std::string value)
{
	this->value = value;
}


// Returns name + value in a string.
std::string Parameter::getParameter()
{
	return getName() + ": " + getValue();
}
