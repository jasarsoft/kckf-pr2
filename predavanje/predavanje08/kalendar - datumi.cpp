#include<iostream>
using namespace std;

struct Datum
{
	int *_dan,
		*_mjesec,
		*_godina;

	void unos();
	void ispis();
	void dealociraj();
};

struct Napomena
{
	char * _opis;
	Datum _datumNapomene;

	void unos();
	void ispis();
	void dealociraj();
};

struct Kalendar
{
	Napomena * _napomene;
	int _trenutno;
	int _max;

	void unos();
	void pregledNapomena();
	void dealociraj();
	//nije moguće dodati dvije napomene za isti datum
	bool dodajNapomenu();
	bool ukloniNapomenu();
};