#ifndef DISPLAYDATABASE_HPP
#define DISPLAYDATABASE_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do wyswietlenia wszystkich osob w bazie.
*/
class displayDatabase : public MenuOption {
public:
	displayDatabase() : MenuOption("Wyswietl wszystkie osoby w bazie") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~displayDatabase() {}
};

#endif