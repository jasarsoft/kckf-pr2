#pragma once
#include <fstream>
using namespace std;

void f_snimi(ofstream& f, float &x)
{
	f.write((char*)&x, sizeof(x));
}

void f_snimi(ofstream& f, int &x)
{
	f.write((char*)&x, sizeof(x));
}

void f_snimi(ofstream& f, Datum &x)
{
	f.write((char*)&x, sizeof(x));
}

void f_snimi(ofstream& f, char* &x, int v)
{
	 f.write(x, v);
}

template <int velicina>
void f_snimi(ofstream& f, char (& x)[velicina])
{
	int v = velicina;
	f.write(x, v);
}

void f_ucitaj(ifstream& f, float &x)
{
	 f.read((char*)&x, sizeof(x));
}

void f_ucitaj(ifstream& f, int &x)
{
	f.read((char*)&x, sizeof(x));
}

void f_ucitaj(ifstream& f, Datum &x)
{
	f.read((char*)&x, sizeof(x));
}

void f_ucitaj(ifstream& f, char* &x, int v)
{
	f.read(x, v);
}

template <size_t  v>
void f_ucitaj(ifstream& f, char (&x)[v])
{
	f.read(x, v);
}
