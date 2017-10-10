#ifndef MENUOPTION_HPP
#define MENUOPTION_HPP

#include <iostream>
#include <fstream>
#include "functions.hpp"
#include "Person.hpp"

using namespace std;

/*!
Funkcja szuka w bazie uzytkownika o podanym ID. Jesli znajdzie, wartosc iteratora
zostaje ustawiona na znalezionego uzytkownika i funkcja zwraca true.
Jesli nie znajdzie, zwraca false.

@param bazaDanych vector obiektow klas Person, stanowiacy podstawe klasy Database.
@param itr iterator vectora obiektow klas Person.
@return Prawda, jesli znaleziono uzytkownika o podanym ID, falsz jest nie znaleziono.
*/
bool returnItrWithID(vector<Person>& bazaDanych, vector<Person>::iterator& itr);

/*!
Klasa bazowa dla klas wykorzystywanych w menu glownym. Klasa abstrakcyjna.
*/
class MenuOption {
	string text;
protected:
	static int temporaryId;
public:
	MenuOption(const string& textTmp) : text(textTmp) {}
	virtual void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) = 0;
	virtual ~MenuOption() {}
	string getText() const {
		return text;
	}
	friend bool returnItrWithID(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
};

#endif