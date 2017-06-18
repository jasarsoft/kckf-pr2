#include <iostream>
#include <functional>
using namespace std;

#include "Kolekcija.h"


void Kolekcija::kDodaj(Tip newV)
{
	//dodaj newV u podaci na poziciju brojac 
	//uvecati brojac 
	podaci[brojac++] = newV;
}

Kolekcija Kolekcija::kFilter(function<bool(Tip&)> f)
{
	Kolekcija newK;
	for (size_t i = 0; i < brojac; i++)
	{
		Tip &x = podaci[i];
		if (f(x)) {
			newK.kDodaj(x);
		}
	} //iz kolekcije k u kolekciju newK kopirati elemente koji zadovoljavaju uslov f 
	return newK;
}

void Kolekcija::kForEach(function<void(Tip&)> f)
{
	//za svaki element iz kolekcije k izvrsi zadatak f 
	for (int i = 0; i < brojac; i++)
	{
		Tip &x = podaci[i];
		f(x);
	}
}