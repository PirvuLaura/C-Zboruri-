#pragma once
#include"repository.h"

class repo_file: public repository
{
private:
	string file_name;
	void load_from_file();
	void save_to_file();
public:
	repo_file(string file_name);
	~repo_file();

	void set_file_name(string file_name);

	void add_zbor(zbor& z);
	void update_zbor(zbor& pVechi, zbor& pNou);
	void delete_zbor(zbor& z);
};

