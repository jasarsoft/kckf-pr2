#include<iostream>
using namespace std;

struct Datum
{
	int _dan;
	int _mjesec;
	int _godina;
};

struct Kosarkas
{
	char _ime[20];
	char _prezime[30];
	float _visina;//vrijednost u metrima
	Datum _datumRodjenja;
	int _brojDresa;
	bool _desnjak;//samo da koristim što manji nizova
	//karaktera jer nismo radili funkcije za manipulaciju
	//nizovima karaktera
	int _brojPoena[5];
};

void unos(Datum & d);
void unos(Kosarkas & k);
void ispis(Datum d);
void ispis(Kosarkas k);


void main()
{
	int niz[10];
	Kosarkas tim[20];
	//Datum datum1 = {12,12,2016};
	//Kosarkas k1 = {"Amer","Vrebac",1.87, datum1,10,true};
	Kosarkas k,k2;
	unos(k);
	//unos(k2);
	system("cls");
	ispis(k);
	cout << "==================================\n";
	//ispis(k2);
}

void unos(Datum & d)
{
	cout << "Unesite datum (dd/mm/gggg): ";
	cin >> d._dan >> d._mjesec >> d._godina;
}
void unos(Kosarkas & k)
{
	strcpy_s(k._ime, "Amer");
	strcpy_s(k._prezime, "Vrebac");
	cout << "Unesite visinu(metri): ";
	cin >> k._visina;
	unos(k._datumRodjenja);
	cout << "Unesite broj dresa: ";
	cin >> k._brojDresa;
	int izbor;
	cout << "1. desnjak\n2. ljevak: ";
	cin >> izbor;
	if (izbor == 1)
		k._desnjak = true;
	else
		k._desnjak = false;
	for (int i = 0; i < 5; i++)
	{
		cout << "Unesite poene na " << i + 1 << ". utakmici: ";
		cin >> k._brojPoena[i];
	}

}
void ispis(Datum d)
{
	cout << d._dan << "/" << d._mjesec << "/" << d._godina << endl;
}
void ispis(Kosarkas k)
{
	cout << "Ime i prezime: " << k._ime << " " << k._prezime << endl;
	cout << "Visina: " << k._visina << endl;
	ispis(k._datumRodjenja);
	cout << "Dres: " << k._brojDresa << endl;
	if (k._desnjak == true)
		cout << "Ruka: desna" << endl;
	else
		cout << "Ruka:  lijeva" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Utakmica "<<i+1<<": "<<k._brojPoena[i]<<endl;
	}
}
