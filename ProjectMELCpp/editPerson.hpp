#ifndef EDITPERSON_HPP
#define EDITPERSON_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do edycji informacji o wybranej osobie.
*/
class editPerson : public MenuOption {
public:
	editPerson() : MenuOption("Edytuj wybrana osobe") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~editPerson() {}
};

#endif