#include <iostream>

using namespace std;

struct Tacka
{
	int x;
	int y;
};

struct Kruznica
{
	Tacka t;
	int r;
};

void main(void)
{
	Tacka o1, o2, o3, o4;
	Kruznica k1, k2, k3, k4;

	cout << "Poluprecnik: "; cin >> k1.r;

	k2.r = k1.r;
	k3.r = 2 * k2.r;
	k4.r = k2.r + k3.r;

	//k2.t.x = 3; k2.t.y = 4;
	//k1.t.x = -4; k1.t.y = 6;
	o1.x = 3; o2.y = 4;
	o2.x = -4; o1.y = 6;
	k1.t = o1;
	k2.t = o2;

	//k3.x = -9; k3.y = -20;
	//k4.x = 11; k4.y = -23;
	o3.x = -9; o3.y = -20;
	o4.x = 11; o4.y = -23;


	/*cout << "Kruznica iz drugog kvadranta sa centrom O(" << k2.x << "," << k2.y<< ")";
	cout << " ima isti poluprecnik  kao kruznica O(" << k1.x << "," << k1.y << ")";
	cout << " iz prvog kvadtanta koji iznosi r = " << k2.r;

	cout << " - Kruznica O(" << k3.x << "," << k3.y << ") ";
	cout << "iz treceg kvadranta ima duplo veci poluprecnik (r = " << k3.r << ") ";
	cout << "od kruznice O(" << k1.x << "," << k1.y;

	cout << "Kruznica O(" << k4.x << "," << k4.y << ") ima poluprecnik (r = " << k4.r << ") ";
	cout << "koji predstavlja zbir poluprecnika kruznice O(" << k3.x << "," << k3.y << ") ";
	cout << "i O(" << k4.x << "," << k4.y << ")";*/

	cout << "Kruznica iz drugog kvadranta sa centrom O(" << o2.x << "," << o2.y << ")";
	cout << " ima isti poluprecnik  kao kruznica O(" << o1.x << "," << o1.y << ")";
	cout << " iz prvog kvadtanta koji iznosi r = " << k2.r;

	cout << " - Kruznica O(" << o3.x << "," << o3.y << ") ";
	cout << "iz treceg kvadranta ima duplo veci poluprecnik (r = " << k3.r << ") ";
	cout << "od kruznice O(" << o1.x << "," << o1.y;

	cout << "Kruznica O(" << o4.x << "," << o4.y << ") ima poluprecnik (r = " << o4.r << ") ";
	cout << "koji predstavlja zbir poluprecnika kruznice O(" << o3.x << "," << o3.y << ") ";
	cout << "i O(" << o4.x << "," << o4.y << ")";

}