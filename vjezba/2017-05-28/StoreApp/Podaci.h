#pragma once
#include "Klijent.h"
#include "Faktura.h"

const int ProizvodMax = 20;
const int KlijentMax = 20;
const int FakturaMax = 20;

Proizvod* ProizvodNiz[ProizvodMax];
Klijent* KlijentNiz[KlijentMax];
Faktura* FakturaNiz[FakturaMax];

int ProizvodBrojac = 0;
int KlijentBrojac = 0;
int FakturaBrojac = 0;


void ProizvodDodaj(Proizvod* p)
{
	ProizvodNiz[ProizvodBrojac] = p;
	ProizvodBrojac++;
}

void KlijentDodaj(Klijent* p)
{
	KlijentNiz[KlijentBrojac] = p;
	KlijentBrojac++;
}

void FakturaDodaj(Faktura* p)
{
	FakturaNiz[FakturaBrojac] = p;
	FakturaBrojac++;
}