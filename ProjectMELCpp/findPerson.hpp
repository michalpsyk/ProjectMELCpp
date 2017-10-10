#ifndef FINDPERSON_HPP
#define FINDPERSON_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do szukania osoby w bazie po nazwisku.
*/
class findPerson : public MenuOption {
public:
	findPerson() : MenuOption("Wyszukaj wybrana osobe po nazwisku") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~findPerson() {}
};

#endif