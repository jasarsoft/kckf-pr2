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
	Klijent* klijent = new Klijent;

	int v1 = strlen(ime) + 1;
	int v2 = strlen(prezime) + 1;

	klijent->_ime = new char[v1];
	klijent->_prezime = new char[v2];
	
	strcpy_s(klijent->_ime, v1, ime);
	strcpy_s(klijent->_prezime, v2, prezime);

	return klijent;
}
