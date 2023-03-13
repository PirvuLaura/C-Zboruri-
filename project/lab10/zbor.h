#pragma once
#include<string>

using namespace std;

class zbor
{
private:
	int cod;
	char* plecare;
	char* destinatie;
	char* data;
	char* tip;
	double pret;
public:
	zbor();
	zbor(int, const char*, const char*, const char*, const char*, double);
	zbor(const zbor&);
	~zbor();

	void set_code(const int);
	int get_code() const;

	void set_plecare(const char*);
	char* get_plecare() const;

	void set_destinatie(const char*);
	char* get_destinatie() const;

	void set_data(const char*);
	char* get_data() const;

	void set_pret(const double);
	double get_pret() const;

	void set_tip(const char*);
	char* get_tip();

	zbor& operator=(const zbor&);
	bool operator==(const zbor&);

	friend ostream& operator<<(ostream&, const zbor&);
};

