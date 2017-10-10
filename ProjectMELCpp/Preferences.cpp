#include "Preferences.hpp"

Preferences::Preferences() : maxWiek(99), czyDzieci(false), czyPowaznyZwiazek(false), prefKolorWlosow("blond"), prefKolorOczu("niebieskie") {}

void Preferences::setCzyDzieci() {
	cout << "Czy uzytkownik chce miec dzieci? (1 - tak, 0 - nie)" << endl;
	wczytaj(czyDzieci);
}
void Preferences::setCzyPowaznyZwiazek() {
	cout << "Czy uzytkownik szuka powaznego zwiazku? (1 - tak, 0 - nie)" << endl;
	wczytaj(czyPowaznyZwiazek);
}
void Preferences::setPrefKolorWlosow() {
	cout << "Podaj preferowany kolor wlosow partnera:" << endl;
	wczytaj(prefKolorWlosow);
}
void Preferences::setPrefKolorOczu() {
	cout << "Podaj preferowany kolor oczu partnera:" << endl;
	wczytaj(prefKolorOczu);
}
void Preferences::setMaxWiek() {
	cout << "Podaj maksymalny wiek partnera:" << endl;
	wczytaj(maxWiek);
}

void Preferences::setPreferences() {
	setCzyDzieci();
	setCzyPowaznyZwiazek();
	setPrefKolorWlosow(); 
	setPrefKolorOczu();
	setMaxWiek();
}
void Preferences::editPreferences() {
	int choise = 0;
	cout << "\nWybierz, co chcesz zmienic:\n";
	cout << " [1] - Edycja preferencji odnosnie dzieci ............... (aktualna wartosc - " << this->czyDzieci << ")" << endl;
	cout << " [2] - Edycja preferencji odnosnie powaznego zwiazku .... (aktualna wartosc - " << this->czyPowaznyZwiazek << ")" << endl;
	cout << " [3] - Edycja preferencji odnosnie koloru wlosow ........ (aktualna wartosc - " << this->prefKolorWlosow << ")" << endl;
	cout << " [4] - Edycja preferencji odnosnie koloru oczu .......... (aktualna wartosc - " << this->prefKolorOczu << ")" << endl;
	cout << " [5] - Edycja preferencji odnosnie maksymalnego wieku ... (aktualna wartosc - " << this->maxWiek << ")" << endl;
	cout << " [6] - Anuluj" << endl;
	while (choise < 1 || choise > 6) {
		wczytaj(choise);
		if (choise < 1 || choise > 6)
			cout << "Zly wybor!" << endl;
	}
	cout << endl;
	switch (choise) {
	case 1:
		setCzyDzieci();
		break;
	case 2:
		setCzyPowaznyZwiazek();
		break;
	case 3:
		setPrefKolorWlosow();
		break;
	case 4:
		setPrefKolorOczu();
		break;
	case 5:
		setMaxWiek();
		break;
	case 6:
		break;
	}
}

void Preferences::displayYesNo(const bool& tmp) const {
	if (tmp == true) cout << "Tak" << endl;
	else cout << "Nie" << endl;
}
void Preferences::showPreferences() const {
	cout << "Czy uzytkownik chce miec dzieci? .............. ";
	displayYesNo(czyDzieci);
	cout << "Czy uzytkownik szuka powaznego zwiazku? ....... ";
	displayYesNo(czyPowaznyZwiazek);
	cout << "Uzytkownik szuka osoby o kolorze wlosow: ...... " << prefKolorWlosow << endl;
	cout << "Uzytkownik szuka osoby o kolorze oczu: ........ " << prefKolorOczu << endl;
	cout << "Uzytkownik szuka osoby o maksymalnym wieku: ... " << maxWiek << endl;
}