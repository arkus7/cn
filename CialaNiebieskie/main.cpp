#include "stdafx.h"
#include <iostream>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Planet> astronomicalObjects;
	loadNamesFromFile(astronomicalObjects);
	loadParametersFromFiles(astronomicalObjects);
	mainMenu(astronomicalObjects);
	return 0;
}

