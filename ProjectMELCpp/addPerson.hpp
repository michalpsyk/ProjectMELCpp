#ifndef ADDPERSON_HPP
#define ADDPERSON_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"
#include "Database.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do dodania osoby do bazy.
*/
class addPerson : public MenuOption 
{
public:
	addPerson() : MenuOption("Dodaj nowa osobe") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~addPerson() {}
};

#endif