#pragma once
#include <iostream>
#include <memory>
using namespace std;

struct Osoba 
{
	int id;
	char ime[15];
};

shared_ptr<Osoba> build(int id, char* ime) {
	shared_ptr<Osoba> x (new Osoba);
	x->id = id;
	strcpy_s(x->ime, ime);
	return x;
}
const int max_i = 5;
shared_ptr<Osoba> ispitivaci[max_i] = {
	build( 534, "Nina B." ),
	build( 435, "Jasmin A."),
	build( 256, "Denis M." ),
	build( 325, "Emina J." ),
	build( 914, "Zanin V." ),
};



// Studenti
const int max_s = 5;
shared_ptr<Osoba> studenti[max_s] = {
	build( 1, "Marko" ),
	build( 2, "Darko" ),
	build( 3, "Zarko" ),
	build( 4, "Adil" ),
	build( 5, "Faruk" )
};

void info(shared_ptr<Osoba> o) {
	cout << "Ime osobe je: " << o->ime << " id= " << o->id <<" ";
}

shared_ptr<Osoba> odaberite_osobu(shared_ptr<Osoba> osobe[], int velicina)
{

	for (int i = 0; i < velicina; i++)
	{
		cout << i + 1 << ". osoba: " << "Id:" << osobe[i]->id << "Ime: " << osobe[i]->ime << endl;

	}
	int rb;
	do {
		cout << "Unesite ID osobe ";
		cin >> rb;
	
		for (size_t i = 0; i < velicina; i++)
		{
			if (rb == osobe[i]->id)
				//return &osobe[i];
				return osobe[i];
		}
		cout << "Neispravan unos..." << endl;
	} while (true);

}



