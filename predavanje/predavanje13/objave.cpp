#include <iostream>
using namespace std;

struct DatumVrijeme
{
	int _dan;
	int _mjesec;
	int _godina;
	int _sati;
	int _minute;

	void unos(int dan, int mjesec, int godina, int sati, int minute)
	{
		_dan = dan;
		_mjesec = mjesec;
		_godina = godina;
		_minute = minute;
		_sati = sati;
	}
	void unos(DatumVrijeme d)
	{
		unos(d._dan, d._mjesec, d._godina, d._sati, d._minute);
	}
	//23/1/2017 19:43
	void ispis()
	{
		cout << "Date and time: " << _dan << "/" << _mjesec << "/" << _godina << " " << _sati << ":" << _minute << endl;
	}

	bool istiDatum(DatumVrijeme d)
	{
		return _dan == d._dan && _mjesec == d._mjesec && _godina == d._godina
			&& _minute == d._minute && _sati == d._sati;
	}
};

struct Korisnik
{
	char *_korinsickoIme;
	int _godinaRodjenja;

	void unos(char * ki, int gr)
	{
		int x = strlen(ki) + 1;
		_korinsickoIme = new char[x];
		strcpy_s(_korinsickoIme, x, ki);

		_godinaRodjenja = gr;

	}

	void ispis()
	{
		cout << "Username: " << _korinsickoIme << endl
			<< "Birthdate:  " << _godinaRodjenja << endl << endl;
	}
	void dealociraj()
	{
		delete[]_korinsickoIme, _korinsickoIme = nullptr;
	}
};


struct Komentar
{
	char * _komentar;
	DatumVrijeme _vrijemeKomentara;
	Korisnik _korisnik;

	void unos(char * komentar, DatumVrijeme vrijeme, Korisnik k)
	{
		int x = strlen(komentar) + 1;
		_komentar = new char[x];
		strcpy_s(_komentar, x, komentar);

		//_vrijemeKomentara.unos(vrijeme);
		_vrijemeKomentara = vrijeme;
		_korisnik.unos(k._korinsickoIme, k._godinaRodjenja);

	}
	//vrijeme - komentar
	void ispis()
	{
		cout << "Comment: " << _komentar << endl;
		_vrijemeKomentara.ispis();
		_korisnik.ispis();

	}
	void dealociraj()
	{
		delete[]_komentar, _komentar = nullptr;
		_korisnik.dealociraj();
	}
};

struct Objava
{
	char * _tekst;
	DatumVrijeme _vrijemeObjave;
	Korisnik _korisnik;
	Komentar * _komentari;//komentari na objavu
	int _trenutnoKomentara;

	void unos(char * tekst, DatumVrijeme vrijemeObjave, Korisnik k)
	{
		_trenutnoKomentara = 0;
		int x = strlen(tekst) + 1;
		_tekst = new char[x];
		strcpy_s(_tekst, x, tekst);

		_korisnik.unos(k._korinsickoIme, k._godinaRodjenja);
		_vrijemeObjave.unos(vrijemeObjave);


		_komentari = nullptr;

	}
	void ispis()
	{
		cout << "\n#----------------------------------------------------#\n";
		_korisnik.ispis();
		cout << "Post: " << _tekst << endl;
		_vrijemeObjave.ispis();
		cout << endl;
		for (int i = 0; i < _trenutnoKomentara; i++)
		{
			_komentari[i].ispis();
		}
		cout << "\n#----------------------------------------------------#\n";

	}
	void dealociraj()
	{
		delete[]_tekst, _tekst = nullptr;
		_korisnik.dealociraj();
		for (int i = 0; i < _trenutnoKomentara; i++)
			_komentari[i].dealociraj();
		if(_komentari!=nullptr)
			delete[]_komentari, _komentari = nullptr;
	}
	void dodajKomentar(char * komentar, DatumVrijeme vrijemeKomentara, Korisnik k)
	{
		Komentar *_nk = new Komentar[_trenutnoKomentara + 1];
		if (_komentari != nullptr)
		{
			//prwkopiraj stare komentare
			for (int i = 0; i < _trenutnoKomentara; i++)
				_nk[i].unos(_komentari[i]._komentar, _komentari[i]._vrijemeKomentara, _komentari[i]._korisnik);
			for (int i = 0; i < _trenutnoKomentara; i++)
				_komentari[i].dealociraj();
			delete[]_komentari;
		}
		_komentari = _nk;
		_nk = nullptr;

		//dodaj komentar
		_komentari[_trenutnoKomentara].unos(komentar, vrijemeKomentara, k);
		_trenutnoKomentara++;
	}
	void dodajKomentar(Komentar k)
	{
		dodajKomentar(k._komentar, k._vrijemeKomentara, k._korisnik);
	}
	//uklanja komentar na osnovu vremena kada je isti dodan
	bool ukloniKomentar(DatumVrijeme vrijemeKomentara)
	{
		for (int i = 0; i < _trenutnoKomentara; i++)
		{
			if (_komentari[i]._vrijemeKomentara.istiDatum(vrijemeKomentara))
			{
				_komentari[i].dealociraj();
				if (i != _trenutnoKomentara - 1)
				{
					_komentari[i].unos(_komentari[_trenutnoKomentara - 1]._komentar, _komentari[_trenutnoKomentara - 1]._vrijemeKomentara, _komentari[_trenutnoKomentara - 1]._korisnik);
					_komentari[_trenutnoKomentara - 1].dealociraj();
				}
				_trenutnoKomentara--;
				return true;
			}
		}
		return false;
	}
};

Objava * najaktivnijeObjave(Objava * objave, int max, int brojKomentara, int &brojac)
{
	//funkcija vraca sve objave koje budu imale više komentara od broja
	//koji je proslijeden kao parametar
	brojac = 0;
	//	1	8	15
	int * lokacije = new int[max];


	for (int i = 0; i < max; i++)
		if (objave[i]._trenutnoKomentara >= brojKomentara)
			lokacije[brojac++] = i;

	if (brojac < 0)
		return nullptr;

	Objava *nObjave = new Objava[brojac];
	//	0	1
	for (int i = 0; i < brojac; i++)
	{
		nObjave[i].unos(objave[lokacije[i]]._tekst, objave[lokacije[i]]._vrijemeObjave, objave[lokacije[i]]._korisnik);
		for (int j = 0; j < objave[lokacije[i]]._trenutnoKomentara; j++)
			nObjave[i].dodajKomentar(objave[lokacije[i]]._komentari[j]);
	}

	delete[]lokacije;
	return nObjave;
}


void main()
{
	DatumVrijeme d1, d2, d3;
	d1.unos(11, 11, 1997, 12, 13);
	d2.unos(23, 12, 1998, 11, 11);
	d3.unos(1, 1, 2015, 11, 14);
	//kreirati 4 korisnika
	Korisnik k1, k2, k3, k4;
	//kreirati niz od 3 objave
	Objava o[3], *ok;
	//dodati proizvoljan broj komentara za razlicite
	//korisnike na razlicitim objavama

	k1.unos("Mirsad", 1997);
	k2.unos("Hamid", 1997);
	k3.unos("Omer", 1997);
	k4.unos("Tarik", 1996);


	o[0].unos("Ovo je objava Omera", d3, k3);
	o[1].unos("Ovo je objava Hamida", d2, k2);
	o[2].unos("Ovo je objava mirsada", d1, k1);


	//testirati funkciju najaktivnijeObjave



	int brK;
	char temp[100];
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter num of comments: ";
		cin >> brK;
		cin.ignore();
		for (int j = 0; j < brK; j++)
		{
			cout << "Enter comment for user " << i + 1 << ": ";
			cin.getline(temp, 100);
			if (i == 2)
				o[i].dodajKomentar(temp, d2, k4);
			else if (i == 1)
				o[i].dodajKomentar(temp, d3, k2);
			else
				o[i].dodajKomentar(temp, d1, k3);
		}
	}

	o[0].ukloniKomentar(d1);
	o[0].ukloniKomentar(d2);
	o[0].ukloniKomentar(d3);

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		o[i].ispis();
	}

	cout << endl << endl << "Najaktvnije objave:";
	int brojac = 0;

	ok = najaktivnijeObjave(o, 3, 2, brojac);

	system("cls");
	for (int i = 0; i < brojac; i++)
		ok[i].ispis();

	k1.dealociraj();
	k2.dealociraj();
	k3.dealociraj();
	k4.dealociraj();

	for (int i = 0; i < 3; i++)
	{
		o[i].dealociraj();
	}
	if (ok != nullptr)
	{
		for (int i = 0; i < brojac; i++)
		{
			ok[i].dealociraj();
		}
		delete[]ok, ok = nullptr;
	}
}