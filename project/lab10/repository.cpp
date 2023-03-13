#include "repository.h"
#include<vector>

using namespace std;

repository::repository()
{
}

repository::repository(vector<zbor> v)
{
    for (int i = 0; i < v.size(); i++) {
        this->elements.push_back(v[i]);
    }
}

repository::repository(const repository& r)
{
    for (int i = 0; i < r.elements.size(); i++) {
        this->elements.push_back(r.elements[i]);
    }
}

repository::~repository()
{
    this->elements.clear();
}

void repository::add_element(const zbor& p)
{
    this->elements.push_back(p);
}

void repository::update_element(const zbor& old_elem,const zbor& new_elem)
{
    for (int i = 0; i < this->elements.size(); i++)
	{
		if (this->elements[i] == old_elem)
		{
			this->elements[i] = new_elem;
    	}
	}
}

void repository::delete_element(const zbor& elem)
{
    for (int i = 0; i < this->elements.size(); i++)
    {
        if (this->elements[i] == elem)
        {
            this->elements.erase(this->elements.begin() + i);
        }
    }
}

bool repository::find(zbor& p)
{
    for (int i = 0; i < this->elements.size(); i++)
    {
        if (this->elements[i] == p)
        {
            return true;
        }
    }
    return false;
}

zbor repository::get_elem_by_cod(int cod)
{
    for (int i = 0; i < this->elements.size(); i++)
    {
        if (this->elements[i].get_code() == cod)
        {
            return this->elements[i];
        }
    }
    throw "Nu s-a gasit acest zbor! Mai incercati";
}

vector<zbor> repository::get_all() const
{
    return  this->elements;
}

int repository::get_size() const
{
    return this->elements.size();
}

repository& repository::operator=(const repository& r)
{
    if (this != &r) {
        for (int i = 0; i < r.elements.size(); i++) {
            this->elements.push_back(r.elements[i]);
        }
    }
    return *this;
}

void repository::empty()
{
    this->elements.clear();
}

