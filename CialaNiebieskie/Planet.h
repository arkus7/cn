#pragma once
#include "Parameter.h"
#include <vector>

using namespace std;

class Planet
{
public:
	Planet();
	Planet(string name);
	~Planet();
	// Returns a planet name.
	string getName();
	// Saves planet Parameters to file. Every planets ends with '---'.
	void savePlanetParameters();
	// Adds a Parameter to a planet.
	void addParameter(string ParameterName, string value);
	// Edits a 'ParameterNumber' Parameter.
	void editParameterName(int parameterNumber, string newName);
	// Edits a 'ParameterNumber' value.
	void editParameterValue(int parameterNumber, string newValue);
	int getParametersCount();
	std::string getParameter(int parameterNumber);
	// Deletes choosen parameter.
	void deleteParameter(int parameterNumber);
	string getNameWithoutSpaces();
	string getParameterName(int parNum);
	string getParameterValue(int parNum);
	void setName(string newName);
private:
	string name;
	vector<Parameter> parametersList;
};

