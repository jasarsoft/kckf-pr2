#pragma once
#include <iostream>
#include <memory>
#include"Transakcija.h"

using namespace std;

typedef Transakcija* TransakcijaTip;

struct TransakcijaKolekcija
{
	int max_size = 30;
	TransakcijaTip* podaci=new TransakcijaTip[max_size];
	int brojac = 0;
	TransakcijaTip& Get(int i)
	{
		
	}
	void Dodaj(TransakcijaTip newV)
	{
	
	}
};

