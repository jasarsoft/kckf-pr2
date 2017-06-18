#pragma once

#include <iostream>
using namespace std;

#include "Datum.h"


enum VrstaTransakcije { UPLATA, ISPLATA };
char *vrstaTransakcije[] = { "UPLATA", "ISPLATA" };

struct Transakcija
{
	Datum _datumTransakcije;
	char _TO[20];
	float _iznos;
	bool _aktivna;
	VrstaTransakcije _vrstaTransakcije; /* ako je isplata vrijednost _TO postaviti na brojRacuna sa koga se transakcija vrsi*/	
	
	
										/*u slucaju da se transakcija izbrise ona postaje neaktivna, ali je bitno da o njoj ostane zapis*/
	void Ispis();
	static Transakcija NapraviUplatu(float iznos, const Datum& datum);
	static Transakcija NapraviIsplatu(float iznos, char* to, Datum& datum);
};