#include "findMatch.hpp"

double findMatch::percentageMatchedInterests(Person& user, Person& foundMatchedPerson) {
	double matchedInterests = 0;
	vector <string>::iterator itrIntUser;
	vector <string>::iterator itrIntfMP;
	vector <string> interestsUser = user.interestsAsVector();
	vector <string> interestsfMP = foundMatchedPerson.interestsAsVector();
	for (itrIntUser = interestsUser.begin(); itrIntUser != interestsUser.end(); ++(itrIntUser)) {
		for (itrIntfMP = interestsfMP.begin(); itrIntfMP != interestsfMP.end(); ++(itrIntfMP)) {
			if (*itrIntUser == *itrIntfMP)
				matchedInterests += 1;
		}
	}
	return (matchedInterests / interestsUser.size()) * 100;
}

void findMatch::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	if (temporaryId == 0)
		cout << "Podaj ID osoby, dla ktorej chcesz znalezc dopasowanie:\n";
	bool foundWithID = returnItrWithID(bazaDanych, itr);
	bool foundMatch = false;
	vector<Person>::iterator user = itr;
	vector<Person>::iterator foundMatchedPerson;
	cout << "Szukam dopasowania dla osoby:\n" << endl;
	printTitleShortPersonInfo();
	user->showPersonInfo(); 
	if (foundWithID) {
		cout << "\nZnalezione dopasowania:\n" << endl;
		for (foundMatchedPerson = bazaDanych.begin(); foundMatchedPerson != bazaDanych.end(); ++foundMatchedPerson) {
			if (*user == *foundMatchedPerson && user->id != foundMatchedPerson->id) {
				foundMatch = true;
				foundMatchedPerson->showPersonInfo();
				cout << "Dopasowanie zainteresowan wynosi " << percentageMatchedInterests(*user, *foundMatchedPerson) << "%" << endl;
			}
		}
	}
	if (!foundMatch)
		cout << "Niestety nie znaleziono pasujacej osoby w bazie danych." << endl;
}
