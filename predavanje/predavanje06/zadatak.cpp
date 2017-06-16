#include <iostream>
using namespace std;

struct Datum
{
	int *_dan,
		*_mjesec,
		*_godina;

	void unos()
	{
		_dan = new int;
		_mjesec = new int;
		_godina = new int;
		cout << "Datum (dd/mm/gggg): ";
		cin >> *_dan >> *_mjesec >> *_godina;
	}
	void ispis()
	{
		cout << *_dan << "/" << *_mjesec << "/" << *_godina << endl;
	}
	void dealociraj()
	{
		delete _dan; _dan = nullptr;
		delete _mjesec; _mjesec = nullptr;
		delete _godina; _godina = nullptr;
	}
};
struct Autor
{
	char * _ime,
		*_prezime,
		*_mjestoRodjenja;
	Datum _datumRodjenja;

	void unos()
	{
		char temp[1000];
		int vel;

		cout << "Uensite datum rodjenja: ";
		_datumRodjenja.unos();

		cin.ignore();

		cout << "Unesite ime: ";
		cin.getline(temp, 1000);
		vel = strlen(temp) + 1;
		_ime = new char[vel];
		strcpy_s(_ime, vel, temp);

		cout << "Unesite prezime: ";
		cin.getline(temp, 1000);
		vel = strlen(temp) + 1;
		_prezime = new char[vel];
		strcpy_s(_prezime, vel, temp);

		cout << "Unesite mjesto rodjenja: ";
		cin.getline(temp, 1000);
		vel = strlen(temp) + 1;
		_mjestoRodjenja = new char[vel];
		strcpy_s(_mjestoRodjenja, vel, temp);


	}
	void ispis()
	{
		cout << "Ime i prezime: " << _ime << " " << _prezime << endl;
		cout << "Mjesto rodjenja: " << _mjestoRodjenja << endl;
		cout << "Datum rodjenja: ";
		_datumRodjenja.ispis();
	}
	void dealociraj()
	{
		_datumRodjenja.dealociraj();
		delete[]_ime, _ime = nullptr;
		delete[]_prezime; _prezime = nullptr;
		delete[]_mjestoRodjenja; _mjestoRodjenja = nullptr;
	}
};

void main()
{
	Autor autor;

	autor.unos();
	system("cls");
	autor.ispis();
	autor.dealociraj();
}