#include "addPerson.hpp"

void addPerson::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	Person *temp = new Person;
	temp->setPersonInfo();
	temp->setPreferences();
	temp->setInterests();
	bazaDanych.push_back(*temp);
	delete temp;
	cout << "\nNowa osoba zostala dodana do bazy." << endl;
}