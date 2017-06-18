#pragma once
#include <iostream>
using namespace std;
#include "Datum.h"

enum VrstaTransakcije
{
	UPLATA,
	ISPLATA
};

struct Transakcija
{
	Datum _datumTransakcije;
	char _TO[20];
	float _iznos;
	VrstaTransakcije _vrstaTransakcije;
	bool _aktivna;

	void Ispis()
	{
		if (_aktivna)
		{
			cout << "Vrsta transakcije: " << _vrstaTransakcije << endl;
			cout << "Iznos: " << _iznos << endl;
			cout << "To: " << _TO << endl;
		}
		else
		{
			cout << "Transakcija je obrisana" << endl;
		}
	}	
};

Transakcija* Transakcija_NapraviUplatu(float iznos, const Datum& datum)
{
	Transakcija* t = new Transakcija;

	t->_datumTransakcije = datum;
	strcpy_s(t->_TO, "none");
	t->_iznos = iznos;
	t->_vrstaTransakcije = UPLATA;
	t->_aktivna = true;

	return t;
}

Transakcija* Transakcija_NapraviIsplatu(float iznos, char* to, Datum& datum)
{
	Transakcija* t = new Transakcija;

	t->_datumTransakcije = datum;
	strcpy_s(t->_TO, to);
	t->_iznos = iznos;
	t->_vrstaTransakcije = ISPLATA;
	t->_aktivna = true;

	return t;
}