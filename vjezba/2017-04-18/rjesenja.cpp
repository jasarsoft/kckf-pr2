#include <iostream>
using namespace  std;

// stuktura Datum
struct Datum {
	int d;
	int m;
	int g;
};


void info(Datum date) {
	// dd/mm/gg
	cout << date.d << "/" << date.m << "/" << date.g << endl;
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

// struktura Osoba
struct Osoba {
	int id;
	char ime[15];
};
void info(Osoba o) {
	cout << "Ime osobe je: " << o.ime << " id= " << o.id << endl;
}

// Studenti
const int max_s = 5;
Osoba studenti[max_s] = {
	{1, "Marko"},
	{2, "Darko"},
	{3, "Zarko"},
	{4, "Adil"},
	{5, "Faruk"}
};

Osoba odaberite_osobu(Osoba niz[],int z)
{
	int a;
	cout << "Spisak osoba: " << endl;
	for (int i = 0; i < z; i++)
	{
		cout << i  << "Ime osobe: " << niz[i].ime <<", ID: "<< niz[i].id << endl;
	}

	cout << "Unesite RB: ";
	cin >> a;
	Osoba x = niz[a];
	return x;
}
const int max_i = 5;
Osoba ispitivaci[max_i] = {
	{ 534, "Nina B."  },
	{  435, "Jasmin A." },
	{  256, "Denis M." },
	{  325, "Emina J." },
	{  914, "Zanin V."  },
};

struct Ispit {

	Osoba ispitivac;
	Datum datum_ispita;
	char predmet[10];
};
Ispit pripremi_ispit()
{
	Ispit x;
	cout << "Unesite predmet " << endl;
	cin >> x.predmet;

	cout << "Odaberite ispitivaca" << endl;
	x.ispitivac = odaberite_osobu(ispitivaci, max_i);

	cout << "Unesite datum ispita" << endl;
	x.datum_ispita = ucitaj_datum();
	return x;
}

void prikazi_ispite(Ispit ispiti[], int max) {
	for (int i = 0; i < max; i++)
	{
		info(ispiti[i].datum_ispita);
		info(ispiti[i].ispitivac);
		cout << "Predmet -> " << ispiti[i].predmet << endl;
	}
}
void main()
{  
	Datum d1, d2, d3;
	d1 = ucitaj_datum();
	d2 = ucitaj_datum();
	d3 = ucitaj_datum();
	info(d1);
	info(d2);
	info(d3);
	Osoba s1 = odaberite_osobu(studenti,max_s);
	info(s1);

	Ispit p1 = pripremi_ispit();
	Ispit p2 = pripremi_ispit();

	int _brojac_ispita = 0;
	const int max_ispita = 30;
	int temp;
	
	Ispit ispiti[max_ispita];
	ispiti[_brojac_ispita++] = pripremi_ispit();
	ispiti[_brojac_ispita++] = pripremi_ispit();
	ispiti[_brojac_ispita++] = pripremi_ispit();
	ispiti[_brojac_ispita++] = pripremi_ispit();

}
