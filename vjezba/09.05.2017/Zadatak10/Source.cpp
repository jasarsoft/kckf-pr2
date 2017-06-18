#include <iostream>
using namespace std;

void ucitaj(int*, int v);
void ispis(int*, int v);
void saberi(int*, int*, int*, int v);

void main()
{
	int x;
	cout << "Unesite velicinu: ";
	cin >> x;

	int* A = new int[x];
	int* B = new int[x];

	ucitaj(A, x);
	ucitaj(B, x);

	int* C = new int[x];
	saberi(A, B, C, x);
	ispis(C, x);

	system("pause");
}

void ucitaj(int* niz, int v)
{
	for (int i = 0; i < v; i++)
	{
		cin >> *(niz + i);
	}
}

void ispis(int* niz, int v)
{
	for (int i = 0; i < v; i++)
	{
		cout << *(niz + i);
	}
}

void saberi(int* niz1, int* niz2, int* niz3, int v)
{
	for (int i = 0; i < v; i++)
	{
		*(niz3 + i) = *(niz1 + i) + *(niz2 + i);
	}
}