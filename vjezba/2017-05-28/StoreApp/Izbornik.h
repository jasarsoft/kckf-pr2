#pragma once

#include <iostream>
#include <memory>
#include"Datum.h"
#include "Podaci.h"
#include "Odabiri.h"
#include "stavkafakture.h"
#include "Faktura.h"
using namespace std;

void m_pretraga()
{
	cout << "TRAZI PO IMENU KLIJENTA" << endl;
	cout << " Ime: ";
	char trazi[100];
	cin.ignore();
	cin.getline(trazi, 100);

	int b = 0;
	cout << "Pronadjeno: " << endl;
	for (int i = 0; i < KlijentBrojac; ++i)
	{
		Klijent* k = KlijentNiz[i];
		if (strcmp(k->_ime, trazi) == 0 || strcmp(k->_prezime, trazi) == 0)
		{
			cout << b << ". ";
			k->Ispis();
			b++;
		}
	}
	cout << "ukupno: " << b<< endl;
}



//UNOS NOVOG KLIJENTA
void m_klijent_add() 
{
	cout << "UNOS NOVOG KLIJENTA" << endl;
	cout << " Ime: ";
	cin.ignore();
	char ime[100];
	cin.getline(ime, 100);

	cout << " Prezime: ";
	cin.ignore();
	char prezime[100];
	cin.getline(prezime, 100);
	KlijentDodaj(Klijent_Napravi(ime, prezime));
}

	
//UNOS NOVOG PROIZVODA
void m_proizvod_add() 
{
	cout << "UNOS NOVOG PROIZVODA" << endl;
	cout << " Naziv: ";
	cin.ignore();
	char naziv[100];
	cin.getline(naziv, 100);

	cout << " Jedinica mjere: ";
	char jmj[10];
	cin.getline(jmj, 10);

	cout << " Cijena: ";	
	float cijena;
	cin >> cijena;
	ProizvodDodaj(Proizvod_Napravi(naziv, jmj, cijena));
}

//NOVA PRODAJA
void m_prodaja_add() 
{
	cout << "PRODAJA - FAKTURA" << endl;
	cout << "Unesite datum (d m g)" << endl;
	int d, m, g;
	cin >> d >> m >> g;
	Datum datum = Datum::Napravi(d, m, g);

	cout << "Odaberite klijenta: " << endl;
	Klijent* klijent = Klijent_odaberi();

	Faktura* f = Faktura_Napravi(datum, klijent);
	FakturaDodaj(f);

	Proizvod* proizvod;
	do
	{
		proizvod = Proizvod_odaberi();
		if (proizvod != nullptr)
		{
			cout << "Unesite kolicinu: " << endl;
			int kolicina;
			cin >> kolicina;
			f->_stavke.Dodaj(Stavka_Napravi(proizvod, kolicina));
		}
	} while (proizvod != nullptr);
}



void m_test_app()
{
	KlijentDodaj(Klijent_Napravi("Denis", "Music"));
	KlijentDodaj(Klijent_Napravi("Adil", "Joldic"));

	ProizvodDodaj(Proizvod_Napravi("Mlijeko", "L", 1.50));
	ProizvodDodaj(Proizvod_Napravi("Jabuke", "KG", 1.30));
	ProizvodDodaj(Proizvod_Napravi("Kafa 500 g", "kom", 6.90));

	Faktura* faktura1 = Faktura_Napravi(Datum::Napravi(25, 5, 2017), KlijentNiz[0]);
	Faktura* faktura2 = Faktura_Napravi(Datum::Napravi(26, 5, 2017), KlijentNiz[1]);
	FakturaDodaj(faktura1);
	FakturaDodaj(faktura2);

	faktura1->_stavke.Dodaj(Stavka_Napravi(ProizvodNiz[0], 2));
	faktura1->_stavke.Dodaj(Stavka_Napravi(ProizvodNiz[1], 2.5));

	faktura2->_stavke.Dodaj(Stavka_Napravi(ProizvodNiz[0], 3));
	faktura2->_stavke.Dodaj(Stavka_Napravi(ProizvodNiz[1], 1.5));
	faktura2->_stavke.Dodaj(Stavka_Napravi(ProizvodNiz[2], 2));


	cout << "Suma za fakturu 1 " << FakturaNiz[0]->GetIznosSuma() << endl;
	cout << "Suma za fakturu 2 " << FakturaNiz[1]->GetIznosSuma() << endl;
}

