#include "tests_service.h"
#include<assert.h>

tests_service::tests_service()
{
	this->service_de_test.set_repo(this->repo);

	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);;
	zbor z2(3333, "Sibiu", "Valcea", "22-10-2020", "one-way", 200);
	zbor z3(3232, "Arad", "Craiova", "17-03-2021", "dus-intors", 150);

	this->service_de_test.add_zbor(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	this->service_de_test.add_zbor(3333, "Sibiu", "Valcea", "22-10-2020", "one-way", 200);
	this->service_de_test.add_zbor(3232, "Arad", "Craiova", "17-03-2021", "dus-intors", 150);

	this->zboruri_din_teste.push_back(z1);
	this->zboruri_din_teste.push_back(z2);
	this->zboruri_din_teste.push_back(z3);
}

tests_service::~tests_service()
{
}

void tests_service::test_all()
{
	this->test_get_all();

	this->test_get_repo();

	this->test_add();
	this->test_delete();
	this->test_update();
}

void tests_service::test_get_all()
{
	vector<zbor> all = this->service_de_test.get_all();
	assert(this->zboruri_din_teste[0] == all[0]);
	assert(this->zboruri_din_teste[1] == all[1]);
	assert(this->zboruri_din_teste[2] == all[2]);
}

void tests_service::test_get_repo()
{
	repository tesare_get_repo;
	tesare_get_repo = this->service_de_test.get_repo();
	vector<zbor> all = tesare_get_repo.get_all();
	int dimensiune = tesare_get_repo.get_size();
	for (int i = 0; i < dimensiune; i++) {
		assert(all[i] == this->zboruri_din_teste[i]);
	}
}

void tests_service::test_add()
{
	zbor z4(5562, "Arad", "Bucuresti", "22-03-2021", "one-way", 100);
	this->service_de_test.add_zbor(5562, "Arad", "Bucuresti", "22-03-2021", "one-way", 100);
	assert(this->service_de_test.get_all()[3] == z4);
}

void tests_service::test_delete()
{
	this->service_de_test.delete_zbor_by_code(5562);
	assert(this->service_de_test.get_all().size() == 3);
	try {
		this->service_de_test.delete_zbor_by_code(2232);
		assert(false);
	}
	catch (const char* e) {
		assert(true);
	}
	assert(this->service_de_test.get_all().size() == 3);
}

void tests_service::test_update()
{
	this->service_de_test.update_zbor(1122, "Sibiu", "nu", "26-12-2021", "nu", 0);
	zbor z(1122, "Sibiu", "Cluj", "26-12-2021", "dus-intors", 230);
	assert(z == this->service_de_test.get_all()[0]);
	try {
		this->service_de_test.update_zbor(1100, "Sibiu", "nu", "26-12-2021", "nu", 0);
		assert(false);
	}
	catch (const char* e) {
		assert(true);
	}
}
