#include<iostream>
using namespace std;

void unos(int[], int);
void unos(char[], int);
void ispis(int[], int);
void ispis(char[], int);
void udvostruci(int[], int);
int suma(int[], int);
float prosjek(int[], int);

void main()
{
	const int vel = 5;
	int niz[vel];
	unos(niz, vel);
	cout << "Prije udvostrucenja: ";
	ispis(niz, vel);
	udvostruci(niz, vel);
	cout << "Nakon udvostrucenja: ";
	ispis(niz, vel);
}

void unos(int nizElemenata[], int brojElemenata)
{
	for (int i = 0; i < brojElemenata; i++)
	{
		cout << "Unesite " << i + 1 << " element: ";
		cin >> nizElemenata[i];
	}
}
void unos(char nizElemenata[], int brojElemenata)
{
	for (int i = 0; i < brojElemenata; i++)
	{
		cout << "Unesite " << i + 1 << " element: ";
		cin >> nizElemenata[i];
	}
}
void ispis(int niz[], int vel)
{
	for (int i = 0; i < vel; i++)
		cout << niz[i] <<" |";
	cout << endl;
}
void ispis(char niz[], int vel)
{
	for (int i = 0; i < vel; i++)
		cout << niz[i] << " |";
	cout << endl;
}
void udvostruci(int niz[], int velicina)
{
	for (int i = 0; i < velicina; i++)
		niz[i] = niz[i] * 2;
}
int suma(int niz[], int vel)
{
	int suma = 0;
	for (int i = 0; i < vel; i++)
		suma = suma + niz[i];
	return suma;
}
float prosjek(int niz[], int vel)
{
	return suma(niz, vel) / (float)vel;
}