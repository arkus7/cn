// CialaNiebieskie.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include "Planet.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Planet solarSystem[] = { 
								Planet("Sun"), Planet("Mercury"), Planet("Venus"),
								Planet("Earth"), Planet("Mars"), Planet("Jupiter"),
								Planet("Saturn"), Planet("Uranus"), Planet("Neptune") 
							};
	solarSystem[3].addParameter("Volume", "205002 dm3");
	for (int i = 0; i < solarSystem[3].getParametersCount(); i++) {
		std::cout << solarSystem[3].getParameter(i) << std::endl;
	}
	char asd;
	std::cin >> asd;
	return 0;
}

