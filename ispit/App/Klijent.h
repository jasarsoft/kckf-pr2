#pragma once
#include "RacunKolekcija.h"

struct Klijent
{
	char* _ime;
	char* _prezime;
	RacunKolekcija racuni;

	void Ispis()
	{
		cout << _ime << " " << _prezime << endl;;
	}
};

Klijent* Klijent_Napravi(char* ime, char* prezime)
{

}
