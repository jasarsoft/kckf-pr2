#include<iostream>
using namespace std;


void main()
{
	//alociranje memorije za jedan objekat nekog tipa
	float * p = new float;

	cin >> *p;
	cout << "Vrijednost: " << *p << endl;
	cout << "Adresa od vrijdnosti: " << p << endl;
	cout << "Adresa pokazivaca: " << &p << endl;

	//dealokacija (osloba�anje meorijskog prostora) pokaziva�a
	delete p;

	//preuzmjeravanje pokaziva�a na "null" adresu
	p = nullptr;
	//ili
	p = NULL;

	if (p == nullptr)
		cout << "Vec sam obrisao p" << endl;
	else
		cout << *p << endl;

}




