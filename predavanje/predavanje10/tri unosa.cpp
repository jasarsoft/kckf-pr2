#include <iostream>
using namespace std;

struct Datum
{
	int _dan, _mjesec, _godina;

	void unos(int d, int m, int g)
	{
		_dan = d;
		_mjesec = m;
		_godina = g;
	}
	void unos()
	{
		cout << "Unesite datum: ";
		int d, m, g;
		cin >> d >> m >> g;
		unos(d, m, g);
	}
	void unos(Datum d)
	{
		unos(d._dan, d._mjesec, d._godina);
	}
};

void main()
{
	Datum d;
	d.unos(10, 10, 2017);
}