#ifndef deletePerson_HPP
#define deletePerson_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do usuwania wybranej osoby.
*/
class deletePerson : public MenuOption {
public:
	deletePerson() : MenuOption("Usun wybrana osobe") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~deletePerson() {}
};

#endif