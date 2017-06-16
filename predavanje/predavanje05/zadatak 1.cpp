#include <iostream>
using namespace std;

int unos(float *, int);
void ispis(float *, int);
bool inicijaliziraj(float*, float*, int);

void main()
{
	float *niz1;
	int vel1;
	do
	{
		cout << "Unesite velicinu niza (min 1): ";
		cin >> vel1;
	} while (vel1<1);
	
	niz1 = new float[vel1];
	int vel2 = unos(niz1, vel1);
	
	float * niz2 = new float[vel2];
	if (inicijaliziraj(niz1, niz2, vel1) == true)
	{
		ispis(niz2, vel2);
	}
	else
		cout << "Neuspjela inicijalizacija. " << endl;

	ispis(niz1, vel1);

	delete[]niz1;
	delete[]niz2;
	niz1 = nullptr;
	niz2 = nullptr;
}

int unos(float * niz, int vel)
{
	int brojac = 0;
	for (int i = 0; i < vel; i++)
	{
		cout << "niz[" << i << "]: ";
		cin >> niz[i];
		if (niz[i] < 0)
			brojac++;
	}
	return brojac;
}
void ispis(float * niz, int vel)
{
	for (int i = 0; i < vel; i++)
		cout << niz[i] << " | ";
	cout << endl;
}
bool inicijaliziraj(float* niz1, float*niz2, int vel)
{
	int lokacijaNiza2 = 0;
	for (int i = 0; i < vel; i++)
	{
		if (niz1[i] < 0)
		{
			niz2[lokacijaNiza2] = niz1[i];
			lokacijaNiza2++;
		}
	}
	//if (lokacijaNiza2 == 0)
	//	return false;
	//else
	//	return true;
	return lokacijaNiza2 > 0;
}