#pragma once
#include "Kolekcija.h"
#include "Datum.h"
#include "Transakcija.h"

enum VrstaRacuna
{
	TEKUCI,
	DEVIZNI,
	STEDNI
};

struct Racun
{
	VrstaRacuna _vrstaRacuna;
	char _brojRacuna[20];
	Kolekcija transakcije;
	bool _aktivan;
	
	static Racun* Napravi(VrstaRacuna vrsta_racuna, char* broj_racuna);
	void Ispis();
	void Uplata(float iznos, Datum datum);
	void Isplata(float iznos, char* to, Datum datum);
	float Saldo(); //stanje na raèunu: suma uplata minus suma isplata
	Kolekcija GetTransakcijeIznos(float iznos);
	Kolekcija GetTransakcijeByDatum(Datum& datum);
};


Racun* Racun::Napravi(VrstaRacuna vrsta_racuna, char* broj_racuna)
{
	Racun* x = new Racun;
	strcpy_s(x->_brojRacuna, broj_racuna);
	x->_aktivan = true;
	x->_vrstaRacuna = vrsta_racuna;

	return x;
}






