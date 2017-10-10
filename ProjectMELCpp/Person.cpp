#include "Person.hpp"

int Person::licznik = 1;

/*!
Operator sluzacy do porownania dwoch osob pod wzgledem preferencji.
Zwraca True, jesli osoby sa zgodne ze swoimi preferencjami.
*/
bool operator==(const Person& user, const Person& suitablePerson) {
	bool condition1 = (user.czyDzieci == suitablePerson.czyDzieci);
	bool condition2 = (user.czyPowaznyZwiazek == suitablePerson.czyPowaznyZwiazek);
	bool condition3 = (user.prefKolorWlosow == suitablePerson.kolorWlosow && suitablePerson.prefKolorWlosow == user.kolorWlosow);
	bool condition4 = (user.prefKolorOczu == suitablePerson.kolorOczu && suitablePerson.prefKolorOczu == user.kolorOczu);
	bool condition5 = (suitablePerson.wiek() <= user.maxWiek && user.wiek() <= suitablePerson.maxWiek);
	bool condition6 = false;
	if (user.orientacja == "homoseksualizm") {
		if (user.gender == suitablePerson.gender && (suitablePerson.orientacja == "homoseksualizm" || suitablePerson.orientacja == "biseksualizm"))
			condition6 = true;
	}
	else if (user.orientacja == "heteroseksualizm") {
		if (user.gender != suitablePerson.gender && (suitablePerson.orientacja == "heteroseksualizm" || suitablePerson.orientacja == "biseksualizm"))
			condition6 = true;
	}
	else if (user.orientacja == "biseksualizm")
		condition6 = true;
	if (condition1 && condition2 && condition3 && condition4 && condition5  && condition6)
		return true;
	else
		return false;
}

Person::Person() : id(licznik), name("Unknown"), surname("Unknown"), orientacja("Unknown"), kolorWlosow("Unknown"), kolorOczu("Unknown"), gender('?'), birthdayYear(1900) { licznik += 1; }

const int Person::wiek() const {
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	return (1900 + ltm.tm_year) - birthdayYear;
}

void Person::setName() {
	cout << "Podaj imie uzytkownika:" << endl;
	wczytaj(name);
}
void Person::setSurname() {
	cout << "Podaj nazwisko uzytkownika:" << endl;
	wczytaj(surname);
}
void Person::setGender() {
	cout << "Podaj plec uzytkownika (k - kobieta, m - mezczyzna):" << endl;
	do {
		wczytaj(gender);
		if (gender != 'k' && gender != 'm')
			cout << "Zly wybor!" << endl;
	} while (gender != 'k' && gender != 'm');
}
void Person::setBirthdayYear() {
	cout << "Podaj rok urodzenia uzytkownika:" << endl;
	wczytaj(birthdayYear);
}
void Person::setOrientacja() {
	cout << "Podaj orientacje seksualna uzytkownika" << "\n(homoseksualizm/heteroseksualizm/biseksualizm):" << endl;
	do {
		wczytaj(orientacja);
		if (orientacja != "homoseksualizm" && orientacja != "heteroseksualizm" && orientacja != "biseksualizm")
			cout << "Zly wybor!" << endl;
	} while (orientacja != "homoseksualizm" && orientacja != "heteroseksualizm" && orientacja != "biseksualizm");
}
void Person::setKolorWlosow() {
	cout << "Podaj kolor wlosow uzytkownika:" << endl;
	wczytaj(kolorWlosow);
}
void Person::setKolorOczu() {
	cout << "Podaj kolor oczu uzytkownika:" << endl;
	wczytaj(kolorOczu);
}

void Person::setPersonInfo() {
	setName();
	setSurname();
	setGender();
	setBirthdayYear();
	setOrientacja();
	setKolorWlosow();
	setKolorOczu();
}

void Person::showPersonInfo() const {
	printElement(id, 5);
	printElement(name, 15);
	printElement(surname, 15);
	printElement(gender, 6);
	printElement(birthdayYear, 15);
	cout << endl;
}
void Person::showFullPersonInfo() const {
	cout << "ID: ..................... " << id << endl;
	cout << "Imie: ................... " << name << endl;
	cout << "Nazwisko: ............... " << surname << endl;
	cout << "Plec: ................... " << gender << endl;
	cout << "Rok urodzenia: .......... " << birthdayYear << endl;
	cout << "Wiek: ................... " << this->wiek() << endl;
	cout << "Orientacja seksualna: ... " << orientacja << endl;
	cout << "Kolor oczu: ............. " << kolorOczu << endl;
	cout << "Kolor wlosow: ........... " << kolorWlosow << endl;
}

void Person::editPersonInfo() {
	int choise = 0;
	cout << "\nWybierz, co chcesz zmienic:\n";
	cout << " [1] - Edycja imienia .......... (aktualna wartosc - " << this->name << ")" << endl;
	cout << " [2] - Edycja nazwiska ......... (aktualna wartosc - " << this->surname << ")" << endl;
	cout << " [3] - Edycja roku urodzenia ... (aktualna wartosc - " << this->birthdayYear << ")" << endl;
	cout << " [4] - Edycja plci ............. (aktualna wartosc - " << this->gender << ")" << endl;
	cout << " [5] - Edycja orientacji ....... (aktualna wartosc - " << this->orientacja << ")" << endl;
	cout << " [6] - Edycja koloru wlosow .... (aktualna wartosc - " << this->kolorWlosow << ")" << endl;
	cout << " [7] - Edycja koloru oczu ...... (aktualna wartosc - " << this->kolorOczu << ")" << endl;
	cout << " [8] - Anuluj" << endl;
	while (choise < 1 || choise > 8) {
		wczytaj(choise);
		if (choise < 1 || choise > 8)
			cout << "Zly wybor!" << endl;
	}
	cout << endl;
	switch (choise) {
	case 1:
		setName();
		break;
	case 2:
		setSurname();
		break;
	case 3:
		setBirthdayYear();
		break;
	case 4:
		setGender();
		break;
	case 5:
		setOrientacja();
		break;
	case 6:
		setKolorWlosow();
		break;
	case 7:
		setKolorOczu();
		break;
	case 8:
		break;
	}
}