#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <conio.h>
#include <vector>
#include "functions.hpp"
#include "Person.hpp"
#include "menuOption.hpp"
#include "addPerson.hpp"
#include "editPerson.hpp"
#include "displayDatabase.hpp"
#include "displayPerson.hpp"
#include "deletePerson.hpp"
#include "importDatabase.hpp"
#include "exportDatabase.hpp"
#include "findMatch.hpp"
#include "findPerson.hpp"
#include "exitDatabase.hpp"
#include "resetTemporaryID.hpp"

using namespace std;

/*!
Klasa bazy danych. Przechowuje ona vector z osobami, ktore sa obiektmi klasy Person.
*/
class Database {
	vector<Person> bazaDanych;
	vector<Person>::iterator itr;
	vector<MenuOption*> options;
public:
	Database();
	/*!
	Funkcja wyswietlajaca menu glowne programu.
	*/
	void menu();
	~Database();
};

#endif