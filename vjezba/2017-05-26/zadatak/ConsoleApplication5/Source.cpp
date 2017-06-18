#include <iostream>
#include "Faktura.h"
#include "StoreAppUI.h"
using namespace  std;




void main()
{
	int unos;
	do
	{
		cout << "1. OPEN STORE FROM FILE" << endl;
		cout << "2. NEW STORE" << endl;
		cout << "3. SAVE CHANGES TO FILE [" << fileName<<"]" << endl;
		cout << "4. DODAJ: GRAD" << endl;
		cout << "5. DODAJ: KLIJENT" << endl;
		cout << "6. DODAJ: PROIZVOD" << endl;
		cout << "7. DODAJ: PRODAJA (FAKTURA)" << endl;
		cout << "8. TEST APP" << endl;
		cout << "0. EXIT" << endl;

		cin >> unos;
		if (unos == 1) m_file_open();
		if (unos == 2) m_store_new();
		if (unos == 3) m_file_save();
		if (unos == 4) m_grad_add();
		if (unos == 5) m_klijent_add();
		if (unos == 6) m_proizvod_add();
		if (unos == 7) m_prodaja_add();
		if (unos == 8) m_test_app();
	} while (unos != 0);
}
