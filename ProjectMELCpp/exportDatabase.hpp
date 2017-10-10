#ifndef EXPORTDATABASE_HPP
#define EXPORTDATABASE_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do eksportu bazy danych do pliku.
*/
class exportDatabase : public MenuOption {
public:
	exportDatabase() : MenuOption("Eksport bazy danych") {}
	/*!
	Template funkcji, sluzacy do wyeksportowania zmiennej do pliku.
	*/
	template <class typ>
	void exportVariable(ofstream& exportedFile, typ& temp) {
		exportedFile.write((const char *)(&(temp)), sizeof(temp));
	}
	/*!
	Specjalizacja szablonu funkcji exportVariable dla zmiennej typu string.
	*/
	template <>
	void exportVariable(ofstream& exportedFile, string& temp) {
		size_t size = (temp).size();
		exportedFile.write((const char *)&size, sizeof(size));
		exportedFile.write((const char *)(&(temp)[0]), size);
	}

	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~exportDatabase() {}
};

#endif