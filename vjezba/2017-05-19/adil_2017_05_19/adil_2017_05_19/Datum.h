#pragma once

#include <iostream>
using namespace std;
// stuktura Datum

struct Datum {
	int d;
	int m;
	int g;
};


void info(Datum date) {
	// dd/mm/gg
	cout << date.d << "/" << date.m << "/" << date.g <<". ";
}

Datum ucitaj_datum()
{
	Datum x;
	cout << "unesite dan, mjesec i godinu: ";
	cin >> x.d;
	cin >> x.m;
	cin >> x.g;
	return x;
}
