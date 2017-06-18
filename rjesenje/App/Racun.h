#pragma once
#pragma once

#include <iostream>
#include "Transakcija.h"
#include "TransakcijaKolekcija.h"
using namespace std;


struct Racun
{
	char _brojRacuna[20];
	bool _aktivan;
	TransakcijaKolekcija transakcije;

	void Ispis()
	{
		cout << "Broj raèuna: " << _brojRacuna << endl;
		cout << "Broj transakcija: " << transakcije.brojac << endl;
		cout << "Stanje na raèunu: " << Saldo() << endl;
	}

	void Deaktiviraj()
	{
		_aktivan = false;
	}

	float Saldo()
	{
		//stanje na raèunu
		float s = 0;

		for (int i = 0; i < transakcije.brojac; i++)
		{
			TransakcijaTip& tt = transakcije.Get(i);

			if (tt->_aktivna)
			{
				if (tt->_vrstaTransakcije == UPLATA)
					s += tt->_iznos;
				else //tt->_vrstaTransakcije == ISPLATA
					s -= tt->_iznos;
			}
		}

		return s;
	}
};


Racun* Racun_Napravi(char* broj_racuna)
{
	Racun* r = new Racun;

	r->_aktivan = true;
	strcpy_s(r->_brojRacuna, broj_racuna);

	return r;
}