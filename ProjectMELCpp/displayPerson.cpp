#include "displayPerson.hpp"

void displayPerson::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	if (temporaryId == 0)
		cout << "Podaj ID osoby, ktora chcesz wyswietlic:\n";
	bool znaleziono = returnItrWithID(bazaDanych, itr);
	if (znaleziono) {
		itr->showFullPersonInfo();
		cout << endl;
		itr->showInterests();
		cout << endl;
		itr->showPreferences();
	}
}