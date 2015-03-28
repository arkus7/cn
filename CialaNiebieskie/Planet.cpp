#include "stdafx.h"
#include "Planet.h"

using namespace std;

Planet::Planet()
{
	numberOfParameters = 0;
}

Planet::Planet(string name)
{
	this->name = name;
	numberOfParameters = 0;
}


Planet::~Planet()
{
}


// Returns a planet name.
string Planet::getName()
{
	return name;
}


// Saves planet Parameters to file. Every planets ends with '---'.
void Planet::savePlanetParameters()
{
}


// Adds a Parameter to a planet.
void Planet::addParameter(string parameterName, string value)
{
	Parameter param = Parameter(parameterName, value);
	parametersList.push_back(param);
	numberOfParameters++;
}


// Edits a 'ParameterNumber' name.
void Planet::editParameterName(int parameterNumber, string newName)
{
	parametersList[parameterNumber].setName(newName);
}


// Edits a 'ParameterNumber' value.
void Planet::editParameterValue(int parameterNumber, string newValue)
{
	parametersList[parameterNumber].setValue(newValue);
}


int Planet::getParametersCount()
{
	return numberOfParameters;
}


std::string Planet::getParameter(int parameterNumber)
{
	return parametersList[parameterNumber].getParameter();
}


// Deletes choosen parameter.
void Planet::deleteParameter(int parameterNumber)
{
	parametersList.erase(parametersList.begin() + parameterNumber);
	numberOfParameters--;
}
