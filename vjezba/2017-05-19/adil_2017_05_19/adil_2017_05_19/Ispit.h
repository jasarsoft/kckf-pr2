#pragma once
#include<iostream>
#include "Osoba.h"
#include "Datum.h"
#include "PrijvaZaIspit.h"
using namespace std;


const int max_p = 100;
struct Ispit
{
	Osoba ispitivac;
	Datum datum_ispita;
	char predmet[10];

	 int brojac_prijavljenih;
	PrijavaZaIspit prijave[max_p];
};
Ispit ucitaj_ispit()
{
	Ispit x;
	cout << "unesite ispitivaca" << endl;
	x.ispitivac = odaberite_osobu(ispitivaci, max_i);
	cout << "unesite datum ispita" << endl;
	x.datum_ispita = ucitaj_datum();
	cout << "odaberite predmet" << endl;
	cin.getline(x.predmet, 10);

	x.brojac_prijavljenih = 0;

	return x;
}



void prikazi_ispite(Ispit ispiti[], int max)
{
	for (int i = 0; i < max; i++)
	{
		Ispit& x = ispiti[i];
		info(x.datum_ispita);
		info(x.ispitivac);
		cout << ", \tBroj prijavljenih: " << ispiti[i].brojac_prijavljenih;
		cout << x.predmet << endl;
	}
}

Ispit& odaberite_ispit(Ispit ispiti[], int max)
{
	prikazi_ispite(ispiti, max);
	cout << "Unesite RB ispita: ";
	int x;
	cin >> x;
	return ispiti[x - 1];
}
