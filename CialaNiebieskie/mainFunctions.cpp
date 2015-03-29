#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

void mainMenu(vector<Planet>& table)
{
	string choice;
	int choiceInt = -1;
	do {
		system("cls");
		cout << "----- CIALA NIEBIESKIE -----" << endl << endl;
		cout << "Wybierz cialo niebieskie: " << endl;
		for (int i = 0; i < table.size(); i++) {
			cout << "[" << i + 1 << "] " << table[i].getName() << endl;
		}
		cout << endl;
		cout << "[A] Dodaj nowe cialo niebieskie" << endl;
		cout << "[E] Zmien nazwe" << endl;
		cout << "[D] Usun cialo niebieskie" << endl;
		cout << endl;
		cout << "[0] Wyjscie z programu" << endl << endl;
		cout << "Twoj wybor: ";
		
		cin >> choice;
		std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		
		if (choice == "a") {
			string name;
			cout << "Podaj nazwe (0 - anuluj): ";
			cin.ignore();
			getline(cin, name);
			if (name != "0") {
				table.push_back(Planet(name));
				cout << "Dodano pomyslnie!" << endl;
				saveNamesToFile(table);
			}
			cout << endl;
			system("pause");
		}
		else if (choice == "e") {
			int num;
			string name;
			for (int i = 0; i < table.size(); i++) {
				cout << "[" << i + 1 << "] " << table[i].getName() << endl;
			}
			cout << endl;
			cout << "Wybierz numer do edycji (0 - anuluj): ";
			cin >> num;
			cout << endl;
			if (num) {
				cout << "Podaj nowa nazwe: ";
				cin.ignore();
				getline(cin, name);
				table[num - 1].setName(name);
				cout << endl << "Edytowano pomyslnie!" << endl << endl;
				saveNamesToFile(table);
			}
			system("pause");
		}
		else if (choice == "d") {
			int num;
			for (int i = 0; i < table.size(); i++) {
				cout << "[" << i + 1 << "] " << table[i].getName() << endl;
			}
			cout << endl;
			cout << "Wybierz numer do usuniecia (0 - anuluj): ";
			cin >> num;

			if (num > 0 && num <= table.size()) {
				char del;
				cout << "Czy na pewno chcesz usunac " << table[num - 1].getName() << "? [T/N]: ";
				cin >> del;
				if (del == 'T' || del == 't') {
					string fileName = "objects/" + table[num - 1].getNameWithoutSpaces() + ".txt";
					table.erase(table.begin() + num - 1);
					cout << "Usunieto pomyslnie!" << endl;
					saveNamesToFile(table);
					remove(fileName.c_str());
				}
			}
			cout << endl;
			system("pause");
		}
		else {
			choiceInt = atoi(choice.c_str());
			if (choiceInt > 0 && choiceInt <= table.size())
				planetMenu(table, choiceInt - 1);
			else if (choice == "0") {
				char exit;
				cout << "Czy na pewno chcesz zakonczyc program? [T/N] ";
				cin >> exit;
				if (exit == 'N' || exit == 'n')
					choiceInt = -1;
			}
			else {
				cout << "Niepoprawy wybor!" << endl << endl << endl;
				system("pause");
				choiceInt = -1;
			}
		}
		
	} while (choiceInt != 0);
	
}

void planetMenu(vector<Planet>& table, int planetNumber) {
	int choice = -1;
	do {
		system("cls");
		cout << "Aktualne cialo niebieskie to: " << table[planetNumber].getName() << endl;
		cout << "Liczba parametrow: " << table[planetNumber].getParametersCount() << endl;
		cout << endl;
		cout << "[1] Przegladaj parametry" << endl;
		cout << "[2] Dodaj parametr" << endl;
		cout << "[3] Edytuj parametr" << endl;
		cout << "[4] Usun parametr" << endl << endl;
		cout << "[0] Powrot do menu glownego" << endl << endl;
		cout << "Twoj wybor: ";

		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: {
					if (table[planetNumber].getParametersCount() > 0){
						cout << "Lista parametrow:" << endl;
						for (int i = 0; i < table[planetNumber].getParametersCount(); i++) {
							cout << "[" << i + 1 << "] " << table[planetNumber].getParameter(i) << endl;
						}
						cout << endl << endl;
					}
					else cout << "Brak parametrow." << endl << endl;
					system("pause");
					break;
		}
		case 2: {
					cin.ignore();
					string name, value;
					cout << "Nazwa parametru: ";
					getline(cin, name);
					cout << "Wartosc: ";
					getline(cin, value);
					table[planetNumber].addParameter(name, value);
					cout << "Dodano pomyslnie." << endl;
					table[planetNumber].savePlanetParameters();
					system("pause");
					break;
		}
		case 3: {
					int parNum;
					string name, value;
					char n, v;
					cout << "Lista parametrow:" << endl;
					for (int i = 0; i < table[planetNumber].getParametersCount(); i++) {
						cout << "[" << i + 1 << "] " << table[planetNumber].getParameter(i) << endl;
					}
					cout << endl;
					cout << "Ktory parametr chcesz edytowac? : ";
					cin >> parNum;
					parNum--;
					cout << "Czy chcesz zmienic nazwe? [T/N]: ";
					cin >> n;
					if (n == 'T' || n == 't') {
						cout << "Podaj nowa nazwe: ";
						cin.ignore();
						getline(cin, name);
						table[planetNumber].editParameterName(parNum, name);
					}
					cout << "Czy chcesz zmienic wartosc? [T/N]: ";
					cin >> v;
					if (v == 'T' || v == 't') {
						cout << "Podaj nowa wartosc: ";
						cin.ignore();
						getline(cin, value);
						table[planetNumber].editParameterValue(parNum, value);
					}
					table[planetNumber].savePlanetParameters();
					cout << "Edytowano parametr pomyslnie!" << endl;
					system("pause");
					break;
		}
		case 4: {
					if (table[planetNumber].getParametersCount() > 0){
						cout << "Lista parametrow:" << endl;
						for (int i = 0; i < table[planetNumber].getParametersCount(); i++) {
							cout << "[" << i + 1 << "] " << table[planetNumber].getParameter(i) << endl;
						}
						cout << endl << endl;

						int parNum;

						cout << "Ktory parametr chcesz usunac? : ";
						cin >> parNum;
						table[planetNumber].deleteParameter(parNum - 1);
						table[planetNumber].savePlanetParameters();
					}
					else cout << "Brak parametrow." << endl << endl;
					system("pause");
					break;
		}
		case 0: 
			break;
		default: {
					 cout << "Niepoprawny wybor!" << endl;
					 system("pause");
					 break;
		}
		}

	} while (choice != 0);
	
}

void loadNamesFromFile(vector<Planet>& table) 
{
	fstream AOnamesFile;
	AOnamesFile.open("AOList.txt", ios::in);
	if (AOnamesFile.is_open()) {
		string name;
		while (getline(AOnamesFile, name)) {
			table.push_back(Planet(name));
		}
		AOnamesFile.close();
	}
	else {
		AOnamesFile.open("AOList.txt", ios::out | ios::app);
		string ao[] = { "Slonce", "Merkury", "Wenus", "Ziemia", "Mars", "Jowisz", "Saturn", "Uran", "Neptun" };
		for (int i = 0; i < 9; i++) {
			AOnamesFile << ao[i] << endl;
			table.push_back(Planet(ao[i]));
		}
	}
}

void loadParametersFromFiles(vector<Planet>& table)
{
	string fileName;
	for (int i = 0; i < table.size(); i++) {
		fileName = "objects/" + table[i].getNameWithoutSpaces() + ".txt";
		fstream objectFile;
		objectFile.open(fileName.c_str(), ios::in);
		if (objectFile.is_open()) {
			string name, value;
			while (getline(objectFile, name)) {
				getline(objectFile, value);
				table[i].addParameter(name, value);
			}
		}
		objectFile.close();
	}
}

void saveNamesToFile(vector<Planet>& table)
{
	fstream namesFile;
	namesFile.open("AOList.txt", ios::out);
	if (namesFile.is_open()){
		for (int i = 0; i < table.size(); i++) {
			namesFile << table[i].getName() << endl;
		}
	}
	namesFile.close();
}
