#pragma once
#include "Datum.h"
#include "Klijent.h"
#include "stavkafakture.h"
#include "Kolekcija.h"
#include <string>

struct Faktura
{
	int _ID;
	Datum _datum;
	Klijent _klijent;
	Kolekcija<StavkaFakture*> _stavke;

	static Faktura* Napravi(Datum datum, Klijent klijent)
	{
		Faktura* x = new Faktura;
		x->_datum = datum;
		x->_klijent = klijent;
		return x;
	}

	float GetIznosSuma()
	{
		float x = 0;
		_stavke.ForEach([&x](StavkaFakture* s){
			x += s->GetIznos();
		});
		return x;
	}

	void Ispis()
	{
		cout << "Broj: " << _ID << ", Datum: ";
		_datum.Ispis();
		_klijent.Ispis();
		cout << ", suma: " << GetIznosSuma() << endl;
	}

	void Snimi(ofstream& f)
	{
		f_snimi(f, _ID);
		f_snimi(f, _datum);
		f_snimi(f, _stavke.brojac);
		_stavke.ForEach([&f](StavkaFakture* s){
			s->Snimi(f);
		});
		_klijent.Snimi(f);
	}
	void Ucitaj(ifstream& f)
	{
		f_ucitaj(f, _ID);
		f_ucitaj(f, _datum);
		f_ucitaj(f, _stavke.brojac);
		_stavke.ForEach([&f](StavkaFakture* &s) {
			s = new StavkaFakture;
			s->Ucitaj(f);
		});
		_klijent.Ucitaj(f);
	}
};

