#ifndef FINDMATCH_HPP
#define FINDMATCH_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do znalezienie partnera dla wybranej osoby.
Klasa najpierw wyszukuje partnera, spelniajacego preferencje osoby, a nastepnie
wylicza procent dopasowania zainteresowan osob.
*/
class findMatch : public MenuOption {
public:
	findMatch() : MenuOption("Znajdz dopasowanie dla wybranej osoby") {}
	/*!
	Funkcja zwraca procentowa wartosc dopasowania zainteresowan uzytkownika 
	user z zainteresowaniami uzytkownika foundMatchedPerson, ktory spelnia jego preferencje.
	*/
	double percentageMatchedInterests(Person& user, Person& foundMatchedPerson);
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~findMatch() {}
};

#endif