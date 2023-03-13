#pragma once
class tests_zbor
{
public:
	tests_zbor();
	~tests_zbor();

	void test_all();
private:
	void test_validator();
	void test_implicit_constructor();
	void test_constructor_with_parameters();
	void test_copy_constructor();
	void test_set_cod();
	void test_set_plecare();
	void test_set_destinatie();
	void test_set_data();
	void test_set_tip();
	void test_set_pret();
	void test_assigment_operator();
	void test_equality_operator();
};

