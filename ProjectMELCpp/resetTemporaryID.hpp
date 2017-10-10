#ifndef resetTemporaryID_HPP
#define resetTemporaryID_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do resetowania wybranego i zapisanego w pamieci ID.
*/
class resetTemporaryID : public MenuOption {
public:
	resetTemporaryID() : MenuOption("Wyzeruj ID uzytkownika zapisane w pamieci") {}
	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~resetTemporaryID() {}
};

#endif