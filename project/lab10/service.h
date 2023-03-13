#pragma once
#include"repository.h"
#include"zbor_validator.h"

class service
{
private:
	repository repo;
public:
	service();
	service(repository& new_repo);
	~service();

	void set_repo(repository& new_repo);
	repository get_repo() const;

	vector<zbor> get_all() const;

	void add_zbor(int, const char*, const char*, const char*, const char*, double);
	void delete_zbor_by_code(int);
	void update_zbor(int, const char*, const char*, const char*, const char*, double);
};

