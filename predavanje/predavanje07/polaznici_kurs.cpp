#include<iostream>
using namespace std;

int id = 1;
char *line = "\n-----------------------------\n";

struct Polaznik
{
	int _id;
	char * _ime;
	char * _prezime;

	void unos()
	{
		_id = id++;

		char temp[100];
		int vel;
		cout << "Ime: ";
		cin.getline(temp, 100);

		vel = strlen(temp) + 1;
		_ime = new char[vel];
		strcpy_s(_ime, vel, temp);

		cout << "Prezime: ";
		cin.getline(temp, 100);
		vel = strlen(temp) + 1;
		_prezime = new char[vel];
		strcpy_s(_prezime, vel, temp);
	}
	void ispis()
	{
		cout << "Id: " << _id << endl;
		cout << "Ime i prezime: " << _ime << " " << _prezime;
		cout << line;
	}
	void dealociraj()
	{
		delete[]_ime; _ime = nullptr;
		delete[]_prezime; _prezime = nullptr;
	}
	void inicijaliziraj(Polaznik p)
	{
		_id = p._id;
		int vel = strlen(p._ime) + 1;
		_ime = new char[vel];
		strcpy_s(_ime, vel, p._ime);
		vel = strlen(p._prezime) + 1;
		_prezime = new char[vel];
		strcpy_s(_prezime, vel, p._prezime);
	}
};

struct Kurs
{
	int _id;
	char * _naziv;
	Polaznik * _polaznici;
	int _trenutno;
	int _max;

	void unos(int max=5)
	{
		_id = id++;
		_trenutno = 0;
		_max = max;

		cout << "Unesite naziv kursa:";
		char naziv[100];
		cin.getline(naziv, 100);
		int vel = strlen(naziv) + 1;
		_naziv = new char[vel];
		strcpy_s(_naziv, vel, naziv);

		//krairanje praznog niza polaznika
		//rezervisanje memorije za "_max" polaznika
		_polaznici = new Polaznik[_max];
	}
	void ispis()
	{
		cout << "Id: " << _id;
		cout << "Kurs: " << _naziv << endl;
		for (int i = 0; i < _trenutno; i++)
			_polaznici[i].ispis();
		cout << line;
	}
	void dealociraj()
	{
		delete[] _naziv; _naziv = nullptr;
		for (int i = 0; i < _trenutno; i++)
			_polaznici[i].dealociraj();
		delete[] _polaznici; _polaznici = nullptr;
	}
	bool dodajPolaznika(Polaznik p)
	{
		if (_trenutno == _max)
			return false;
		for (int i = 0; i < _trenutno; i++)
			if (strcmp(_polaznici[i]._prezime, p._prezime)==0)
				return false;
		_polaznici[_trenutno].inicijaliziraj(p);
		_trenutno++;
		return true;
	}
	bool ukloniPolaznika(int id)
	{
		for (int i = 0; i < _trenutno; i++)
		{
			if (_polaznici[i]._id == id)
			{
				_polaznici[i].dealociraj();
				//samo ako ne uklanjam posljednji element
				if (i < _trenutno - 1)
				{
					_polaznici[i].inicijaliziraj(_polaznici[_trenutno - 1]);
					_polaznici[_trenutno - 1].dealociraj();
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
	Polaznik p1, p2, p3;

	p1.unos();
	p2.unos();
	p3.unos();

	Kurs kurs;
	kurs.unos();
	
	if (kurs.dodajPolaznika(p1) == true)
		cout << "Uspjesno dodan polaznik\n";
	else
		cout << "Niste dodali polaznika. Greska!!\n";
	if (kurs.dodajPolaznika(p2) == true)
		cout << "Uspjesno dodan polaznik\n";
	else
		cout << "Niste dodali polaznika. Greska!!\n";
	if (kurs.dodajPolaznika(p3) == true)
		cout << "Uspjesno dodan polaznik\n";
	else
		cout << "Niste dodali polaznika. Greska!!\n";

	kurs.ispis();
	int id;
	cout << "Unesite id korisnika kojeg zelite ukloniti: ";
	cin >> id;
	if(kurs.ukloniPolaznika(id)==true)
		cout << "Uspjesno uklonjen polaznik\n";
	else
		cout << "Polanzik sa unesenim id-em ne postoji!!\n";

	kurs.ispis();

	p1.dealociraj();
	p2.dealociraj();
	p3.dealociraj();
	kurs.dealociraj();
}