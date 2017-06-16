#include <iostream>
using namespace std;

struct DatumVrijeme
{
	int _dan;
	int _mjesec;
	int _godina;
	int _sati;
	int _minute;

	void unos(int dan, int mjesec, int godina, int sati, int minute);
	//23/1/2017 19:43
	void ispis();
};

struct Korisnik
{
	char *_korinsickoIme;
	int _godinaRodjenja;

	void unos(char * ki, int gr);
	void ispis();
	void dealociraj();
};

struct Komentar
{
	char * _komentar;
	DatumVrijeme _vrijemeKomentara;
	Korisnik _korisnik;

	void unos(char * komentar, DatumVrijeme vrijeme, Korisnik k);
	//vrijeme - komentar
	void ispis();
	void dealociraj();
};

struct Objava
{
	char * _tekst;
	DatumVrijeme _vrijemeObjave;
	Korisnik _korisnik;
	Komentar * _komentari;//komentari na objavu
	int _ternutnoKomentara;

	void unos(char * tekst, DatumVrijeme vrijemeObjave);
	void ispis();
	void dealociraj();
	bool dodajKomentar(char * komentar, DatumVrijeme vrijemeKomentara, Korisnik k);
	//uklanja komentar na osnovu vremena kada je isti dodan
	bool ukloniKomentar(DatumVrijeme vrijemeKomentara);
};

Korisnik * najaktivnijeObjave(Objava * objave, int max, int brojKomentara)
{
	//funkcija vraca sve objave koje budu imale više komentara od broja
	//koji je proslijeden kao parametar
}


void main()
{
	//kreirati 4 korisnika
	//kreirati niz od 3 objave
	//dodati proizvoljan broj komentara za razlicite
	//korisnike na razlicitim objavama

	//testirati funkciju najaktivnijeObjave
}