#ifndef IMPORTDATABASE_HPP
#define IMPORTDATABASE_HPP

#include <iostream>
#include <vector>
#include "menuOption.hpp"

using namespace std;

/*!
Klasa dziedziczaca po MenuOption, sluzy do importu bazy danych z pliku.
*/
class importDatabase : public MenuOption {
public:
	importDatabase() : MenuOption("Import bazy danych") {}
	/*!
	Template funkcji, sluzacy do importowania zmiennej z pliku.
	*/
	template <class typ>
	void importVariable(ifstream& importedFile, typ& temp) {
		importedFile.read((char *)(&(temp)), sizeof(temp));
	}
	/*!
	Specjalizacja szablonu funkcji importVariable dla zmiennej typu string.
	*/
	template <>
	void importVariable(ifstream& importedFile, string& temp) {
		size_t size;
		importedFile.read((char *)&size, sizeof(size));
		(temp).resize(size);
		importedFile.read((char *)(&(temp)[0]), size);
	}

	void action(vector<Person>& bazaDanych, vector<Person>::iterator& itr);
	virtual ~importDatabase() {}
};

#endif