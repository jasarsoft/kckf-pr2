#pragma once
#include <fstream>

struct Proizvod
{
	char _naziv[20];
	char _jmj[10];
	float cijena;

	void Ispis()
	{
		cout << "Naziv: " << _naziv << ", jmj: " << _jmj << ", cijena: " << cijena << endl;
	}

};

Proizvod* Proizvod_Napravi(char* naziv, char* jmj, float cijena)
{
	Proizvod* p = new Proizvod;
	strcpy_s(p->_naziv, naziv);
	strcpy_s(p->_jmj, jmj);
	p->cijena = cijena;
	return p;
}