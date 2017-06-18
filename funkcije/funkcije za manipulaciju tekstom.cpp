#include <iostream>
using namespace std;

void main()
{
	char ime[100];
	char prezime[100];
	char * pokIme;
	//funkcija za unos teksta
	cin.getline(ime, 100);
	cin.getline(prezime, 100);
	//funkcija koja broj unesenih karaktera
	int size = strlen(ime)+1;

	pokIme = new char[50];
	//funkcija za kopiranje
	//		gdje	velicna		šta
	strcpy_s(pokIme,	50,	ime);
	strncpy_s(pokIme,	50,	ime,	4);

	//funkcaij koja dodaje tekst na prethodnu vrijednost
	strcat_s(pokIme, 50, " ");
	strcat_s(pokIme, 50, prezime);

	//funkcija koja poredi dva stringa i ukoliko su
	//identièni vraæa vrijednost 0
	if (strcmp(pokIme, ime) == 0)
		cout << "isto ime." << endl;
	else
		cout << "razlicito ime." << endl;

	cout << pokIme << endl;
	delete[]pokIme;
	pokIme = nullptr;
}

