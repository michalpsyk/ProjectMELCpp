#include "deletePerson.hpp"

void deletePerson::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	if (temporaryId == 0)
		cout << "Podaj ID osoby, ktora chcesz usunac:\n";
	bool znaleziono = returnItrWithID(bazaDanych, itr);
	if (znaleziono) {
		cout << "Zostanie usuniety uzytkownik:\n" << endl;
		printTitleShortPersonInfo();
		itr->showPersonInfo();
		string choise;
		cout << "\nCzy jestes pewny? (tak/nie)" << endl;
		while (choise != "tak" && choise != "nie") {
			wczytaj(choise);
			if (choise != "tak" && choise != "nie")
				cout << "Zly wybor!" << endl;
		}
		if (choise == "tak") {
			bazaDanych.erase(itr);
			cout << "\nUzytkownik o podanym ID zostal usuniety z bazy." << endl;
		}
		else
			cout << "\nPrzerwano operacje usuniecia uzytkownika o podanym ID." << endl;
	}
}