#pragma once
#include "Grad.h"
#include "Fajlovi.h"

struct Klijent
{
	char _ime[20];
	char _prezime[20];
	Grad _grad;
	static Klijent* Napravi(char* ime, char* prezime, Grad grad)
	{
		Klijent * k = new Klijent;
		strcpy_s(k->_ime, ime);
		strcpy_s(k->_prezime, prezime);
		k->_grad = grad;
		return k;
	}

	void Snimi(ofstream& f)
	{
		f_snimi(f, _ime);
		f_snimi(f, _prezime);
		_grad.Snimi(f);
	}
	void Ucitaj(ifstream& f)
	{
		f_ucitaj(f, _ime);
		f_ucitaj(f, _prezime);
		_grad.Ucitaj(f);
	}

	void Ispis()
	{
		cout << _ime << " " << _prezime<<" (" << _grad._naziv << ") ";
	}
};
