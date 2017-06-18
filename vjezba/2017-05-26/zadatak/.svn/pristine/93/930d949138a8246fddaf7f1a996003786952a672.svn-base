#pragma once

#include <iostream>
#include <memory>
#include"Datum.h"
#include "Grad.h"
#include <functional>
#include "StoreApp.h"
#include "Odabiri.h"
using namespace std;

StoreApp* _app = nullptr;
char fileName[100];


//OTVARANJE NOVOG FAJLA
void m_file_open()
{
	if (_app != nullptr)
	{
		//Snimimanje starog storeApp prije otvaranja novog
		ofstream f(fileName, ios::binary);
		_app->Snimi(f);
		f.close();
	}
	
	ifstream f;
	do
	{
		cout << "OTVARANJE NOVOG FAJLA" << endl;
		cout << " Naziv fajla: " << endl;	
		cin.getline(fileName, 100);
		f.open(fileName);
	} while (f.fail());

	_app = new StoreApp;
	_app->Ucitaj(f);
	f.close();
}

//UNOS NOVOG GRADA
void m_grad_add()
{
	if (_app == nullptr)
	{
		cout << "Greška: StoreApp je null";
		return;
	}

	cout << "UNOS NOVOG GRADA" << endl;
	cout << " Naziv: ";
	cin.ignore();
	char naziv[100];
	cin.getline(naziv, 100);

	_app->Gradovi.Dodaj(Grad::Napravi(naziv));
}

//UNOS NOVOG KLIJENTA
void m_klijent_add() 
{
	if (_app == nullptr)
	{
		cout << "Greška: StoreApp je null";
		return;
	}

	cout << "UNOS NOVOG KLIJENTA" << endl;
	cout << " Ime: ";
	cin.ignore();
	char ime[100];
	cin.getline(ime, 100);

	cout << " Prezime: ";
	cin.ignore();
	char prezime[100];
	cin.getline(prezime, 100);

	cout << " Grad: ";
	Grad* grad = odaberi(_app->Gradovi);

	_app->Klijenti.Dodaj(Klijent::Napravi(ime, prezime, *grad));
}

	
//UNOS NOVOG PROIZVODA
void m_proizvod_add() 
{
	if (_app == nullptr)
	{
		cout << "Greška: StoreApp je null";
		return;
	}

	cout << "UNOS NOVOG PROIZVODA" << endl;
	cout << " Naziv: ";
	cin.ignore();
	char naziv[100];
	cin.getline(naziv, 100);

	cout << " Jedinica mjere: ";
	cin.ignore();
	char jmj[10];
	cin.getline(jmj, 10);

	cout << " Cijena: ";
	cin.ignore();
	float cijena;
	cin >> cijena;

	_app->Proizvodi.Dodaj(Proizvod::Napravi(naziv, jmj, cijena));
}

//NOVA PRODAJA
void m_prodaja_add() 
{
	if (_app == nullptr)
	{
		cout << "Greška: StoreApp je null";
		return;
	}

	cout << "PRODAJA - FAKTURA" << endl;
	cout << "Unesite datum (d m g)" << endl;
	int d, m, g;
	cin >> d >> m >> g;
	Datum datum = Datum::Napravi(d, m, g);

	cout << "Odaberite klijenta: " << endl;
	Klijent* klijent = odaberi(_app->Klijenti);

	Faktura* f = Faktura::Napravi(datum, *klijent);
	_app->Fakture.Dodaj(f);

	Proizvod* proizvod;
	do
	{
		proizvod = odaberi(_app->Proizvodi);
		if (proizvod != nullptr)
		{
			cout << "Unesite kolicinu: " << endl;
			int kolicina;
			cin >> kolicina;
			f->_stavke.Dodaj(StavkaFakture::Napravi(*proizvod, kolicina));
		}
	} while (proizvod != nullptr);
}


//SNIMI U FAJL
void m_file_save()
{
	if (_app == nullptr)
	{
		cout << "Greška: StoreApp je null";
		return;
	}
	//Snimimanje starog storeApp prije otvaranja novog
	ofstream f(fileName, ios::binary);
	_app->Snimi(f);
	f.close();
	cout << "Izmjene su snimljene ["<< fileName <<"]"<< endl;
}

//NOVI STORE
void m_store_new()
{
	if (_app != nullptr)
	{
		cout << "Greška: StoreApp nije zatvoren";
		return;
	}
	cout << "Unesite JIB firme (store)" << endl;
	int id;
	cin >> id;

	cout << "Unesite naziv firme" << endl;
	char naziv[100];
	cin.ignore();
	cin.getline(naziv, 100);
	cout << "Unesite naziv fajla" << endl;
	//cin.ignore();
	cin.getline(fileName, 100);
	_app = StoreApp::Napravi(id, naziv);
}



void m_test_app()
{
	StoreApp* appTmp = StoreApp::Napravi(1, "Bingo doo");
	
	appTmp->Gradovi.Dodaj(Grad::Napravi("Mostar"));
	appTmp->Gradovi.Dodaj(Grad::Napravi("Sarajevo"));

	appTmp->Klijenti.Dodaj(Klijent::Napravi("Denis", "Music", *appTmp->Gradovi.Get(0)));
	appTmp->Klijenti.Dodaj(Klijent::Napravi("Adil", "Joldic", *appTmp->Gradovi.Get(1)));

	appTmp->Proizvodi.Dodaj(Proizvod::Napravi("Mlijeko", "L", 1.50));
	appTmp->Proizvodi.Dodaj(Proizvod::Napravi("Jabuke", "KG", 1.30));
	appTmp->Proizvodi.Dodaj(Proizvod::Napravi("Kafa 500 g", "kom", 6.90));

	Faktura* faktura1 = Faktura::Napravi(Datum::Napravi(25, 5, 2017), *appTmp->Klijenti.Get(0));
	Faktura* faktura2 = Faktura::Napravi(Datum::Napravi(26, 5, 2017), *appTmp->Klijenti.Get(1));
	appTmp->Fakture.Dodaj(faktura1);
	appTmp->Fakture.Dodaj(faktura2);

	faktura1->_stavke.Dodaj(StavkaFakture::Napravi(*appTmp->Proizvodi.Get(0), 2));
	faktura1->_stavke.Dodaj(StavkaFakture::Napravi(*appTmp->Proizvodi.Get(1), 2.5));

	faktura2->_stavke.Dodaj(StavkaFakture::Napravi(*appTmp->Proizvodi.Get(0), 3));
	faktura2->_stavke.Dodaj(StavkaFakture::Napravi(*appTmp->Proizvodi.Get(1), 1.5));
	faktura2->_stavke.Dodaj(StavkaFakture::Napravi(*appTmp->Proizvodi.Get(2), 2));

	ofstream f1("m123");
	appTmp->Snimi(f1);
	f1.close();

	StoreApp* s2 = new StoreApp;
	ifstream f2("m123");
	s2->Ucitaj(f2);
	f2.close();

	//cout << "Suma za fakturu 1 " << s2->Fakture.Get(0)->GetIznosSuma() << endl;
	//cout << "Suma za fakturu 2 " << s2->Fakture.Get(1)->GetIznosSuma() << endl;
}