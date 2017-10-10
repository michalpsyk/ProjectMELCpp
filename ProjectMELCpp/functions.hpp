#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <iomanip> // formatowanie wyswietlenia

using namespace std;

/*!
Template funkcji do wczytywania zmiennej z klawiatury za pomoca cin.
*/
template <class typ>
void wczytaj(typ& tmp) {
	//Funkcja sluzaca do wczytania wartosci zmiennej z klawiatury.
	while (!(cin >> tmp)) {
		cout << "Zly wybor!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*!
Template funkcji do wypisywania zmiennej ustalonym odstepem z lewej.
*/
template<class typ>
void printElement(typ& t, int numWidth)
{
	cout << left << setw(numWidth) << t;
}

/*!
Funkcja wyswietla naglowek dla funkcji showPersonInfo - linijke z nazwa zmiennych.
UWAGA: Nalezy dopasowac szerokosc wyswietlania tej funkcji z wywolaniami
	   w funkcji showPersonInfo klasy Person
*/
void printTitleShortPersonInfo();

#endif