#include<iostream>
using namespace std;


void main()
{
	//alociranje memorije za niz objekata nekog tipa
	int vel;
	cout << "Unesite broj elemenata koji zelite: ";
	cin >> vel;
	int * p = new int[vel];

	for (int i = 0; i < vel; i++)
	{
		cout << "niz[" << i << "]: ";
		cin >> p[i];
	}
	for (int i = 0; i < vel; i++)
		cout << p[i] << " | ";
	cout << endl;
	//dealokacija (oslobađanje meorijskog prostora) pokazivača
	delete []p;

	//preuzmjeravanje pokazivača na "null" adresu
	p = nullptr;
	//ili
	p = NULL;
}




