#include <iostream>
using namespace std;

void main(void)
{
	int x;

	do
	{
		cout << "Unesite x: "; cin >> x;

		if (x > 20) cout << "Broj mora biti manji od 20!\n";
		if (x <= 0) cout << "Broj mora biti veci od 0!\n";
	} while (x > 20 || x <= 0);

	int max = 0;
	int *niz = new int[x];

	for (int i = 0; i < x; i++)
	{
		cout << "Element [" << i << "]: "; cin >> niz[i];
		if (max < niz[i]) max = niz[i];
	}

	for (int i = x - 1; i >= 0; i--) cout << "Ispis [" << i << "]: " << niz[i];
	cout << "Maksimalni broj: " << max << endl;
}