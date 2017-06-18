#include <iostream>
using namespace std;

//Zadatak 1 - Datum

struct Datum
{
	int d;
	int m;
	int g;
};

void info(Datum date)
{
	cout << date.d << "/" << date.m << "/" << date.g << endl;
}

Datum ucitaj_datum()
{
	Datum date;
	cout << "Unesi dan, mjesec, godinu:\n";
	cout << "Dan: "; cin >> date.d;
	cout << "Mjesec: "; cin >> date.m;
	cout << "Godina: "; cin >> date.g;

	return date;
}