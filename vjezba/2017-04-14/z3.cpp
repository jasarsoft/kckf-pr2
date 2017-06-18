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

struct Trougao
{
	Tacka A;
	Tacka B;
	Tacka C;
};

void info(Kruznica k)
{
	cout << "centar O( " << k.centar.x << ", "<< k.centar.y << ")";
	cout << "polupreènik r =  " << k.poluprecnik << endl;
}

void main()
{
	//a
	Trougao T1;
	cout << "Unesite x i y za tacku A: ";
	cin >> T1.A.x;
	cin >> T1.A.y;

	cout << "Unesite x i y za tacku B: ";
	cin >> T1.B.x;
	cin >> T1.B.y;

	cout << "Unesite x i y za tacku C: ";
	cin >> T1.C.x;
	cin >> T1.C.y;

	//b
	Kruznica K1;
	K1.centar = T1.A;
	//ili
	K1.centar.x = T1.A.x;
	K1.centar.y = T1.A.y;
	//c
	cout << "Unesite poluprecnik za K1: ";
	cin >> K1.poluprecnik;

	//d
	Kruznica K3 = K1;
	//e
	K3.poluprecnik = K3.poluprecnik * 1.1;
	//ili
	K3.poluprecnik *= 1.1;

	//f
	Kruznica K2 = { T1.B, K3.poluprecnik };
	//ili
	K2.centar = T1.B;
	K2.poluprecnik = K3.poluprecnik;

	info(K1);
	info(K2);
	info(K3);
}
