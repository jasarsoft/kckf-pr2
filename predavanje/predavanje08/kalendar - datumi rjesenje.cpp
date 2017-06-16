#include<iostream>
#include<Windows.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum Boja{Plava=1,Crvena,Zelena,Zuta};

struct Datum
{
	int *_dan,
		*_mjesec,
		*_godina;

	void unos()
	{
		_dan = new int;
		_mjesec = new int;
		_godina = new int;
		cout << "Unesite datum(dd/mm/gggg): ";
		cin >> *_dan >> *_mjesec >> *_godina;
	}
	void ispis()
	{
		cout << *_dan << "/" << *_mjesec << "/" << *_godina << endl;
	}
	void dealociraj()
	{
		delete _dan; _dan = nullptr;
		delete _mjesec; _mjesec = nullptr;
		delete _godina; _godina = nullptr;
	}
	bool istiDatumi(Datum d)
	{
		//if (*_dan == *d._dan && *_mjesec == *d._mjesec
		//	&& *_godina == *d._godina)
		//	return true;
		//return false;
		return *_dan == *d._dan && *_mjesec == *d._mjesec &&
			*_godina == *d._godina;
	}
	void inicijaliziraj(Datum d)
	{
		_dan = new int(*d._dan);
		_mjesec = new int(*d._mjesec);
		_godina = new int(*d._godina);
		//*_dan = *d._dan;
	}
};

struct Napomena
{
	char * _opis;
	Datum _datumNapomene;
	Boja _bojaNpomene;

	void unos()
	{
		cout << "Datum napomene - ";
		_datumNapomene.unos();
		cin.ignore();
		cout << "Unesite opis: ";
		char opis[1000];
		cin.getline(opis, 1000);
		int vel = strlen(opis)+1;
		_opis = new char[vel];
		strcpy_s(_opis, vel, opis);
		int izbor;
		do
		{
			cout << "Izaberite boju napomene: " << endl <<
				"1. Plava\n2. Crvena\n3. Zelena\n4. Zuta\n";
			cin >> izbor;
		} while (izbor<1 || izbor>4);
		_bojaNpomene = (Boja)izbor;
	}
	void ispis()
	{

		switch (_bojaNpomene)
		{
		case Plava:
			SetConsoleTextAttribute(hConsole, 1 | FOREGROUND_INTENSITY);
			break;
		case Crvena:
			SetConsoleTextAttribute(hConsole, 4 | FOREGROUND_INTENSITY);
			break;
		case Zelena:
			SetConsoleTextAttribute(hConsole, 2 | FOREGROUND_INTENSITY);
			break;
		case Zuta:
			SetConsoleTextAttribute(hConsole, 6 | FOREGROUND_INTENSITY);
			break;
		default:
			SetConsoleTextAttribute(hConsole, 7 | FOREGROUND_INTENSITY);
			break;
		}
		cout << "Napomena: " << _opis << endl;
		cout << "Datum napomene: ";
		_datumNapomene.ispis();
	}
	void dealociraj()
	{
		delete[] _opis; _opis = nullptr;
		_datumNapomene.dealociraj();
	}
	void inicijaliziraj(Napomena n)
	{
		_bojaNpomene = n._bojaNpomene;
		_datumNapomene.inicijaliziraj(n._datumNapomene);
		int vel = strlen(n._opis)+1;
		_opis = new char[vel];
		strcpy_s(_opis, vel, n._opis);
	}
};

struct Kalendar
{
	Napomena * _napomene;
	int _trenutno;
	int _max;

	void unos(int max = 20)
	{
		_trenutno = 0;
		_max = max;
		_napomene = new Napomena[_max];
	}
	void pregledNapomena()
	{
		for (int i = 0; i < _trenutno; i++)
			_napomene[i].ispis();
	}
	void dealociraj()
	{
		for (int i = 0; i < _trenutno; i++)
			_napomene[i].dealociraj();
		delete[] _napomene; _napomene = nullptr;
	}
	bool dodajNapomenu()
	{
		if (_trenutno == _max)
			return false;
		_napomene[_trenutno].unos();
		_trenutno++;
		return true;
	}
	//na osnovu datuma koji unosi korisnik
	bool ukloniNapomenu()
	{
		Datum d;
		cout << "Datum za uklanjanje napomene - ";
		d.unos();
		for (int i = 0; i < _trenutno; i++)
		{
			//if(*_napomene[i]._datumNapomene._dan == *d._dan &&
			//	*_napomene[i]._datumNapomene._mjesec == *d._mjesec &&
			//	*_napomene[i]._datumNapomene._godina == *d._godina)
			if (_napomene[i]._datumNapomene.istiDatumi(d))
			{
				_napomene[i].dealociraj();
				if (i != _trenutno - 1)
				{
					_napomene[i].inicijaliziraj(_napomene[_trenutno - 1]);
					_napomene[_trenutno - 1].dealociraj();
				}
				_trenutno--;
				return true;
				// n1	n4	n3	
			}

		}
		return false;
	}
};

void main()
{
	Kalendar kalendar;

	kalendar.unos();
	kalendar.dodajNapomenu();
	kalendar.dodajNapomenu();
	kalendar.dodajNapomenu();
	kalendar.pregledNapomena();
	SetConsoleTextAttribute(hConsole, 7 | FOREGROUND_INTENSITY);
	kalendar.ukloniNapomenu();
	kalendar.pregledNapomena();

	kalendar.dealociraj();
}