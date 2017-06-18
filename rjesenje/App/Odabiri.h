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
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}

Racun* Racun_odaberi(Klijent* k)
{
	cout << "Racuni" << endl;
	
	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < k->racuni.brojac; i++)
		{
			cout << rb++ << ". ";
			k->racuni.Get(i)->Ispis();
			cout << endl;
		}
		cout << "Unesite RB: "; 
		cin >> unos;
		if (unos >= 1 && unos <= k->racuni.brojac) 
			return k->racuni.Get(unos - 1);
		cout << " !!Pogresan unos!!\n";
	} while (true);
}

Transakcija* Transakcija_odaberi(Racun* r)
{
	cout << "Transakcije" << endl;

	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < r->transakcije.brojac; i++)
		{
			cout << rb++ << ". ";
			r->transakcije.Get(i)->Ispis();
			cout << endl;
		}
		cout << "Unesite RB: ";
		cin >> unos;
		if (unos >= 1 && unos <= r->transakcije.brojac)
			return r->transakcije.Get(unos - 1);
		cout << " !!Pogresan unos!!\n";
	} while (true);
}


