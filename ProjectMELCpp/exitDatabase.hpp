#ifndef EXITDATABASE_HPP
#define EXITDATABASE_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do wyjscia z programu.
*/
class exitDatabase : public MenuOption {
public:
	exitDatabase() : MenuOption("Wyjscie z programu") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~exitDatabase() {}
};

#endif