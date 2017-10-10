#include "MenuOption.hpp"

int MenuOption::temporaryId = 0;

bool returnItrWithID(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	int idTemp;
	if (MenuOption::temporaryId == 0) {
		wczytaj(idTemp);
	}
	else
		idTemp = MenuOption::temporaryId;
	
	bool znaleziono = false;
	for (itr = bazaDanych.begin(); itr != bazaDanych.end(); ++itr) {
		if (itr->id == idTemp) {
			znaleziono = true;
			break;
		}
	}
	try {
		if (!znaleziono)
			throw "\nBlad: Nie znaleziono osoby o podanym ID.";
	}
	catch (char* text) {
		cout << text << endl;
	}
	return znaleziono;
}