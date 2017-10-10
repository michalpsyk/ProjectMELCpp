#ifndef DISPLAYPERSON_HPP
#define DISPLAYPERSON_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do wyswietlania informacji o wybranej osobie.
*/
class displayPerson : public MenuOption {
public:
	displayPerson() : MenuOption("Wyswietl pelne informacje o wybranej osobie") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~displayPerson() {}
};

#endif