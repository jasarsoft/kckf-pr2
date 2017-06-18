#pragma once
#include "Osoba.h"
#include "Datum.h"
#include "Ispit.h"


struct PrijavaZaIspit
{
	Osoba student;
	Datum datum_prijave;
	Datum datum_odjave;
	int ocjena;
};

void info(PrijavaZaIspit p)
{
	cout << "Student: ";
	info(p.student);
	cout << " Datum prijave: ";
	info(p.datum_prijave);
	cout << " Datum odjave: ";
	info(p.datum_odjave);
	cout << endl;
}


//const int max_p = 100;
//
//struct Ispit
//{
//	Osoba ispitivac;
//	Datum datum_ispita;
//	char predmet[10];
//
//	int brojac_prijavljenih;
//	PrijavaZaIspit prijave[max_p];
//};
