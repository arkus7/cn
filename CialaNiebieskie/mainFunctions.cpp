#include "stdafx.h"
#include <iostream>

using namespace std;

void mainMenu(Planet* table)
{
	int choice = -1;
	do {
		cout << "----- CIALA NIEBIESKIE -----" << endl << endl;
		cout << "Wybierz cialo niebieskie: " << endl;
		cout << "[1] Slonce" << endl;
		cout << "[2] Merkury" << endl;
		cout << "[3] Wenus" << endl;
		cout << "[4] Ziemia" << endl;
		cout << "[5] Mars" << endl;
		cout << "[6] Jowisz" << endl;
		cout << "[7] Saturn" << endl;
		cout << "[8] Uran" << endl;
		cout << "[9] Neptun" << endl << endl;
		cout << "[0] Wyjscie z programu" << endl << endl;
		cout << "Twoj wybor: ";
		
		cin >> choice;
		
		if (choice > 0 && choice < 10)
			planetMenu(table, choice-1);
	} while (choice != 0);
	
}

void planetMenu(Planet* table, int planetNumber) {
	int choice = -1;
	do {
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
					cout << "Ktory parametr chcesz edytowac? :";
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
					cout << "Edytowano parametr pomyslnie" << endl;
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

						cout << "Ktory parametr chcesz usunac? :";
						cin >> parNum;
						table[planetNumber].deleteParameter(parNum - 1);
					}
					else cout << "Brak parametrow." << endl << endl;
					break;
		}
		case 0: 
			break;
		default: {
					 cout << "Niepoprawny wybor!" << endl;
					 break;
		}
		}

	} while (choice != 0);
	
}