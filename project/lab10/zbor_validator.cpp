#include "zbor_validator.h"

void zbor_validator::valideaza_zbor(zbor& z)
{
	if (!(strcmp(z.get_tip(), "one-way") == 0)) {
		if (!(strcmp(z.get_tip(), "dus-intors") == 0))
		{
			throw "Tipul poate fi doar one-way sau dus-intors";
		}
	}
}
