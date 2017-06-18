#pragma once
#include <iostream>
using namespace std;

struct Osoba 
{
	int id;
	char ime[15];
};
const int max_i = 5;
Osoba ispitivaci[max_i] = {
	{ 534, "Nina B." },
	{ 435, "Jasmin A." },
	{ 256, "Denis M." },
	{ 325, "Emina J." },
	{ 914, "Zanin V." },
};

// Studenti
const int max_s = 5;
Osoba studenti[max_s] = {
	{ 1, "Marko" },
	{ 2, "Darko" },
	{ 3, "Zarko" },
	{ 4, "Adil" },
	{ 5, "Faruk" }
};

void info(Osoba o) {
	cout << "Ime osobe je: " << o.ime << " id= " << o.id <<" ";
}

Osoba odaberite_osobu(Osoba *osobe, int velicina)
{

	for (int i = 0; i < velicina; i++)
	{
		cout << i + 1 << ". osoba: " << "Id:" << osobe[i].id << "Ime: " << osobe[i].ime << endl;

	}
	int rb;
	do {
		cout << "Unesite ID osobe ";
		cin >> rb;
	
		for (size_t i = 0; i < velicina; i++)
		{
			if (rb == osobe[i].id)
				return osobe[rb];
		}
		cout << "Neispravan unos..." << endl;
	} while (true);

}



