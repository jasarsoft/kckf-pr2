#include <iostream>
using namespace std;

enum Gorivo{Benzin=1, Dizel, Plin, Elektro, Hibrid};
enum MarkaVozila{BMW, Audi, Mercedes, VW};

struct Datum
{
	int _dan, _mjesec_godina;
	void unos(int d, int m, int g);
	void ispis();
};
struct Vozilo
{
	MarkaVozila _markaVozila;
	Gorivo _gorivo;
	Datum _datumRegistracije;
	int _predjeniKilometri;
	char * _registarskaOznaka;

	void unos();
	void unos(MarkaVozila m, Gorivo g, Datum dr, int kilometri, char * regOznaka);
	void ispis();
	void dealociraj();
	void uvecajKilometre(int kilometri);
};
struct Vlasnik
{
	char * _imePrezime;
	Vozilo *_vozila[5];
	const int _max = 5;
	int _trenutno;

	void unos(char *ip);
	void ispis();
	bool dodajVozilo(Vozilo v);
	bool ukloniVozilo(char * registarskaOznaka);
	void dealociraj();
	//vraæa pokazivaè vozilo sa najvise predjenih kilometara od svih vozila
	Vozilo *voziloSaNajviseKilometara();
};


void main()
{

}