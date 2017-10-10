#include "Database.hpp"

Database::Database() {
	options.push_back(new displayDatabase);
	options.push_back(new addPerson);
	options.push_back(new findPerson);
	options.push_back(new resetTemporaryID);
	options.push_back(new displayPerson);
	options.push_back(new editPerson);
	options.push_back(new deletePerson);
	options.push_back(new findMatch);
	options.push_back(new importDatabase);
	options.push_back(new exportDatabase);
	options.push_back(new exitDatabase);
}

Database::~Database() {
	for (vector<MenuOption*>::iterator itr = options.begin(); itr != options.end(); ++itr)
		delete *itr;
}

void Database::menu() {
	int choise;
	while (true) {
		cout << "Wybierz jedna z ponizszych opcji:\n";
		int i = 1;
		for (vector <MenuOption*>::iterator it = Database::options.begin(); it != Database::options.end(); it++, i++)
		{
			cout << "[" << i << "] - " << (*it)->getText() << endl;
		}
		choise = 0;
		while (choise < 1 || choise > options.size()) {
			wczytaj(choise);
			if (choise < 1 || choise > options.size())
				cout << "Zly wybor!" << endl;
		}
		system("cls");
		choise -= 1;
		options[choise]->action(bazaDanych, itr);

		cout << "\nAby powrocic do menu wcisnij dowolny klawisz." << endl;
		_getch();
		system("cls");
	}
}