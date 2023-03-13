#include "service.h"

service::service()
{
}

service::service(repository& new_repo)
{
	this->repo = new_repo;
}

service::~service()
{
}

void service::set_repo(repository& new_repo)
{
	this->repo = new_repo;
}

repository service::get_repo() const
{
	return this->repo;
}

vector<zbor> service::get_all() const
{
	return this->repo.get_all();
}

void service::add_zbor(int cod, const char* plecare, const char* destinatie, const char* data, const char* tip, double pret)
{
	zbor_validator validator;
	zbor z(cod, plecare, destinatie, data, tip, pret);
	validator.valideaza_zbor(z);
	vector<zbor> all = this->get_all();
	for (auto z : all) {
		if (z.get_code() == cod) {
			throw "Codul trebuie sa fie unic!";
		}
	}
	this->repo.add_element(z);
}

void service::delete_zbor_by_code(int cod)
{
	zbor z = this->repo.get_elem_by_cod(cod);
	this->repo.delete_element(z);
}

void service::update_zbor(int cod, const char* plecare, const char* destinatie, const char* data, const char* tip, double pret)
{
	zbor_validator validator;
	zbor z = this->repo.get_elem_by_cod(cod);
	zbor z_new(cod, strcmp(plecare, "nu") == 0 ? z.get_plecare() : plecare, strcmp(destinatie, "nu") == 0 ? z.get_destinatie() : destinatie,
		strcmp(data, "nu") == 0 ? z.get_data() : data, strcmp(tip, "nu") == 0 ? z.get_tip() : tip, pret == 0 ? z.get_pret() : pret);
	validator.valideaza_zbor(z_new);
	this->repo.update_element(z, z_new);
}
