#pragma once
#include "Parametr.h"
#include <vector>

using namespace std;

class Planet
{
public:
	Planet();
	~Planet();
private:
	string name;
	vector<Parametr>parametrsList;
public:
	// Returns a planet name.
	string getName();
	// Saves planet parametrs to file. Every planets ends with '---'.
	void savePlanetParametrs();
	// Adds a parametr to a planet.
	void addParametr(string parametrName, string value);
	// Edits a 'parametrNumber' parametr.
	void editParametrName(int parametrNumber, string newName);
	// Edits a 'parametrNumber' value.
	void editParametrValue(int parametrNumber, string newValue);
};

