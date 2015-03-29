#include "stdafx.h"
#include "Planet.h"
#include <fstream>

using namespace std;

Planet::Planet()
{
}

Planet::Planet(string name)
{
	this->name = name;
}


Planet::~Planet()
{
}


// Returns a planet name.
string Planet::getName()
{
	return name;
}


// Saves planet Parameters to file.
void Planet::savePlanetParameters()
{
	fstream planetFile;
	planetFile.open("objects/" + getNameWithoutSpaces() + ".txt", ios::out);
	if (planetFile.is_open()) {
		for (int i = 0; i < getParametersCount(); i++) {
			planetFile << getParameterName(i) << endl << getParameterValue(i) << endl;
		}
	}
	planetFile.close();
}


// Adds a Parameter to a planet.
void Planet::addParameter(string parameterName, string value)
{
	Parameter param = Parameter(parameterName, value);
	parametersList.push_back(param);
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
	return parametersList.size();
}


std::string Planet::getParameter(int parameterNumber)
{
	return parametersList[parameterNumber].getParameter();
}


// Deletes choosen parameter.
void Planet::deleteParameter(int parameterNumber)
{
	parametersList.erase(parametersList.begin() + parameterNumber);
}


string Planet::getNameWithoutSpaces() 
{
	string name = getName();
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') name[i] = '_';
	}
	return name;
}

string Planet::getParameterName(int parNum)
{
	return parametersList[parNum].getName();
}

string Planet::getParameterValue(int parNum)
{
	return parametersList[parNum].getValue();
}

void Planet::setName(string newName)
{
	name = newName;
}