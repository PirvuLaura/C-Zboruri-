#include "tests_repository.h"
#include <cassert>

tests_repository::tests_repository()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);;
	zbor z2(3333, "Sibiu", "Valcea", "22-10-2020", "one-way", 200);
	zbor z3(3232, "Arad", "Craiova", "17-03-2021", "dus-intors", 150);

	test_zbor_vector.push_back(z1);
	test_zbor_vector.push_back(z2);
	test_zbor_vector.push_back(z3);
}

tests_repository::~tests_repository()
{
}

void tests_repository::test_all()
{
	this->test_add_element();
	this->test_copy_constructor();
	this->test_constuctor_with_parameters();
	this->test_get_all();
	this->test_get_size();
	this->test_assigment_operator();

	this->test_delete_element();
	this->test_update_element();
	this->test_find_element();

	this->test_get_elem_by_cod();
}

void tests_repository::test_add_element()
{
	this->test_repo.add_element(this->test_zbor_vector[0]);
	this->test_repo.add_element(this->test_zbor_vector[1]);
	this->test_repo.add_element(this->test_zbor_vector[2]);
	vector<zbor> all_adds = this->test_repo.get_all();
	assert(this->test_repo.get_size() == 3);
	for (int i = 0; i < this->test_repo.get_size(); i++) {
		assert(all_adds[i] == this->test_zbor_vector[i]);
	}
}

void tests_repository::test_delete_element()
{
	zbor z4(3232, "Arad", "Craiova", "17-03-2021", "dus-intors", 150);
	this->test_repo.delete_element(z4);

	vector<zbor> all_elem = this->test_repo.get_all();
	assert(this->test_repo.get_size() == 2);
	assert(all_elem[0] == this->test_zbor_vector[0]);
	assert(all_elem[1] == this->test_zbor_vector[1]);


	zbor z5(3232, "Bucuresti", "Craiova", "17-03-2021", "dus-intors", 150);
	this->test_repo.delete_element(z5);

	assert(this->test_repo.get_size() == 2);

	this->test_repo.add_element(z4);
}

void tests_repository::test_update_element()
{
	zbor z4(3232, "Arad", "Craiova", "17-03-2021", "dus-intors", 250);
	this->test_repo.update_element(this->test_zbor_vector[2], z4);
	vector<zbor> all_elem = this->test_repo.get_all();
	assert(all_elem[2] == z4);
	this->test_repo.update_element(z4, this->test_zbor_vector[2]);
}

void tests_repository::test_find_element()
{
	zbor z4(3232, "Arad", "Craiova", "17-03-2021", "dus-intors", 250);
	assert(this->test_repo.find(this->test_zbor_vector[2]));
	assert(this->test_repo.find(z4)==false);
}

void tests_repository::test_get_elem_by_cod()
{
	assert(this->test_repo.get_elem_by_cod(1122) == this->test_zbor_vector[0]);
	try {
		this->test_repo.get_elem_by_cod(1123);
	}
	catch (const char* e) {
		assert(strcmp(e, "Nu s-a gasit acest zbor! Mai incercati") == 0);
	}
}

void tests_repository::test_copy_constructor()
{
	repository r(this->test_repo);
	vector<zbor> all = r.get_all();
	for (int i = 0; i < r.get_size(); i++) {
		assert(all[i] == this->test_zbor_vector[i]);
	}
}

void tests_repository::test_constuctor_with_parameters()
{
	repository r(this->test_zbor_vector);
	vector<zbor> all = r.get_all();
	for (int i = 0; i < r.get_size(); i++) {
		assert(all[i] == this->test_zbor_vector[i]);
	}
}

void tests_repository::test_get_all()
{
	vector<zbor> all = this->test_repo.get_all();
	for (int i = 0; i < this->test_repo.get_size(); i++) {
		assert(all[i] == this->test_zbor_vector[i]);
	}
}

void tests_repository::test_get_size()
{
	int size = this->test_repo.get_size();
	assert(size == 3);
}

void tests_repository::test_assigment_operator()
{
	repository r;
	r = this->test_repo;
	vector<zbor> all = r.get_all();
	for (int i = 0; i < r.get_size(); i++) {
		assert(all[i] == this->test_zbor_vector[i]);
	}
}
