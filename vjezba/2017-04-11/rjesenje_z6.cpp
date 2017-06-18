#include <iostream>
using namespace std;


void ispis(double niz[], int b)
{
	for (int i = 0; i<b; i++)
	{
		if (niz[i] > 0)
		{
			cout << "Korijen iz broja " << niz[i] << " je: " << sqrt(niz[i]) << endl;
		}
		else
		{
			cout << "Korijen iz broja " << niz[i] << " je: " << sqrt(-niz[i]) << "i" << endl;
		}
	}
}

void main()
{
	double niz[50];
	int b;
	do
	{
		cout << "Unesite vrijednost koja je manja od 50: ";
		cin >> b;
	} while (b > 50);
	for (int i=0; i < b; i++)
	{
		cout << "Unesite " << i + 1 << ". broj: ";
		cin >> niz[i];
	}

	ispis(niz, b);
}
