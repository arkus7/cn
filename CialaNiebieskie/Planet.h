#pragma once
class Planet
{
public:
	Planet();
	~Planet();
private:
	string name;
public:
	// Returns a planet name.
	string getName();
	// Saves planet parametrs to file. Every planets ends with '---'.
	void savePlanetParametrs();
	// Adds a parametr to a planet.
	void addParametr(string parametrName, string value);
	// Edits a 'parametrNumber' parametr.
	void editParametrName(int parametrNumber, string newName);
};

