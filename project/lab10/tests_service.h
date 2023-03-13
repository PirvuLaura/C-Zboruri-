#pragma once
#include"service.h"
class tests_service
{
public:
	tests_service();
	~tests_service();

	void test_all();
private:
	service service_de_test;
	repository repo;
	vector<zbor> zboruri_din_teste;

	void test_get_all();

	void test_get_repo();

	void test_add();
	void test_delete();
	void test_update();
};

