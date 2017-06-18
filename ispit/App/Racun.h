#pragma once
#pragma once

#include <iostream>
#include "Transakcija.h"
#include "TransakcijaKolekcija.h"
using namespace std;

struct Racun
{
	char _brojRacuna[20];
	TransakcijaKolekcija transakcije;

	void Ispis()
	{
		cout << "Broj raèuna: " << _brojRacuna << endl;
		cout << "Broj transakcija: " << transakcije.brojac << endl;
	}


	float Saldo()
	{
		float s = 0;
		// ...
		return s;
	}
};


Racun* Racun_Napravi(char* broj_racuna)
{

}