#include <iostream>

using namespace std;

void main(void)
{
	float sum = 0.0;
	int niz[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Unesite vrijednost niza[" << i << "]: "; cin >> niz[i];
		sum = sum + niz[i];
	}

	for (int i = 0; i < 5; i++)
	{
		cout << "niz[" << i << "]: " << niz[i] << endl;
	}

	int sum;
	

	cout << "Arimeticka sredina: " << sum / 5.0 << endl;
}