#include<iostream>
using namespace std;

struct Rezervacija
{
	char * _imePrezime;
	int _brojOsoba;
	double _uplata;
	int _brojRezervacije;

	void unos();
	void ispis();
	void deinicijaliziraj();
	void inicijaliziraj(Rezervacija r);
};

struct Hotel
{
	char *_naziv;
	Rezervacija * _rezervacije;
	int _trenutno;
	int _maksimalno;

	void unos();
	void ispis();
	void deinicijaliziraj();
	void dodajRezervaciju(Rezervacija r);
	Rezervacija * pretraga(int brojRezervacije);
};