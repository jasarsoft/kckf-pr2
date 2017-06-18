#pragma once
#include <memory>

#include "Osoba.h"
#include "Datum.h"
#include "Ispit.h"


struct PrijavaZaIspit
{
	shared_ptr<Osoba> student;
	shared_ptr<Datum> datum_prijave;
	shared_ptr<Datum> datum_odjave;
	int ocjena;
};

void info(shared_ptr<PrijavaZaIspit> p)
{
	cout << "Student: ";
	info(p->student);
	cout << " Datum prijave: ";
	info(p->datum_prijave);
	cout << " Datum odjave: ";
	info(p->datum_odjave);
	cout << endl;
}



