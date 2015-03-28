#pragma once
#include "Planet.h"
#include "stdafx.h"

void mainMenu(vector<Planet>& table);
void planetMenu(vector<Planet>& table, int planetNumber);
void loadNamesFromFile(vector<Planet>& table);
void loadParametersFromFiles(vector<Planet>& table);
void saveNamesToFile(vector<Planet>& table);