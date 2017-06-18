#pragma once
#include "Kolekcija.h"
#include "Proizvod.h"
#include <fstream>


struct StoreApp
{
	int Id=100;
	char Naziv[20];
	Kolekcija<Proizvod*> Proizvodi;
	Kolekcija<Faktura*> Fakture;
	Kolekcija<Grad*> Gradovi;
	Kolekcija<Klijent*> Klijenti;

	void Snimi(ofstream& f)
	{
		f_snimi(f, Id);
		f_snimi(f, Naziv);

		f_snimi(f, Proizvodi.brojac);

		Proizvodi.ForEach([&f](Proizvod* x){
			x->Snimi(f);
		});

		f_snimi(f, Fakture.brojac);
		Fakture.ForEach([&f](Faktura* x) {
			x->Snimi(f);
		});

		f_snimi(f, Gradovi.brojac);
		Gradovi.ForEach([&f](Grad* x) {
			x->Snimi(f);
		});

		f_snimi(f, Klijenti.brojac);
		Klijenti.ForEach([&f](Klijent* x) {
			x->Snimi(f);
		});
	}

	void Ucitaj(ifstream& f)
	{ 
		f_ucitaj(f, Id);
		f_ucitaj(f, Naziv);

		f_ucitaj(f, Proizvodi.brojac);
		Proizvodi.ForEach([&f](Proizvod* &x) {
			x = new Proizvod;
			x->Ucitaj(f);
		});

		f_ucitaj(f, Fakture.brojac);
		Fakture.ForEach([&f](Faktura* &x) {
			x = new Faktura;
			x->Ucitaj(f);
		});

		f_ucitaj(f, Gradovi.brojac);
		Gradovi.ForEach([&f](Grad* &x) {
			x = new Grad;
			x->Ucitaj(f);
		});

		f_ucitaj(f, Klijenti.brojac);
		Klijenti.ForEach([&f](Klijent* &x) {
			x = new Klijent;
			x->Ucitaj(f);
		});
	}

	static StoreApp *Napravi(int Id, char* nazivStore)
	{
		StoreApp *y = new StoreApp;
		y->Id = Id;
		strcpy_s(y->Naziv, nazivStore);
		return y;
	}

};
