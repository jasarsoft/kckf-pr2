#include <iostream>
#include "Izbornik.h"
using namespace  std;



void main()
{
	int unos;
	do
	{
		cout << "1. DODAJ: KLIJENT" << endl;
		cout << "2. DODAJ: PROIZVOD" << endl;
		cout << "3. DODAJ: PRODAJA (FAKTURA)" << endl;
		cout << "4. Pretraga klijenata po imenu" << endl;
		cout << "5. TEST APP" << endl;
		cout << "0. EXIT" << endl;

		cin >> unos;
		if (unos == 1) m_klijent_add();
		if (unos == 2) m_proizvod_add();
		if (unos == 3) m_prodaja_add();
		if (unos == 4) m_pretraga();
		if (unos == 5) m_test_app();
	} while (unos != 0);
}
