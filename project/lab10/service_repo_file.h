#pragma once
#include "repo_file.h"
#include "zbor_validator.h"
class service_repo_file
{
private:
	repo_file repo = repo_file("zboruri.txt");
public:
	service_repo_file();
	service_repo_file(repo_file& new_repo);
	~service_repo_file();

	void set_repo(repo_file& new_repo);
	repo_file get_repo() const;

	vector<zbor> get_all() const;

	void add_zbor(int, const char*, const char*, const char*, const char*, double);
	void delete_zbor_by_code(int);
	void update_zbor(int, const char*, const char*, const char*, const char*, double);

	vector<zbor> get_zboruri_dupa_toate(const char*, const char*, const char*) const;
	vector<zbor> get_dus_intors() const;
};

