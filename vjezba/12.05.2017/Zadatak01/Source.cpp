#include <iostream>
using namespace std;

void ispis(int**, int, int);
void ucitaj(int**, int, int);
int izracunaj_sumu(int**, int, int);
float izracunaj_prosjek(int**, int, int);


void main(void)
{
	int m = 4;
	int n = 3;
	
	int** M = new int*[n] { new int[m], new int[m], new int[m] };

	ucitaj(M, n, m);
	ispis(M, n, m);
	cout << izracunaj_sumu(M, n, m) << endl;
	cout << izracunaj_prosjek(M, n, m) << endl;

	delete[] M;
	system("pause");
}



int izracunaj_sumu(int** X, int r, int k)
{
	int sum = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < k; j++)
			sum += X[i][j];

	return sum;
}

float izracunaj_prosjek(int** X, int r, int k)
{
	return izracunaj_sumu(X, r, k) / (r * k * 1.0);
}


void ispis(int** X, int r, int k)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < k; j++) cout << X[i][j];
		cout << endl;
	}
}

void ucitaj(int** X, int r, int k)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < k; j++) cin >> X[i][j];
		cout << endl;
	}
}