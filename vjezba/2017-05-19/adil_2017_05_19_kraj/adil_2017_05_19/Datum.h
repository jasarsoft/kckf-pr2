#pragma once

#include <iostream>
#include <memory>
using namespace std;
// stuktura Datum

struct Datum {
	int d;
	int m;
	int g;
};


void info(shared_ptr<Datum> date) {
	// dd/mm/gg
	cout << date->d << "/" << (*date).m << "/" << (*date).g <<". ";
}

shared_ptr<Datum> ucitaj_datum()
{
	shared_ptr<Datum> x (new Datum);
	cout << "unesite dan, mjesec i godinu: ";
	cin >> x->d;
	cin >> x->m;
	cin >> x->g;
	return x;
}
