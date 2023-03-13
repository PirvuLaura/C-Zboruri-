#include "tests_zbor.h"
#include"zbor.h"
#include"zbor_validator.h"
#include<assert.h>
#include <iostream>

tests_zbor::tests_zbor()
{
}

tests_zbor::~tests_zbor()
{
}

void tests_zbor::test_all()
{
	test_implicit_constructor();
	test_constructor_with_parameters();
	test_copy_constructor();
	test_set_cod();
	test_set_plecare();
	test_set_destinatie();
	test_set_data();
	test_set_tip();
	test_set_pret();
	test_assigment_operator();
	test_equality_operator();
	test_validator();
}

void tests_zbor::test_validator()
{
	zbor_validator validator;
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	validator.valideaza_zbor(z1);
	zbor z2(1122, "Bucuresti", "Cluj", "25-12-2021", "plec pe marte", 230);
	try {
		validator.valideaza_zbor(z2);
		assert(false);
	}
	catch (const char* e) {
		assert(true);
	}
}

void tests_zbor::test_implicit_constructor()
{
	zbor z1;
	assert(z1.get_code() == 0);
	assert(z1.get_destinatie() == NULL);
	assert(z1.get_plecare() == NULL);
	assert(z1.get_data() == NULL);
	assert(z1.get_tip() == NULL);
	assert(z1.get_pret() == 0);
}

void tests_zbor::test_constructor_with_parameters()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	assert(z1.get_code() == 1122);
	assert(strcmp(z1.get_destinatie(), "Cluj") == 0);
	assert(strcmp(z1.get_plecare(), "Bucuresti") == 0);
	assert(strcmp(z1.get_data(), "25-12-2021") == 0);
	assert(strcmp(z1.get_tip(), "dus-intors") == 0);
	assert(z1.get_pret() == 230);
}

void tests_zbor::test_copy_constructor()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230), z2 = z1;
	assert(z2.get_code() == 1122);
	assert(strcmp(z2.get_destinatie(), "Cluj") == 0);
	assert(strcmp(z2.get_plecare(), "Bucuresti") == 0);
	assert(strcmp(z2.get_data(), "25-12-2021") == 0);
	assert(strcmp(z2.get_tip(), "dus-intors") == 0);
	assert(z2.get_pret() == 230);
}

void tests_zbor::test_set_cod()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	z1.set_code(2000);
	assert(z1.get_code() == 2000);
}

void tests_zbor::test_set_plecare()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	z1.set_plecare("Arad");
	assert(strcmp(z1.get_plecare(), "Arad") == 0);
}

void tests_zbor::test_set_destinatie()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	z1.set_destinatie("Arad");
	assert(strcmp(z1.get_destinatie(), "Arad") == 0);
}

void tests_zbor::test_set_data()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	z1.set_data("25-12-2020");
	assert(strcmp(z1.get_data(), "25-12-2020") == 0);
}

void tests_zbor::test_set_tip()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	z1.set_tip("dus");
	assert(strcmp(z1.get_tip(), "dus") == 0);
}

void tests_zbor::test_set_pret()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230);
	z1.set_pret(300);
	assert(z1.get_pret() == 300);
}

void tests_zbor::test_assigment_operator()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230), z2;
	z2 = z1;
	assert(z2.get_code() == 1122);
	assert(strcmp(z2.get_destinatie(), "Cluj") == 0);
	assert(strcmp(z2.get_plecare(), "Bucuresti") == 0);
	assert(strcmp(z2.get_data(), "25-12-2021") == 0);
	assert(strcmp(z2.get_tip(), "dus-intors") == 0);
	assert(z2.get_pret() == 230);
}

void tests_zbor::test_equality_operator()
{
	zbor z1(1122, "Bucuresti", "Cluj", "25-12-2021", "dus-intors", 230), z2;
	z2 = z1;
	assert(z2 == z1);
}
