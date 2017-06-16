#include <iostream>
using namespace std;

enum Gorivo { Benzin = 1, Dizel, Plin, Elektro, Hibrid };
enum MarkaVozila { BMW=1, Audi, Mercedes, VW };
char *markaVozila[]{ "BMW","Audi","Mercedes","VW" };
char *gorivo[]{ "Benzin","Dizel","Plin","Elektro", "Hibrid" };

struct Datum
{
	int _dan, _mjesec,_godina;
	void unos(int d, int m, int g)
	{
		_dan = d;
		_mjesec = m;
		_godina = g;
	}
	void ispis()
	{
		cout << _dan << "/" << _mjesec << "/" << _godina << endl;
	}
};
struct Vozilo
{
	MarkaVozila _markaVozila;
	Gorivo _gorivo;
	Datum _datumRegistracije;
	int _predjeniKilometri;
	char * _registarskaOznaka;

	void unos();
	void unos(MarkaVozila m, Gorivo g, Datum dr, int kilometri, char * regOznaka)
	{
		_gorivo = g;
		_markaVozila = m;
		_datumRegistracije.unos(dr._dan, dr._mjesec, dr._godina);
		_predjeniKilometri = kilometri;
		int vel = strlen(regOznaka) + 1;
		_registarskaOznaka = new char[vel];
		strcpy_s(_registarskaOznaka, vel, regOznaka);
	}
	void ispis()
	{
		cout <<"Vozilo: "<< markaVozila[_markaVozila-1]<<endl;
		cout << "Gorivo: " << gorivo[_gorivo - 1] << endl;
		cout << "Datum registracije: ";
		_datumRegistracije.ispis();
	}
	void dealociraj()
	{
		delete[] _registarskaOznaka; _registarskaOznaka = nullptr;
	}
	void uvecajKilometre(int kilometri)
	{
		_predjeniKilometri += kilometri;
	}
};
struct Vlasnik
{
	char * _imePrezime;
	Vozilo *_vozila[5];
	const int _max = 5;
	int _trenutno;

	void unos(char *ip)
	{
		int vel = strlen(ip) + 1;
		_imePrezime = new char[vel];
		strcpy_s(_imePrezime, vel, ip);
		_trenutno = 0;
		//for each (Vozilo* v in _vozila)
		//{
		//	v = nullptr;
		//}
		for (int i = 0; i < _max; i++)
			_vozila[i] = nullptr;
	}
	void ispis();
	bool dodajVozilo(Vozilo v)
	{
		if (_trenutno == _max)
			return false;
		_vozila[_trenutno] = new Vozilo;
		_vozila[_trenutno]->unos(v._markaVozila, v._gorivo,
			v._datumRegistracije, v._predjeniKilometri, v._registarskaOznaka);
		_trenutno++;
		return true;
	}
	bool ukloniVozilo(char * registarskaOznaka)
	{
		for (int i = 0; i < _trenutno; i++)
		{
			if (strcmp(_vozila[i]->_registarskaOznaka, registarskaOznaka) == 0)
			{
				_vozila[i]->dealociraj();
				if (i != _trenutno - 1)
				{
					_vozila[i] = _vozila[_trenutno - 1];
					_vozila[_trenutno - 1] = nullptr;
				}
				_trenutno--;
				return true;
			}
		}
		return false;
	}
	void dealociraj()
	{
		delete[] _imePrezime; _imePrezime = nullptr;
		for (int i = 0; i < _trenutno; i++)
		{
			_vozila[i]->dealociraj();
			delete _vozila[i];
			_vozila[i] = nullptr;
		}
	}
	//vraæa pokazivaè vozilo sa najvise predjenih kilometara od svih vozila
	Vozilo *voziloSaNajviseKilometara()
	{
		if (_trenutno == 0)
			return nullptr;
		int lokacija = 0;
		int najviseKilometara = _vozila[0]->_predjeniKilometri;
		for (int i = 1; i < _trenutno; i++)
		{
			if (_vozila[i]->_predjeniKilometri > najviseKilometara)
			{
				najviseKilometara = _vozila[i]->_predjeniKilometri;
				lokacija = i;
			}
		}
		return _vozila[lokacija];
	}
};


void main()
{
	Vlasnik v;
	v.unos("Amer Vrebac");
}