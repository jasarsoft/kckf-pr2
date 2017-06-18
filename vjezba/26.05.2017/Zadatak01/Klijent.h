#pragma once
#include "Racun.h"

struct  Klijent
{
	int maxR = 10;
	char _JMBG[14];
	char* _imePrezime;
	Racun** _racuni = new Racun*[maxR];
	int _treuntnoRacuna;
	bool _aktivan;

	static Klijent* Napravi(char* jmbg, char* imePrezime);
	void Ispis();
	void Delociranje();
	void DodajRacun(VrstaRacuna vrstaRacuna, char* brojRacuna);
	void DodajUplatu(int indexRacuna, float iznos, Datum datum);
	void DodajIsplatu(int indexRacuna, float iznos, char* to, Datum datum);
	Kolekcija GetTransakcijeByIznos(float iznos);// vraca Kolekciju transakcija koje su imale iznos veci od trazenog
	Kolekcija GetTransakcijeByDatum(Datum datum);// vraca transakcija koje su obavljene za trazeni datum
	void Deaktiviraj();
};