#include <iostream>
using namespace std;

enum tipKorisnika
{
	Admin = 1,
	Menadzer ,
	Prodavac 
};

struct Korisnik
{
	char ime[10];
	tipKorisnika tip;
};

void main()
{
	Korisnik k1;
	strcpy_s(k1.ime, "Adil");
	k1.tip = Menadzer;
	
	Korisnik k2;
	cout << "Ime";
	cin.getline(k2.ime, 10);
	cout << "1. Admin"<<endl;
	cout << "2. Menadzer" << endl;
	cout << "3. Prodavac" << endl;
	int u;
	cin >> u;
	k2.tip = (tipKorisnika)u;
}
