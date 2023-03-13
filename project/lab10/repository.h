#pragma once
#include<vector>
#include"zbor.h"
using namespace std;

class repository
{
protected:
	vector<zbor> elements;
public:
	repository();
	repository(vector<zbor>);
	repository(const repository&);
	virtual ~repository();

	void add_element(const zbor&);
	void update_element(const zbor&, const zbor&);
	void delete_element(const zbor&);

	bool find(zbor&);

	zbor get_elem_by_cod(int);

	vector<zbor> get_all() const;

	int get_size() const;

	repository& operator=(const repository&);

	void empty();
};

