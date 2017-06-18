#include <iostream>
using namespace  std;


void m_klijent_add()
{
}

void m_racun_add()
{
}

void m_uplata_add()
{
}

void m_isplata_add()
{
}

void m_transakcija_deaktiviraj()
{
}

void m_pretraga_klijenta()
{
}

void m_prikazi_transkacije_za_mjesec()
{
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
		cout << "5. Poništi transakciju (deaktiviraj)" << endl;
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
