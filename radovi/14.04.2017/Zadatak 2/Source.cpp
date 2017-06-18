#include <iostream>

using namespace std;

struct Tacka
{
	int x;
	int y;
};

struct Trougao
{
	Tacka a;
	Tacka b;
	Tacka c;
};

struct Kruznica
{
	int r;
	Tacka o;
};

void InfoKruznica (Kruznica k)
{
	cout << "Centar O(" << k.o.x << "," << k.o.y << ")\n";
	cout << "Poluprecnika r: " << k.r << endl;
}


void main(void)
{
	Trougao t1;

	//a
	cout << "Trouga tacka A:\n";
	cout << "x: "; cin >> t1.a.x;
	cout << "y: "; cin >> t1.a.y;

	cout << "Trouga tacka B:\n";
	cout << "x: "; cin >> t1.b.x;
	cout << "y: "; cin >> t1.c.y;
	
	cout << "Trouga tacka C:\n";
	cout << "x: "; cin >> t1.c.x;
	cout << "y: "; cin >> t1.c.y;

	//b
	Kruznica k1;
	k1.o = t1.a;


	//c
	cout << "Poluprecnik kruznice: ";
	cin >> k1.r;

	//d
	Kruznica k3 = k1;

	//e
	k3.r += k3.r * (10 / 100);

	//f
	Kruznica k2 = k3;
	k2.o.x = t1.b.x;
	k2.o.y = t1.b.y;

	InfoKruznica(k1);
	InfoKruznica(k2);
	InfoKruznica(k3);

}