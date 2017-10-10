#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include "Interests.hpp"
#include "Preferences.hpp"
#include "functions.hpp"

using namespace std;

/*!
Klasa stanowiaca podstawe bazy, uzytkownicy bazy sa tworzeni jako obiekty tej klasy.
Klasa dziedzczy po klasie Preferences i Interests.
*/
class Person : public Preferences, public Interests {
	//
private:
	//zmienna sluzaca do nadawania kolejnego id nowopowstalym osoba
	static int licznik;
	int id;
	string name, surname;
	int birthdayYear;
	char gender; // k - kobieta / m - mezczyzna
	string orientacja, kolorWlosow, kolorOczu;
	const int wiek() const;
public:
	//! Konstruktor klasy Person.
	/*!
	Konstruktor domyslny klasy Person, inicjalizuje zmienne defaultowymi wartosciami.
	*/
	explicit Person();
	//! Destruktor klasy Person.
	/*!
	Wirtualny destruktor klasy Person.
	*/
	virtual ~Person() {}

	/*!
	Funkcja umozliwia zmiane wszystkich cech uzytkownika, wywoluje wszystkie funkcje set_NazwaZmiennej.
	*/
	void setPersonInfo();
	/*!
	Funkcja wyswietla podstawowe informacje o uzytkowniku (id, imie, nazwisko, plec, rok urodzenia)
	*/
	void showPersonInfo() const;
	/*!
	Funkcja wyswietla wszystkie informacje o uzytkowniku.
	*/
	void showFullPersonInfo() const;
	
	void setName();
	void setSurname();
	void setGender();
	void setBirthdayYear();
	void setOrientacja();
	void setKolorWlosow();
	void setKolorOczu();

	/*!
	Funkcja wyswietla menu edycji cech uzytkownika a nastepnie wywoluje odpowiednia funkcje set_NazwaZmiennej.
	*/
	void editPersonInfo();

	friend bool returnItrWithID(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	friend bool operator==(const Person& user, const Person& suitablePerson);
	friend class Database;
	friend class findPerson;
	friend class importDatabase;
	friend class exportDatabase;
	friend class findMatch;
};

#endif