#pragma once

#include <iostream>
#include <functional>
using namespace std;

typedef int Tip;
const int max_size = 30;

struct Kolekcija
{

	Tip podaci[max_size];
	int brojac = 0;
	
	void kDodaj(Tip newV);
	Kolekcija kFilter(function<bool(Tip&)> f);
	void kForEach(function<void(Tip&)> f);
}; 





