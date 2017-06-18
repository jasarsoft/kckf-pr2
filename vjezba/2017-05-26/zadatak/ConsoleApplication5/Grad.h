#pragma once
#include <fstream>
#include "Fajlovi.h"

struct Grad
{
	char _naziv[20];
	static Grad* Napravi(char* naziv)
	{
		Grad* g = new Grad;
		strcpy_s(g->_naziv, 20, naziv);
		return g;
	}

	void Snimi(ofstream& f)
	{
		f_snimi(f, _naziv);
	}
	void Ucitaj(ifstream& f)
	{
		f_ucitaj(f, _naziv);
	}
};
