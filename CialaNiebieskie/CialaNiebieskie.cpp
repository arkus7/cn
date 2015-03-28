// CialaNiebieskie.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Planet solarSystem[] = { 
								Planet("Sun"), Planet("Mercury"), Planet("Venus"),
								Planet("Earth"), Planet("Mars"), Planet("Jupiter"),
								Planet("Saturn"), Planet("Uranus"), Planet("Neptune") 
							};
	mainMenu(solarSystem);

	return 0;
}

