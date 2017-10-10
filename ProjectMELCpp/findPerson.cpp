#include "findPerson.hpp"
#include <algorithm>

void findPerson::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	cout << "Podaj nazwisko osoby ktora chcesz znalezc:\n";
	string surnameTemp;
	wczytaj(surnameTemp);
	/*!
	Zmienna typu bool, ktora przyjmuje wartosc True gdy znaleziono jakies osoby.
	*/
	bool znaleziono = false;
	/*!
	Zmienna sluzaca do spawdzenia ile znaleziono osob, jesli wiecej niz 1 lub rowne 0 to nie pojawi sie komunikat o zapisaniu w pamieci ID znalezionej osoby.
	*/
	int liczbaZnalezionych = 0;
	/*!
	Zmienna sluzaca do przechowania ID znalezionej osoby, aby potem przypisac go do zmiennej statycznej temporaryId.
	*/
	int idFoundMatch = 0;

	cout << "\nZnalezione osoby:\n" << endl;
	printTitleShortPersonInfo();
	for (itr = bazaDanych.begin(); itr != bazaDanych.end(); ++itr)
		if ((itr->surname).rfind(surnameTemp) != string::npos) {
			znaleziono = true;
			itr->showPersonInfo();
			idFoundMatch = itr->id;
			liczbaZnalezionych += 1;
		}
	if (!znaleziono)
		cout << "Brak osob o podanym nazwisku." << endl;
	else if (liczbaZnalezionych == 1) {
		string confirmation;
		cout << "\nCzy chcesz, aby podana osoba zostala zapisana w pamieci jak aktualny wybor? (tak/nie)" << endl;
		while (confirmation != "tak" && confirmation != "nie") {
			wczytaj(confirmation);
			if (confirmation != "tak" && confirmation != "nie")
				cout << "Zly wybor!" << endl;
		}
		if (confirmation == "tak") {
			temporaryId = idFoundMatch;
		}
	}
}