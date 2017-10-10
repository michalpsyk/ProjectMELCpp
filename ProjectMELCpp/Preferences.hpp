#ifndef PREFERENCES_HPP
#define PREFERENCES_HPP

#include <iostream>
#include <string>
#include "functions.hpp"

using namespace std;

/*!
W klasie tej zapisywane sa preferencje uzytkownika.
Jest dziedziczona przez klase Person.
*/
class Preferences {
protected:
	bool czyDzieci, czyPowaznyZwiazek;
	string prefKolorWlosow, prefKolorOczu;
	int maxWiek;
public:
	explicit Preferences();
	void setPreferences();
	/*!
	Pomocnicza funkcja, wyswietla "Tak" jest wartosc zmiennej typu bool wynosi "True" i adekwatnie dla "False" - "Nie".
	*/
	void displayYesNo(const bool& tmp) const;
	void setCzyDzieci();
	void setCzyPowaznyZwiazek();
	void setPrefKolorWlosow();
	void setPrefKolorOczu();
	void setMaxWiek();
	void showPreferences() const;
	void editPreferences();
	virtual ~Preferences() {}
};

#endif