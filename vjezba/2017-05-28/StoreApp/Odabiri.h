#pragma once
#include "Klijent.h"
#include "Proizvod.h"
#include "Faktura.h"
#include "Podaci.h"


Klijent* Klijent_odaberi()
{
	cout << "KLIJENTI" << endl;

	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < KlijentBrojac; ++i)
		{
			cout << rb << ". ";
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

Proizvod* Proizvod_odaberi()
{
	cout << "PROIZVOD" << endl;

	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < ProizvodBrojac; ++i)
		{
			cout << rb << ". ";
			ProizvodNiz[i]->Ispis();
			cout << endl;
		}
		cout << "0. cancel" << endl;
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos == 0)
			return nullptr;
		if (unos >= 1 && unos <= ProizvodBrojac)
			return ProizvodNiz[unos - 1];
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}

Faktura* Faktura_odaberi()
{
	cout << "FAKTURE" << endl;

	int unos;
	do
	{
		int rb = 1;
		for (int i = 0; i < FakturaBrojac; ++i)
		{
			cout << rb << ". ";
			FakturaNiz[i]->Ispis();
			cout << endl;
		}
		cout << "Unesite RB: " << endl;
		cin >> unos;
		if (unos >= 1 && unos <= FakturaBrojac)
			return FakturaNiz[unos - 1];
		cout << " !!Pogrešan unos" << endl;
	} while (true);
}