#include "repo_file.h"
#include<iostream>
#include<fstream>

using namespace std;

void repo_file::load_from_file()
{
	ifstream f(this->file_name);
	if (f.is_open())
	{
		this->empty();
		string linie;
		string delim = " ";

		while (getline(f, linie))
		{
			int cod;
			char plecare[20], destinatie[20], data[20], tip[20];
			double pret;

			int pos = linie.find(delim);
			cod = stoi(linie.substr(0, pos));
			linie = linie.erase(0, pos + 1);

			pos = linie.find(delim);
			strcpy_s(plecare, linie.substr(0, pos).length()+1, linie.substr(0, pos).c_str());
			linie = linie.erase(0, pos + 1);

			pos = linie.find(delim);
			strcpy_s(destinatie, linie.substr(0, pos).length() + 1, linie.substr(0, pos).c_str());
			linie = linie.erase(0, pos + 1);

			pos = linie.find(delim);
			strcpy_s(data, linie.substr(0, pos).length() + 1, linie.substr(0, pos).c_str());
			linie = linie.erase(0, pos + 1);

			pos = linie.find(delim);
			strcpy_s(tip, linie.substr(0, pos).length() + 1, linie.substr(0, pos).c_str());
			linie = linie.erase(0, pos + 1);

			pret = stod(linie);

			zbor z(cod, plecare, destinatie, data, tip, pret);
			this->elements.push_back(z);
		}
	}
	f.close();
}

void repo_file::save_to_file()
{
	ofstream f(this->file_name);
	if (f.is_open())
	{
		for (zbor zbor : this->elements)
		{
			f << zbor << endl;
		}
	}
	f.close();
}

repo_file::repo_file(string file_name)
{
	this->file_name = file_name;
	this->load_from_file();
}

repo_file::~repo_file()
{
}

void repo_file::set_file_name(string file_name)
{
	this->file_name = file_name;
	this->save_to_file();
}

void repo_file::add_zbor(zbor& z)
{
	repository::add_element(z);
	this->save_to_file();
}

void repo_file::update_zbor(zbor& z_vechi, zbor& z_nou)
{
	repository::update_element(z_vechi, z_nou);
	this->save_to_file();
}

void repo_file::delete_zbor(zbor& z)
{
	repository::delete_element(z);
	this->save_to_file();
}
