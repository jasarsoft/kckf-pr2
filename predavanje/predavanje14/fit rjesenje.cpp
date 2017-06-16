#include<iostream>
using namespace std;
int brojRacuna = 1;
char * crt = "\n----------------------------------------------------\n";
struct Datum {
	int * _dan, *_mjesec, *_godina;
	void Unos(int d, int m, int g) {
		_dan = new int;
		*_dan = d;
		_mjesec = new int(m);
		_godina = new int(g);
	}
	void Ispis() { cout << *_dan << "/" << *_mjesec << "/" << *_godina << endl; }
	void Dealociraj() {
		delete _dan; delete _mjesec; delete _godina;
		_dan = _mjesec = _godina = nullptr;
	}
};
struct Artikal {
	char * _naziv;
	float _cijena;
	void Unos(char * naziv, float cijena) {
		int vel = strlen(naziv) + 1;
		_naziv = new char[vel];
		strcpy_s(_naziv, vel, naziv);
		_cijena = cijena;
	}
	void Dealociraj() { delete[]_naziv; _naziv = nullptr; }
	void Ispis() { cout << _naziv << " " << _cijena << " KM"; }
};
struct Racun {
	//format broja racuna: ?006005491
	//531
	//osigurati automatsko generisanje broja racuna pocevsi od ?000000001
	char _brojRacuna[10];
	Datum _datumKreiranja;
	Artikal * _artikli;
	int * _kolicine;//cuva informaciju o kolicini svakog artikla na racunu
	int _brojArtikala;
	//Potpisi funkcija trebaju odgovarati onima u main-u
	void Unos(char * brojRacuna, Datum d)
	{
		strncpy_s(_brojRacuna, brojRacuna, 9);
		_datumKreiranja.Unos(*(d._dan), *d._mjesec, *d._godina);
		_brojArtikala = 0;
		_artikli = nullptr;
		_kolicine = nullptr;
	}
	void Dealociraj()
	{
		if (_artikli != nullptr && _kolicine != nullptr)
		{
			for (int i = 0; i < _brojArtikala; i++)
				_artikli[i].Dealociraj();
			delete[]_kolicine; _kolicine = nullptr;
			delete[]_artikli; _artikli = nullptr;
		}
	}
	//3. DodajArtikal(Artikal, koolicina) - dodaje novi artikal u listu artikala zajedno sa njegovom kolicinom. 
	//Onemoguciti ponavljanje artikala na nacin da se uvecava samo kolicina ukoliko
		//korisnik vise puta pokusa dodati isti artikal.
	void DodajArtikal(Artikal artikal, int kolicina)
	{
		if (_artikli != nullptr && _kolicine != nullptr)
		{
			//provjera da li je artikal prethodno dodan
			for (int i = 0; i < _brojArtikala; i++)
			{
				if (strcmp(_artikli[i]._naziv, artikal._naziv) == 0)
				{
					_kolicine[i] += kolicina;
					return;
				}
			}
		}
		Artikal * noviArtikli = new Artikal[_brojArtikala + 1];
		int * noveKolicine = new int[_brojArtikala + 1];

		//kopiram stare artikle i kolicine u nove veæe nizove
		for (int i = 0; i < _brojArtikala; i++)
		{
			noviArtikli[i].Unos(_artikli[i]._naziv, _artikli[i]._cijena);
			noveKolicine[i] = _kolicine[i];
		}

		//dealociram stare nizove samo ako imam šta dealocirati
		if (_artikli != nullptr && _kolicine != nullptr)
		{
			for (int i = 0; i < _brojArtikala; i++)
			{
				_artikli[i].Dealociraj();
			}
			delete[]_artikli;
			delete[]_kolicine;
		}

		//preusmjeravam stare manje artikle i kolièine na  nove veæe nizove
		_artikli = noviArtikli;
		_kolicine = noveKolicine;

		//dodajem novi artikal
		_artikli[_brojArtikala].Unos(artikal._naziv, artikal._cijena);
		_kolicine[_brojArtikala] = kolicina;
		_brojArtikala++;
	}
		//4. Ispis - ispisuje racun u formatu prikazanom na slici (nije obavezno da bude 
		//identican, ali je svakako pozeljno).Prilikom svakog ispisa, racun
		//je potrebno spasiti u tekstualni fajl sa istim nazivom kao i broj racuna.
	void Ispis()
	{
		cout << crt;
		cout << "Broj racuna: " << _brojRacuna<<endl;
		cout << "Datum: ";
		_datumKreiranja.Ispis();
		cout << crt;
		for (int i = 0; i < _brojArtikala; i++)
		{
			_artikli[i].Ispis();
			cout << "	-	" << _kolicine[i]<<"	KOM" << endl;
		}
		cout << crt;
		cout << "Hvala na posjeti.";
		cout << crt;
	}
		//5. Pretraga(char * naziv) - koristeci  pretragu, na osnovu naziva, pronalazi i vraca 
		//pokazivac na artikal.Ukoliko trazeni artikal ne postoji funkcija vraca nullptr.
	Artikal * Pretraga(char *naziv)
	{
		for (int i = 0; i < _brojArtikala; i++)
		{
			if (strcmp(_artikli[i]._naziv, naziv) == 0)
				return &_artikli[i];
		}
		return nullptr;
	}
};
//1. PronadjiNajskupljiArtikal - rekurzivna funkcija koja vraca pokazivac na artikal sa
//najvecom ukupnom cijenom (cijena*kolicina)
//2. char * GenerisiSljedeciBrojRacuna() - generise i vraca naredni broj racuna

Artikal * PronadjiNajskupljiArtikal(Racun racun, int brojArtikala, int lokacijaNajskupljeg)
{
	//može ostati da je jednako nuli ako æemo kao lokaciju poslati 0
	if (brojArtikala == 0)
		return &racun._artikli[lokacijaNajskupljeg];
	if (racun._artikli[brojArtikala - 1]._cijena*racun._kolicine[brojArtikala - 1] >
		racun._artikli[lokacijaNajskupljeg]._cijena*racun._kolicine[lokacijaNajskupljeg])
		PronadjiNajskupljiArtikal(racun, brojArtikala - 1, brojArtikala - 1);
	else
		PronadjiNajskupljiArtikal(racun, brojArtikala - 1, lokacijaNajskupljeg);
}

char *GenerisiSljedeciBrojRacuna()
{
	char * broj = new char[10];
	strcpy_s(broj,10, "00000000");
	int privremeni = brojRacuna;
	int brojac = 0;
	while (privremeni != 0)
	{
		privremeni /= 10;
		brojac++;
	}
	char * p = broj + 9 - brojac;
	_itoa_s(brojRacuna, p,brojac+1, 10);
	brojRacuna++;
	return broj;
}
void main() {
	//za eventualne nejasnoce analizirati testni program i ispise na slici
	Datum danas; danas.Unos(13, 6, 2016);
	Artikal cigarete, cokolada, sok;
	cigarete.Unos("Cigarete", 2.23);
	cokolada.Unos("Cokolada", 1.23);
	sok.Unos("Cappy", 2.10);
	Racun racun;
	racun.Unos(GenerisiSljedeciBrojRacuna(), danas);
	racun.DodajArtikal(cokolada, 5);
	racun.DodajArtikal(sok, 10);
	racun.DodajArtikal(cigarete, 2);
	racun.DodajArtikal(cigarete, 5);
	racun.Ispis();
	Artikal * p1 = racun.Pretraga("Cokolada");
	cout << "Binarnom pretragom pronadjen artikal -> ";
	if(p1!=nullptr)
		p1->Ispis();
	racun.Ispis();
	Artikal * p2 = PronadjiNajskupljiArtikal(racun,racun._brojArtikala,0);
	cout << "Rekurzivno pronadjen najskuplji artikal -> ";
	p2->Ispis();
	cout << endl;
	
	racun.Dealociraj();
	danas.Dealociraj();
	cigarete.Dealociraj();
	cokolada.Dealociraj();
	sok.Dealociraj();
	//dealocirati zauzetu memoriju
}
