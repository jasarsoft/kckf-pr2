#include <iostream>
using namespace std;

const int max_s = 5;
const int max_i = 5;

struct Osoba
{
	int id;
	char ime[20];
};

struct Datum
{
	int d;
	int m;
	int g;
};


Osoba studenti[max_s] = 
{
	{0, "ime0"},
	{1, "ime1"},
	{2, "ime2"},
	{3, "ime3"},
	{4, "ime4"}
};

Osoba ispitivaci[max_i] = 
{
	{534, "Nina B."},
	{435, "Jasmin A."},
	{256, "Denis M."},
	{325, "Emina J."},
	{914, "Zanin V."}
};

struct Ispit
{
	Osoba ispitivac;
	Datum datum_ispita;
	char predmet[10];
};


void info(Osoba o);
void info(Datum date);
Datum ucitaj_datum();
Osoba odaberi_osobu();
Osoba odaberite_osobu(Osoba osobe[], int v);

//main entry point
void main()
{
	Datum d1, d2, d3;

	d1 = ucitaj_datum();
	d2 = ucitaj_datum();
	d3 = ucitaj_datum();

	info(d1);
	info(d2);
	info(d3);

	info(odaberi_osobu());

	Ispit p1 =
	{
		ispitivaci[0],
		ucitaj_datum(),
		"Predmet 1"
	};

	A:Ispit p2 =
	{
		ispitivaci[1],
		ucitaj_datum(),
		"Predmet 2"
	};

	  goto A;

	int brojac;
	Ispit ispiti[2];


}

void info(Datum date)
{
	cout << "Dan: " << date.d << endl;
	cout << "Mjesec: " << date.m << endl;
	cout << "Godina: " << date.g << endl;
}

void info(Osoba o)
{
	cout << "Id: " << o.id << endl;
	cout << "Ime: " << o.ime << endl;
}

Datum ucitaj_datum()
{
	Datum date;
	cout << "Unesite dan: "; cin >> date.d;
	cout << "Unesite mjesec: "; cin >> date.m;
	cout << "Unesite godinu: "; cin >> date.g;

	return date;
}

Osoba odaberi_osobu()
{
	cout << "Spisak osoba:\n";
	for (int i = 0; i < max_s; i++)
	{
		cout << i + 1 << ". " << studenti[i].ime << " ID: " << studenti[i].id << endl;
	}

	int rb;
	
	do
	{
		cout << "Unesite redni broj: ";
		cin >> rb;
		rb -= 1;
	} while (rb > max_s || rb < 0);

	return studenti[rb];
}

Osoba odaberite_osobu(Osoba osobe[], int v)
{
	cout << "Spisak osoba:\n";
	for (int i = 0; i < v; i++)
	{
		cout << i + 1 << ". " << osobe[i].ime << " ID: " << osobe[i].id << endl;
	}

	int rb;
	
	do
	{
		cout << "Unesite redni broj: "; cin >> rb;
		rb -= 1;
	} while (rb > max_s || rb < 0);

	return osobe[rb];
}