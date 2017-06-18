#include <iostream>
using namespace std;

void ucitaj(int*, int v);
void ispis(int*, int v);

void main()
{
	const int v = 10;

	int N[v];

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
		cout << *(niz + i)
	}
}