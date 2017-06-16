#include<iostream>
using namespace std;

void main()
{
	int * p = NULL;
	p = nullptr;
	cout << *p << endl;


	//int broj = 15;
	//int * p = &broj;
	//cout <<"p=>"<< p << endl;
	//cout <<"&broj=>"<< &broj << endl;
	//cout << &p << endl;
	//broj++;
	//cout <<"*p=>"<< *p << endl;
	//cout << "broj=>" << broj << endl;
	//int b = 10;
	//p = &b;
	//cout << "*p=>" << *p << endl;
	//cout << "p=>" << p << endl;
	//cout << "&broj=>" << &broj << endl;
}


#include<iostream>
using namespace std;

void unos(float*, int);
void ispis(float *, int);
float * najveci(float *, int);

void main()
{
	const int vel = 5;
	float niz[vel];
	unos(niz,vel);
	ispis(niz, vel);
	cout << *najveci(niz, vel) << endl;
	ispis(niz, vel);
}

void unos(float * niz, int vel)
{
	for (int i = 0; i < vel; i++)
		cin >> niz[i];
}
void ispis(float * niz, int vel)
{
	for (int i = 0; i < vel; i++)
		cout << niz[i] << " | ";
	cout << endl;
}
float * najveci(float * niz, int vel)
{
	float * najveci = niz;
	for (int i = 1; i < vel; i++)
	{
		if (niz[i] > *najveci)
			najveci = &niz[i];
	}
	return najveci;
}


