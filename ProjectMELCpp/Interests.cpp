#include "Interests.hpp"

void Interests::setInterests() {
	cout << "Podaj zainteresowania uzykownika, wypisujac je po przecinku:" << endl;
	cin.clear();
	cin.sync();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, zainteresowania);
}
vector<string> Interests::interestsAsVector() {
	vector <string> zainteresowaniaWektor;
	stringstream stringStreamIntrests(zainteresowania);
	string oneItemTemp;
	getline(stringStreamIntrests, oneItemTemp, ',');
	zainteresowaniaWektor.push_back(oneItemTemp);
	while (getline(stringStreamIntrests, oneItemTemp, ',')) {
		oneItemTemp.erase(0, 1);
		zainteresowaniaWektor.push_back(oneItemTemp);
	}
	return zainteresowaniaWektor;
}
void Interests::showInterests() const {
	cout << "Zainteresowania wybranego uzykownika:" << endl;
	cout << zainteresowania << endl;
}

void Interests::editInterests() {
	cout << "\nAktualne zainteresowania:" << endl;
	cout << zainteresowania << endl << endl;
	setInterests();
}