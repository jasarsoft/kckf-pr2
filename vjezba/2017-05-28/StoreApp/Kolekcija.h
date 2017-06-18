#pragma once
#include <iostream>
#include <memory>
#include"Datum.h"

using namespace std;

typedef StavkaFakture* Tip;

struct Kolekcija
{
	int max_size = 30;
	Tip* podaci=new Tip[max_size];
	int brojac = 0;
	void Prosiri()
	{
		max_size *= 2;
		Tip* podaciNew = new Tip[max_size];
		for (int i = 0; i < brojac; i++)
		{
			podaciNew[i] = podaci[i];
		}
		delete[]podaci;
		podaci = podaciNew;
	}

	Tip& Get(int i)
	{
		return podaci[i];
	}
	void Dodaj(Tip newV)
	{
		if (brojac == max_size)
			Prosiri();
		podaci[brojac++] = newV;
	}
};

