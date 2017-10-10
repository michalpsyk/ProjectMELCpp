#include "Database.hpp"

using namespace std;

int main() {
	cout << "Witaj w bazie danych biura matrymonialnego Venus!\n" << endl;
	Database* bazaDanych = new Database;
	bazaDanych->menu();
	delete bazaDanych;
	
	_getch();
	return 1;
}