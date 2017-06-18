#pragma once
#include <fstream>
#include "Fajlovi.h"

struct Proizvod
{
	int _ID;
	char _naziv[20];
	char _jmj[10];
	float cijena;
	static Proizvod* Napravi(char* naziv, char* jmj, float cijena)
	{
		static int generalID = 0;
		Proizvod* p = new Proizvod;
		strcpy_s(p->_naziv, naziv);
		strcpy_s(p->_jmj, jmj);
		p->cijena = cijena;
		p->_ID = generalID++;
		return p;
	}

	void Ispis()
	{
		cout << "Naziv: " << _naziv << ", jmj: " << _jmj << ", cijena: " << cijena << endl;
	}
	void Snimi(ofstream& f)
	{
		f_snimi(f, _ID);
		f_snimi(f, _naziv);
		f_snimi(f, _jmj);
		f_snimi(f, cijena);
	}

	void Ucitaj(ifstream& f)
	{
		f_ucitaj(f, _ID);
		f_ucitaj(f, _naziv);
		f_ucitaj(f, _jmj);
		f_ucitaj(f, cijena);
	}
};
