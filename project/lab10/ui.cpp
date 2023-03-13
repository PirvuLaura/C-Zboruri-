#include "ui.h"
#include<iostream>

using namespace std;

void ui::showMenu()
{
	cout << endl;
	cout << "1. Adaugare zbor " << endl;
	cout << "2. Stergere zbor" << endl;
	cout << "3. Update zbor " << endl;
	cout << "4. Afiseaza toate cheltuielile " << endl;
	cout << endl << "0. IESIRE" << endl << endl;
}

void ui::ui_add_zbor()
{
	int cod;
	char plecare[20], destinatie[20], data[20], tip[20];
	double pret;
	cout << "Dati codul: ";
	cin >> cod;
	cout << "Dati orasul de plecare: ";
	cin >> plecare;
	cout << "Dati oradul de sosire: ";
	cin >> destinatie;
	cout << "Dati data zborului(zz-mm-yyyy): ";
	cin >> data;
	cout << "Dati tipul(one-way sau dus-intors): ";
	cin >> tip;
	cout << "Dati costul: ";
	cin >> pret;
	try {
		this->service.add_zbor(cod, plecare, destinatie, data, tip, pret);
		cout << "S-a efectuat adaugarea!";
	}
	catch (const char* e) {
		cout << "\033[31m EROARE!!!";
		cout << e;
		cout << "\033[0m";
	}
}

void ui::ui_delete_zbor()
{
	int cod;
	cout << "Dati id-ul zborului de sters: ";
	cin >> cod;
	try {
		this->service.delete_zbor_by_code(cod);
		cout << "S-a efectuat stergerea!";
	}
	catch (const char* e) {
		cout << e;
	}
}

void ui::ui_update_zbor()
{
	int cod;
	char plecare[20], destinatie[20], data[20], tip[20];
	double pret;
	cout << "Dati codul: ";
	cin >> cod;
	cout << "Dati orasul de plecare nou sau nu pentru a nu modifica: ";
	cin >> plecare;
	cout << "Dati orasul de sosire  nou sau nu pentru a nu modifica: ";
	cin >> destinatie;
	cout << "Dati data zborului(zz-mm-yyyy) noua sau nu pentru a nu modifica: ";
	cin >> data;
	cout << "Dati tipul(one-way sau dus-intors)  nou sau nu pentru a nu modifica: ";
	cin >> tip;
	cout << "Dati pretul  nou sau 0 pentru a nu modifica: ";
	cin >> pret;
	try {
		this->service.update_zbor(cod, plecare, destinatie, data, tip, pret);
		cout << "S-a efectuat adaugarea!";
	}
	catch (const char* e) {
		cout << e;
	}
	catch (...) {
		cout << "\033[31m EROARE!!!";
		cout << "\033[0m";
	}
}

void ui::ui_show_all()
{
	vector<zbor> all = this->service.get_all();
	for (zbor z : all)
		cout << z << endl;
}

ui::ui()
{
}

ui::ui(class service service)
{
	this->service = service;
}

ui::~ui()
{
}

void ui::run_menu()
{
	int cmd;
	bool ok = true;
	while (ok) {
		this->showMenu();
		cout << "\033[96m Alegeti optiunea dorita:  \033[0m";
		cin >> cmd;
		switch (cmd) {
		case 1:
			this->ui_add_zbor();
			break;
		case 2:
			this->ui_delete_zbor();
			break;
		case 3:
			this->ui_update_zbor();
			break;
		case 4:
			this->ui_show_all();
			break;
		case 0:
			ok = false;
			break;
		default:
			cout << endl << "\033[35m Optiune invalida! \033[0m" << endl << endl;
		}
	}
}
