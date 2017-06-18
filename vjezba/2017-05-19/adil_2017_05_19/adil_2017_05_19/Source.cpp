#include <iostream>
using namespace std;
#include "Datum.h"
#include "Osoba.h"
#include "Ispit.h"

void main()
{
	const int max_ispiti = 10;
	Ispit ispiti[max_ispiti];
	int brojac_ispita = 0;
	int x;
	do
	{
		cout << "1. Ispiti - prikazi sve" << endl;
		cout << "2. Ispiti - dodaj novi (zakazi novi ispit)" << endl;
		cout << "3. Prijavljeni za ispit: prikazi sve (za ispit x)" << endl;
		cout << "4. Prijavljeni za ispit: dodaj novu prijavu (za ispit x)" << endl;
		cout << "5. Evidentiraj sve ocjene (za ispit x)" << endl;
		cout << "0. EXIT" << endl;
		cin >> x;
		if (x == 1)
		{
			prikazi_ispite(ispiti, brojac_ispita);
		}
		if (x == 2)
		{
			Ispit i = ucitaj_ispit();
			ispiti[brojac_ispita] = i;
			brojac_ispita++;
		}
		if (x == 3)
		{
			Ispit i = odaberite_ispit(ispiti, brojac_ispita);
			for (int j = 0; j<i.brojac_prijavljenih; j++)
			{
				PrijavaZaIspit& p = i.prijave[j];
				info(p);
			}
		}
		if (x == 4)
		{
			Ispit& i = odaberite_ispit(ispiti, brojac_ispita);
			PrijavaZaIspit novaP;
			novaP.student = odaberite_osobu(studenti, max_s);
			novaP.datum_prijave = ucitaj_datum();
			i.prijave[i.brojac_prijavljenih++] = novaP;
		}
		if (x == 5)
		{
			Ispit& i = odaberite_ispit(ispiti, brojac_ispita);
			for (int j = 0; j<i.brojac_prijavljenih; j++)
			{
				info(i.prijave[j].student);
				cout << ", Unesite ocjenu sa ispita: ";
				cin >> i.prijave[j].ocjena;
			}
		}
	} while (x != 0);
}
