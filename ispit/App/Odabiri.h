#pragma once
#include "Klijent.h"
#include "Podaci.h"
#include "Racun.h"


Klijent* Klijent_odaberi()
{
	cout << "KLIJENTI" << endl;

	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < KlijentBrojac; ++i)
		{
			cout << rb++ << ". ";
			KlijentNiz[i]->Ispis();
			cout << endl;
		}
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos >= 1 && unos <= KlijentBrojac)
			return KlijentNiz[unos-1];
		cout << " !!Pogre�an unos" << endl;
	} while (true);
}

Racun* Proizvod_odaberi(Klijent* k)
{
	cout << "Racuni" << endl;

	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < k->racuni.brojac; ++i)
		{
			cout << rb++ << ". ";
			k->racuni.Get(i)->Ispis();
			cout << endl;
		}
		cout << "0. cancel" << endl;
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos >= 1 && unos <= k->racuni.brojac)
			return k->racuni.Get(unos-1);
		cout << " !!Pogre�an unos" << endl;
	} while (true);
}

