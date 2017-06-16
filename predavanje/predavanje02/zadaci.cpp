#include<iostream>
#include<iomanip>
using namespace std;
const int kolona = 4;
int najbliziNuli(int[], int);
void unos(int matrica[][kolona], int red);
void ispis(int matrica[][kolona], int red);
int suma(int matrica[][kolona], int red);
float prosjekStudenta(int matrica[][kolona], int student);
float prosjekIspita(int matrica[][kolona], int ispit, int redovi);

//	6	7	8	9
//	6	6	6	6
//	10	9	9	10
void main()
{
	const int red = 3;
	int matrix[red][kolona];
	unos(matrix, red);
	ispis(matrix, red);
	//cout<<"suma: "<<suma(matrix, red)<<endl;
}

void ispis(int m[][kolona], int red)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << setw(10) << m[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void unos(int matrica[][kolona], int red)
{
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			cout << "matrica[" << i << "][" << j << "]: ";
			cin >> matrica[i][j];
		}
	}
}
int suma(int matrica[][kolona], int red)
{
	int suma = 0;
	for (int i = 0; i < red; i++)
	{
		for (int j = 0; j < kolona; j++)
		{
			if(matrica[i][j]%3==0 && i==j)
				suma = suma + matrica[i][j];
		}
	}
	return suma;
}
int suma(int matrica[][kolona])
{
	int suma = 0;
	for (int i = 0; i < kolona; i++)
	{
		if (matrica[i][i] % 3 == 0)
			suma = suma + matrica[i][i];
	}
	return suma;
}
float prosjekStudenta(int matrica[][kolona], int student)
{
	float suma = 0;
	for (int i = 0; i < kolona; i++)
	{
		suma = suma + matrica[student][i];
	}
	return suma / kolona;
}
float prosjekIspita(int matrica[][kolona], int ispit, int redovi)
{
	float suma = 0;
	for (int i = 0; i < redovi; i++)
	{
		suma = suma + matrica[i][ispit];
	}
	return suma / redovi;
}
//int najbliziBroju(int niz[], int vel, int broj)
int najbliziNuli(int niz[], int vel)
{
	int najblizi = niz[0];
	for (int i = 1; i < vel; i++)
	{
		if (abs(niz[i]) < abs(najblizi))
			najblizi = niz[i];
	}
	return najblizi;
}