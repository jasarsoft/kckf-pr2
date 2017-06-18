#pragma once
#pragma once
#include <iostream>
#include <memory>
#include"Transakcija.h"
#include "Klijent.h"
#include "Racun.h"

using namespace std;

typedef Racun* RacunTip;

struct RacunKolekcija
{
	int max_size = 30;
	RacunTip* podaci = new RacunTip[max_size];
	int brojac = 0;

	RacunTip& Get(int i)
	{
		
	}
	void Dodaj(RacunTip newV)
	{
		
	}
};

