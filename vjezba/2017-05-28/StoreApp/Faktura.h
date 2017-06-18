#pragma once
#include "Datum.h"
#include "Klijent.h"
#include "stavkafakture.h"
#include "Kolekcija.h"
#include <string>

struct Faktura
{
	Datum _datum;
	Klijent* _klijent;
	Kolekcija _stavke;

	float GetIznosSuma()
	{
		float x = 0;

		for(int i=0;i<_stavke.brojac;i++)
		{
			x += _stavke.Get(i)->GetIznos();
		}
		return x;
	}

	void Ispis()
	{
		cout << "Datum: ";
		_datum.Ispis();
		_klijent->Ispis();
		cout << ", suma: " << GetIznosSuma() << endl;
	}
	
};

Faktura* Faktura_Napravi(Datum datum, Klijent* klijent)
{
	Faktura* x = new Faktura;
	x->_datum = datum;
	x->_klijent = klijent;
	return x;
}