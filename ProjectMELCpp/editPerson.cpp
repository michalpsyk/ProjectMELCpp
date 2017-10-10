#include "editPerson.hpp"

void editPerson::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	if (temporaryId == 0)
		cout << "Podaj ID osoby, ktora chcesz edytowac:" << endl;
	bool znaleziono = returnItrWithID(bazaDanych, itr);
	while (znaleziono) {
			cout << "Zostanie edytowana ponizsza osoba:\n" << endl;
			printTitleShortPersonInfo();
			itr->showPersonInfo();
			int choise = 0;
			cout << "\nWybierz, co chcesz zmienic:\n";
			cout << " [1] - Edycja danych osobowych\n" << " [2] - Edycja preferencji\n" << " [3] - Edycja zainteresowan\n" << " [4] - Anuluj\n";
			while (choise < 1 || choise > 4) {
				wczytaj(choise);
				if (choise < 1 || choise > 4)
					cout << "Zly wybor!" << endl;
			}
			if (choise == 4)
				break;
			switch (choise) {
			case 1:
				itr->editPersonInfo();
				break;
			case 2:
				itr->editPreferences();
				break;
			case 3:
				itr->editInterests();
				break;
		}
		system("cls");
	}
}