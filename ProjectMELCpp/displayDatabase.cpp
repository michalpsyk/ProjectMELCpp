#include "displayDatabase.hpp"

void displayDatabase::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	if (bazaDanych.empty())
		cout << "Blad: brak osob w bazie danych" << endl;
	else {
		cout << "Ilosc uzytkownikow w bazie: ..... " << bazaDanych.size() << endl << endl;
		printTitleShortPersonInfo();
		for (itr = bazaDanych.begin(); itr != bazaDanych.end(); ++itr)
			itr->showPersonInfo();
	}
}