#ifndef INTERESTS_HPP
#define INTERESTS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*!
W klasie tej zapisywane sa zainteresowania uzytkownika.
Jest dziedziczona przez klase Person.
*/
class Interests {
protected:
	/*!
	String zawierajacy zainteresowania uzytkownika, wpisane po przecinkach.
	*/
	string zainteresowania;
public:
	explicit Interests() : zainteresowania("brak") {}
	void setInterests();
	/*!
	Funkcja zwraca zainteresowania uzytkownika w postaci wektora (zainteresowania dzielone sa ze jednego stringa na vector stringow).
	*/
	vector<string> interestsAsVector();
	/*!
	Funkcja wyswietla aktualne zainteresowania.
	*/
	void showInterests() const;
	/*!
	Funkcja wyswietla aktualne zainteresowania i wywoluje funkcje setInterests.
	*/
	void editInterests();
	virtual ~Interests() {}
};

#endif