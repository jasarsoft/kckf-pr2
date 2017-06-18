#pragma once
#include "Proizvod.h"
#include <fstream>
using namespace  std;

struct StavkaFakture
{
	int _ID;
	float _kolicina;
	Proizvod _proizvod;
	static StavkaFakture* Napravi(Proizvod proizvod, float kolicina)
	{
		StavkaFakture* s = new StavkaFakture;
		s->_kolicina = kolicina;
		s->_proizvod = proizvod;
		return s;
	}
	void Ispis()
	{
		cout << _proizvod._naziv << ", " << _proizvod.cijena << " x " << _kolicina << " = " << GetIznos() << endl;
	}
	void Snimi(ofstream& f)
	{
		f_snimi(f, _ID);
		f_snimi(f, _kolicina);
		_proizvod.Snimi(f);
	}
	void Ucitaj(ifstream& f)
	{
		f_ucitaj(f, _ID);
		f_ucitaj(f, _kolicina);
		_proizvod.Ucitaj(f);
	}

	float GetIznos()
	{
		return _kolicina * _proizvod.cijena;
	}
};
