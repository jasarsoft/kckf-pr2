#include <iostream>
using namespace  std;

#include "Klijent.h"
#include "Podaci.h"
#include "Odabiri.h"
#include "Datum.h"


void m_klijent_add()
{
	if (KlijentBrojac >= KlijentMax)
	{
		cout << "Klijent: Dostignut je maksimalni broj.\n";
		return;
	}

	char ime[20];
	char prezime[20];
	cin.ignore();

	cout << "Unesite ime -> ";
	cin.getline(ime, 20);
	
	cout << "Unesite prezime -> ";
	cin.getline(prezime, 20);

	KlijentNiz[KlijentBrojac++] = Klijent_Napravi(ime, prezime);
	cout << "Klijent: uspjesno napravljen.\n";
}

void m_racun_add()
{
	Klijent* k = Klijent_odaberi();

	char broj_racuna[20];
	cin.ignore();
	cout << "Unesite broj racuna: ";
	cin.getline(broj_racuna, 20);
	Racun* r = Racun_Napravi(broj_racuna);
	k->racuni.Dodaj(r);
}

void m_uplata_add()
{
	Klijent* k = Klijent_odaberi();
	Racun* r = Racun_odaberi(k);
	
	int d, m, g;
	cout << "Unesite datum uplate:\n";
	cin >> d >> m >> g;
	
	float iznos;
	cout << "Unesi iznos: ";
	cin >> iznos;

	Transakcija* transakcija = Transakcija_NapraviUplatu(iznos, Datum::Napravi(d, m, g));
	r->transakcije.Dodaj(transakcija);
}

void m_isplata_add()
{
	Klijent* k = Klijent_odaberi();
	Racun* r = Racun_odaberi(k);

	int d, m, g;
	cout << "Unesite datum isplate:\n";
	cin >> d >> m >> g;
	
	char to[20];
	cin.ignore();
	cout << "Za: ";
	cin.getline(to, 20);

	float iznos;
	cout << "Iznos: ";
	cin >> iznos;

	Transakcija* transakcija = Transakcija_NapraviIsplatu(iznos, to, Datum::Napravi(d, m, g));
	r->transakcije.Dodaj(transakcija);
}

void m_transakcija_deaktiviraj()
{
	Klijent* k = Klijent_odaberi();
	Racun* r = Racun_odaberi(k);
	Transakcija* t = Transakcija_odaberi(r);

	t->_aktivna = false;
}

void m_pretraga_klijenta()
{
	char trazim[20];
	cout << "Unesite string za pretragu -> ";
	cin.getline(trazim, 20);
	for (size_t i = 0; i < KlijentBrojac; i++)
	{
		if (strcmp(KlijentNiz[i]->_ime, trazim) == 0 || strcmp(KlijentNiz[i]->_ime, trazim) == 0) {
			KlijentNiz[i]->Ispis();
			cout << endl;
		}
	}
}

void m_prikazi_transkacije_za_mjesec()
{
	int mjesec;
	int godina;
	cout << "Unesite mm/gggg za pretragu -> ";
	cin >> mjesec;
	cin >> godina;
	cin.ignore();
	for (int i = 0; i < KlijentBrojac; i++)
	{
		Klijent* klijent = KlijentNiz[i];

		for (int j = 0; j < klijent->racuni.brojac; j++)
		{
			Racun* racun = klijent->racuni.Get(j);

			for (int k = 0; k < racun->transakcije.brojac; k++)
			{
				Transakcija* transakcija = racun->transakcije.Get(k);

				if (transakcija->_datumTransakcije._mjesec == mjesec
					&& transakcija->_datumTransakcije._godina == godina)
				{
					transakcija->Ispis();
					cout << "\n-----------------------------------\n";
				}
			}
		}
	}
}

void main()
{
	int unos;
	do
	{
		cout << "1. DODAJ: KLIJENT" << endl;
		cout << "2. DODAJ: RACUN" << endl;
		cout << "3. DODAJ: UPLATU" << endl;
		cout << "4. DODAJ: ISPLATU" << endl;
		cout << "5. Ponisti transakciju (deaktiviraj)" << endl;
		cout << "6. Pretraga klijenata po imenu" << endl;
		cout << "7. Prikazi transakcije po za odabrani mjesec" << endl;
		cout << "0. EXIT" << endl;

		cin >> unos;
		if (unos == 1) m_klijent_add();
		if (unos == 2) m_racun_add();
		if (unos == 3) m_uplata_add();
		if (unos == 4) m_isplata_add();
		if (unos == 5) m_transakcija_deaktiviraj();
		if (unos == 6) m_pretraga_klijenta();
		if (unos == 7) m_prikazi_transkacije_za_mjesec();
	} while (unos != 0);
}
