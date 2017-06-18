#pragma once
#include<iostream>
#include "Osoba.h"
#include "Datum.h"
#include "PrijvaZaIspit.h"
using namespace std;


const int max_p = 100;
struct Ispit
{
	shared_ptr<Osoba> ispitivac;
	shared_ptr<Datum> datum_ispita;
	char predmet[10];

	int brojac_prijavljenih;
	shared_ptr<PrijavaZaIspit> prijave[max_p];
};
shared_ptr<Ispit> ucitaj_ispit()
{
	shared_ptr<Ispit> x (new Ispit);
	cout << "unesite ispitivaca" << endl;
	x->ispitivac = odaberite_osobu(ispitivaci, max_i);
	cout << "unesite datum ispita" << endl;
	x->datum_ispita = ucitaj_datum();
	cout << "odaberite predmet" << endl;
	cin.getline(x->predmet, 10);

	x->brojac_prijavljenih = 0;

	return x;
}



void prikazi_ispite(shared_ptr<Ispit> ispiti[], int max)
{
	for (int i = 0; i < max; i++)
	{
		shared_ptr<Ispit> x = ispiti[i];
		info(x->datum_ispita);
		info(x->ispitivac);
		cout << ", \tBroj prijavljenih: " << ispiti[i]->brojac_prijavljenih;
		cout << x->predmet << endl;
	}
}

shared_ptr<Ispit> odaberite_ispit(shared_ptr<Ispit> ispiti[], int max)
{
	prikazi_ispite(ispiti, max);
	cout << "Unesite RB ispita: ";
	int x;
	cin >> x;
	//return &ispiti[x - 1];
	return ispiti[x-1];
}
