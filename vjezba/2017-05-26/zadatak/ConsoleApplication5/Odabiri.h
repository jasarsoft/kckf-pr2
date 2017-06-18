#pragma once
#include "Grad.h"


Grad* odaberi(Kolekcija<Grad*> kolekcija)
{
	cout << "GRADOVI" << endl;

	int unos;
	do
	{
		int rb = 1;
		kolekcija.ForEach([&](Grad* g) {
			cout << rb << ". " << g->_naziv;
		});
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos >= 1 && unos <= kolekcija.brojac)
			return kolekcija.podaci[unos];
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}

Klijent* odaberi(Kolekcija<Klijent*> kolekcija)
{
	cout << "KLIJENTI" << endl;

	int unos;
	do
	{
		int rb = 1;
		kolekcija.ForEach([&](Klijent* g) {
			cout << rb << ". ";
			g->Ispis();
			cout << endl;
		});
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos >= 1 && unos <= kolekcija.brojac)
			return kolekcija.podaci[unos];
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}

Proizvod* odaberi(Kolekcija<Proizvod*> kolekcija)
{
	cout << "PROIZOVID" << endl;

	int unos;
	do
	{
		int rb = 1;
		kolekcija.ForEach([&](Proizvod* g) {
			cout << rb << ". ";
			g->Ispis();
			cout << endl;
		});
		cout << "0. Odustani" << endl;
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos == 0)
			return nullptr;
		if (unos >= 1 && unos <= kolekcija.brojac)
			return kolekcija.podaci[unos];
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}

Faktura* odaberi(Kolekcija<Faktura*> kolekcija)
{
	cout << "FAKTURE" << endl;

	int unos;
	do
	{
		int rb = 1;
		kolekcija.ForEach([&](Faktura* g) {
			cout << rb << ". ";
			g->Ispis();
		});
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos >= 1 && unos <= kolekcija.brojac)
			return kolekcija.podaci[unos];
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}