#include "zbor.h"
#include<iostream>

using namespace std;

zbor::zbor()
{
	this->cod = 0;
	this->plecare = NULL;
	this->destinatie = NULL;
	this->data = NULL;
	this->tip = NULL;
	this->pret = 0;
}

zbor::zbor(int cod, const char* plecare, const char* destinatie, const char* data,const char* tip, double pret)
{
	this->cod = cod;
	if (plecare == NULL) {
		this->plecare = NULL;
	}
	else
	{
		this->plecare = new char[strlen(plecare) + 1];
		strcpy_s(this->plecare, strlen(plecare) + 1, plecare);
	}

	if (destinatie == NULL) {
		this->destinatie = NULL;
	}
	else
	{
		this->destinatie = new char[strlen(destinatie) + 1];
		strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
	}

	if (data == NULL) {
		this->data = NULL;
	}
	else
	{
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}

	if (tip == NULL) {
		this->tip = NULL;
	}
	else
	{
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
	this->pret = pret;
}

zbor::zbor(const zbor& z)
{
	this->cod = z.cod;
	if (z.plecare == NULL) {
		this->plecare = NULL;
	}
	else
	{
		this->plecare = new char[strlen(z.plecare) + 1];
		strcpy_s(this->plecare, strlen(z.plecare) + 1, z.plecare);
	}

	if (z.destinatie == NULL) {
		this->destinatie = NULL;
	}
	else
	{
		this->destinatie = new char[strlen(z.destinatie) + 1];
		strcpy_s(this->destinatie, strlen(z.destinatie) + 1, z.destinatie);
	}

	if (z.data == NULL) {
		this->data = NULL;
	}
	else
	{
		this->data = new char[strlen(z.data) + 1];
		strcpy_s(this->data, strlen(z.data) + 1, z.data);
	}

	if (z.tip == NULL) {
		this->tip = NULL;
	}
	else
	{
		this->tip = new char[strlen(z.tip) + 1];
		strcpy_s(this->tip, strlen(z.tip) + 1, z.tip);
	}
	this->pret = z.pret;
}

zbor::~zbor()
{
	if (this->plecare != NULL) {
		delete[] this->plecare;
		this->plecare = NULL;
	}
	if (this->destinatie != NULL) {
		delete[] this->destinatie;
		this->destinatie = NULL;
	}
	if (this->data != NULL) {
		delete[] this->data;
		this->data = NULL;
	}
}

void zbor::set_code(const int cod)
{
	this->cod = cod;
}

int zbor::get_code() const
{
	return this->cod;
}

void zbor::set_plecare(const char* noua_plecare)
{
	if (this->plecare)
	{
		delete[]this->plecare;
	}
	if (noua_plecare == NULL)
	{
		this->plecare = NULL;
	}
	else
	{
		this->plecare = new char[strlen(noua_plecare) + 1];
		strcpy_s(this->plecare, strlen(noua_plecare) + 1, noua_plecare);
	}
}

char* zbor::get_plecare() const
{
	return this->plecare;
}

void zbor::set_destinatie(const char* noua_destinatie)
{
	if (this->destinatie)
	{
		delete[]this->destinatie;
	}
	if (noua_destinatie == NULL)
	{
		this->destinatie = NULL;
	}
	else
	{
		this->destinatie = new char[strlen(noua_destinatie) + 1];
		strcpy_s(this->destinatie, strlen(noua_destinatie) + 1, noua_destinatie);
	}
}

char* zbor::get_destinatie() const
{
	return this->destinatie;
}

void zbor::set_data(const char* noua_data)
{

	if (this->data)
	{
		delete[]this->data;
	}
	if (noua_data == NULL)
	{
		this->data = NULL;
	}
	else
	{
		this->data = new char[strlen(noua_data) + 1];
		strcpy_s(this->data, strlen(noua_data) + 1, noua_data);
	}
}

char* zbor::get_data() const
{
	return this->data;
}

void zbor::set_pret(const double noul_pret)
{
	this->pret = noul_pret;
}

double zbor::get_pret() const
{
	return this->pret;
}

void zbor::set_tip(const char* noul_tip)
{

	if (this->tip)
	{
		delete[]this->tip;
	}
	if (noul_tip == NULL)
	{
		this->tip = NULL;
	}
	else
	{
		this->tip = new char[strlen(noul_tip) + 1];
		strcpy_s(this->tip, strlen(noul_tip) + 1, noul_tip);
	}
}

char* zbor::get_tip()
{
	return this->tip;
}

zbor& zbor::operator=(const zbor& z)
{
	if (this != &z) {
		this->set_code(z.cod);
		this->set_plecare(z.plecare);
		this->set_destinatie(z.destinatie);
		this->set_data(z.data);
		this->set_tip(z.tip);
		this->set_pret(z.pret);
	}
	return *this;
}

bool zbor::operator==(const zbor& z)
{
	return (this->cod == z.cod && !(strcmp(z.plecare, this->plecare)) && !(strcmp(z.destinatie, this->destinatie)) && !(strcmp(z.data, this->data)) && this->pret == z.pret && !(strcmp(z.tip, this->tip)));
}

ostream& operator<<(ostream& os, const zbor& z)
{
	os << z.cod << " " << z.plecare << " " << z.destinatie << " " << z.data << " " <<z.tip << " " << z.pret;
	return os;
}
