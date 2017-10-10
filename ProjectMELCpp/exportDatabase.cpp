#include "exportDatabase.hpp"

void exportDatabase::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	ofstream exportedFile;
	exportedFile.open("database", ios::binary | ios::trunc);

	bool fileCorrect = true;
	try {
		if (!exportedFile.good())
			throw "Blad: nie mozna otworzyc pliku z baza danych!";
	}
	catch (char* s) {
		cout << s << endl;
		fileCorrect = false;
	}
	if (fileCorrect) {
		int sizeExportedDatabase = bazaDanych.size();
		exportVariable(exportedFile, sizeExportedDatabase);
		for (itr = bazaDanych.begin(); itr != bazaDanych.end(); ++itr) {
			//exportedFile.write((const char *)(&(itr->id)), sizeof(itr->id));
			exportVariable(exportedFile, (itr->birthdayYear));
			exportVariable(exportedFile, (itr->gender));
			exportVariable(exportedFile, (itr->name));
			exportVariable(exportedFile, (itr->surname));
			exportVariable(exportedFile, (itr->orientacja));
			exportVariable(exportedFile, (itr->kolorOczu));
			exportVariable(exportedFile, (itr->kolorWlosow));
			exportVariable(exportedFile, (itr->zainteresowania));
			exportVariable(exportedFile, (itr->prefKolorWlosow));
			exportVariable(exportedFile, (itr->prefKolorOczu));
			exportVariable(exportedFile, (itr->czyDzieci));
			exportVariable(exportedFile, (itr->czyPowaznyZwiazek));
			exportVariable(exportedFile, (itr->maxWiek));
		}
		exportedFile.close();
		cout << "Eksport bazy zakonczony sukcesem." << endl;
	}
}