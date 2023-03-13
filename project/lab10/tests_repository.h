#pragma once
#include"repository.h"
class tests_repository
{
public:
	tests_repository();
	~tests_repository();

	void test_all();
private:
	repository test_repo;
	vector<zbor> test_zbor_vector;

	void test_copy_constructor();
	void test_constuctor_with_parameters();
	void test_get_all();
	void test_get_size();

	void test_add_element();
	void test_delete_element();
	void test_update_element();
	void test_find_element();

	void test_get_elem_by_cod();

	void test_assigment_operator();
};

