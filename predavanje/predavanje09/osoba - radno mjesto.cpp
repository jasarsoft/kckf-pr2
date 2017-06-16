#include <iostream>
using namespace std;

struct Osoba
{
	char *_ime;
	char *_prezime;

	void unos()
	{
		char temp[50];
		int vel;
		cout << "Ime: ";
		cin.getline(temp, 50);
		vel = strlen(temp)+1;
		_ime = new char[vel];
		strcpy_s(_ime, vel, temp);

		cout << "Prezime: ";
		cin.getline(temp, 50);
		vel = strlen(temp)+1;
		_prezime = new char[vel];
		strcpy_s(_prezime, vel, temp);
	}
	void ispis()
	{
		cout << "Ime i prezime: " << _ime << " " << _prezime << endl;
	}
	void dealociraj()
	{
		delete[]_ime; _ime = nullptr;
		delete[]_prezime; _prezime = nullptr;
	}
	void kopiraj(Osoba o)
	{
		int vel = strlen(o._ime) + 1;
		_ime = new char[vel];
		strcpy_s(_ime, vel, o._ime);
		vel = strlen(o._prezime)+1;
		_prezime = new char[vel];
		strcpy_s(_prezime, vel, o._prezime);
	}
	bool istaOsoba(Osoba o)
	{
		if (strcmp(_ime, o._ime) == 0 && strcmp(_prezime, o._prezime) == 0)
			return true;
		return false;
	}
};

struct RadnoMjesto
{
	char * _naziv;
	int _max;
	int _trenutno;
	Osoba *_radnici[3];

	void unos()
	{
		char naziv[100];
		cout << "Unesite naziv radnog mjesta: ";
		cin.getline(naziv, 100);
		int vel = strlen(naziv) + 1;
		_naziv = new char[vel];
		strcpy_s(_naziv, vel, naziv);
		_trenutno = 0;
		_max = 3;
		for (int i = 0; i < _max; i++)
			_radnici[i] = nullptr;
	}
	void ispis()
	{
		cout << "Radno mjesto: " << _naziv << endl;
		for (int i = 0; i < _trenutno; i++)
			_radnici[i]->ispis();
	}
	void dealociraj()
	{
		delete[] _naziv; _naziv = nullptr;
		for (int i = 0; i < _trenutno; i++)
		{
			_radnici[i]->dealociraj();
			delete _radnici[i];
		}
	}
	bool dodajRadnika(Osoba o)
	{
		if (_trenutno == _max)
			return false;
		_radnici[_trenutno] = new Osoba;
		_radnici[_trenutno]->kopiraj(o);
		_trenutno++;
		return true;
	}
	bool uklnoiRanika(Osoba o )
	{
		for (int i = 0; i < _trenutno; i++)
		{
			if (_radnici[i]->istaOsoba(o) == true)
			{
				//r1		r2		null
				//dealociraj memoriju za r1
				_radnici[i]->dealociraj();
				//samo ako se ne radi o posljednjem elemntu
				if (i != _trenutno - 1)
				{
					//prebaci posljednjeg radnika na njegovu poziciju
					_radnici[i]->kopiraj(*_radnici[_trenutno - 1]);
					//dealociraj r3
					_radnici[_trenutno - 1]->dealociraj();
					//oslobodi memoriju pokazivaèa
					delete _radnici[_trenutno - 1];
					_radnici[_trenutno - 1] = nullptr;
				}
				else
				{
					//ukoliko se radi o posljednjem elementu
					delete _radnici[i];
					_radnici[i] = nullptr;
				}
				_trenutno--;
				return true;
			}
		}
		return false;
	}
};

void main()
{
	RadnoMjesto programer;
	Osoba o1, o2;
	o1.unos();
	o2.unos();
	programer.unos();

	programer.dodajRadnika(o1);
	programer.dodajRadnika(o2);
	cout << "Prije uklanjanja\n";
	programer.ispis();
	programer.uklnoiRanika(o1);

	cout << "Nakon uklanjanja\n";
	programer.ispis();

	o1.dealociraj();
	o2.dealociraj();
	programer.dealociraj();
}