#include "Racun.h"


void Racun::Ispis()
{
	cout << "Vrsta racuna: " << _vrstaRacuna << endl;
	cout << "Broj racuna: " << _brojRacuna << endl;
	//transakcije
	_aktivan ? cout << "Racuna aktivan\n" : cout << "Racun nije aktivan\n";
}


void Racun::Uplata(float iznos, Datum datum)
{
	
}


float Racun::Saldo()
{
	float Saldo = 0;

	for (int i = 0; i < transakcije.brojac; i++)
	{
		Transakcija& t = transakcije.podaci[i];

		if (t._vrstaTransakcije == UPLATA)
			Saldo += t._iznos;
		else
			Saldo -= t._iznos;
	}

	return Saldo;
}