#include <iostream>
using namespace std;

//void f1(float, float, float, float&, float&, bool&);
void f2(float, float, float, float*, float*, bool*);

void main(void)
{
	//a) u main-u vršite unos parametara a, b i c
	float a, b, c;
	cout << "Unesite a: "; cin >> a;
	cout << "Unesite b: "; cin >> b;
	cout << "Unesite c: "; cin >> c;

	//b) u main - u deklarišite varijablu error, x1, x2
	bool greska;
	float x1, x2;

	//c) iz main-a pozovite funkciju f1 i proslijedite joj aktuelne parametre a, b, c, x1, x2, error
	//f1(a, b, c, x1, x2, greska);

	//d) ispišite rješenja kvadratne jednaèine samo u sluèaju da postoje rješenja
	/*if (!greska)
	{
		cout << "Rjesenje X1: " << x1 << endl;
		cout << "Rjesenje X2: " << x2 << endl;
	}*/
	

	void(*pf1)(float, float, float, float&, float&, bool&);
	pf1 = f1;
	pf1(a, b, c, x1, x2, greska);
	if (!greska)
	{
		cout << "Rjesenje X1: " << x1 << endl;
		cout << "Rjesenje X2: " << x2 << endl;
	}

	bool* pGreska = &greska;
	float* pX1 = &x1;
	float* pX2 = &x2;

	void(*pf2)(float, float, float, float*, float*, bool*);
	pf2 = f2;
	pf2(a, b, c, pX1, pX2, pGreska);
	if (!greska)
	{
		cout << "Rjesenje X1: " << x1 << endl;
		cout << "Rjesenje X2: " << x2 << endl;
	}



	system("pause");
}

void f1(float a, float b, float c, float& r1, float& r2, bool& greska)
{
	if (a == 0.0)
	{
		greska = true;
		return;
	}

	float d = b * b - 4 * a * c;
	if (d < 0)
	{
		greska = true;
		return;
	}

	r1 = (-b + sqrt(d)) / (2 * a);
	r2 = (-b - sqrt(d)) / (2 * a);
	greska = false;
}

void f2(float a, float b, float c, float* r1, float* r2, bool* greska)
{
	if (a == 0.0)
	{
		*greska = true;
		return;
	}

	float d = b * b - 4 * a * c;
	if (d < 0)
	{
		*greska = true;
		return;
	}

	*r1 = (-b + sqrt(d)) / (2 * a);
	*r2 = (-b - sqrt(d)) / (2 * a);
	*greska = false;
}