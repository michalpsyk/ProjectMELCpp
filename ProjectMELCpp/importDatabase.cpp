#include "importDatabase.hpp"

void importDatabase::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	ifstream importedFile;
	importedFile.open("database", ios::binary);
	bool fileCorrect = true;
	try {
		if (!importedFile.good())
			throw "Blad wczytywania bazy danych: nie mozna otworzyc pliku z baza danych!\n";
		if (importedFile.peek() == ifstream::traits_type::eof())
			throw "Blad wczytywania bazy danych: plik z baza danych jest pusty!\n";
	}
	catch (char* s) {
		cout << s << endl;
		fileCorrect = false;
	}
	if (fileCorrect) {
		int sizeImportedDatabase = 0;
		importVariable(importedFile, sizeImportedDatabase);
		int sizeBeforeImport = bazaDanych.size();
		bazaDanych.reserve(sizeBeforeImport + sizeImportedDatabase + 100);
		for (int i = 0; i < sizeImportedDatabase; i++) {
			Person *temp = new Person;
			bazaDanych.push_back(*temp);
			delete temp;
		}
		for (itr = bazaDanych.begin() + sizeBeforeImport; itr != bazaDanych.end(); ++itr) {
			//importedFile.read((char *)(&(itr->id)), sizeof(itr->id));
			importVariable(importedFile, (itr->birthdayYear));
			importVariable(importedFile, (itr->gender));
			importVariable(importedFile, (itr->name));
			importVariable(importedFile, (itr->surname));
			importVariable(importedFile, (itr->orientacja));
			importVariable(importedFile, (itr->kolorOczu));
			importVariable(importedFile, (itr->kolorWlosow));
			importVariable(importedFile, (itr->zainteresowania));
			importVariable(importedFile, (itr->prefKolorWlosow));
			importVariable(importedFile, (itr->prefKolorOczu));
			importVariable(importedFile, (itr->czyDzieci));
			importVariable(importedFile, (itr->czyPowaznyZwiazek));
			importVariable(importedFile, (itr->maxWiek));
		}
		importedFile.close();
		cout << "Import bazy zakonczony sukcesem." << endl;
	}
}