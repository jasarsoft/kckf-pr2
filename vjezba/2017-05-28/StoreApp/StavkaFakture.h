#pragma once
#include "Proizvod.h"
#include <fstream>
using namespace  std;

struct StavkaFakture
{
	float _kolicina;
	Proizvod* _proizvod;
	
	void Ispis()
	{
		cout << _proizvod->_naziv << ", " << _proizvod->cijena << " x " << _kolicina << " = " << GetIznos() << endl;
	}

	float GetIznos()
	{
		return _kolicina * _proizvod->cijena;
	}
};

StavkaFakture* Stavka_Napravi(Proizvod* proizvod, float kolicina)
{
	StavkaFakture* s = new StavkaFakture;
	s->_kolicina = kolicina;
	s->_proizvod = proizvod;
	return s;
}
