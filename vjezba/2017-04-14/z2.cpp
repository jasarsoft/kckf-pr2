#include <iostream>
using namespace  std;

struct Tacka
{
	float x;
	float y;
};

struct Kruznica
{
	Tacka centar;
	float poluprecnik;
};



void main()
{
	Kruznica k1;
	Kruznica k2;
	Kruznica k3;
	Kruznica k4;

	//a
	k1.centar.x = 5;
	k1.centar.y = 6;
	k2.centar.x = -5;
	k2.centar.y = 6;
	k3.centar.x = -5;
	k3.centar.y = -6;
	k4.centar.x = 5;
	k4.centar.y = -6;
	
	//b
	cout << "Unesite poluprecnik za k1: ";
	cin >> k1.poluprecnik;
	//c
	k2.poluprecnik = k1.poluprecnik;
	//d
	k3.poluprecnik = 2 * k2.poluprecnik;
	//e
	k4.poluprecnik = k2.poluprecnik + k3.poluprecnik;
	cout << endl;
}
