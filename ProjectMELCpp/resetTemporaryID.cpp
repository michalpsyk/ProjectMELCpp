#include "resetTemporaryID.hpp"

void resetTemporaryID::action(vector<Person>& bazaDanych, vector<Person>::iterator& itr) {
	if (temporaryId == 0)
		cout << "Blad: w pamieci nie ma zapisanego ID zadnego uzytkownika." << endl;
	else {
		temporaryId = 0;
		cout << "ID zapisane w pamieci zostalo wyzerowane." << endl;
	}
}