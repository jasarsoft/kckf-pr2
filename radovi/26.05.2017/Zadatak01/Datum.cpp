#include <iostream>
using namespace std;

#include "Datum.h"

Datum Datum::Napravi(int d, int m, int g)
{
	Datum datum;
	datum._dan = d;
	datum._mjesec = m;
	datum._godina = g;
	return datum;
}

bool Datum::jednako(Datum& drugi)
{
	return	(_dan == drugi._dan) &&
		(_mjesec == drugi._mjesec) &&
		(_godina == drugi._godina);
}

void Datum::Ispis()
{
	cout << "Datum: " << _dan << "." << _mjesec << "." << _godina << endl;
}