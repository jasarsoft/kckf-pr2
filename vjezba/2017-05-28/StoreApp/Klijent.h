#pragma once

struct Klijent
{
	char _ime[20];
	char _prezime[20];

	void Ispis()
	{
		cout << _ime << " " << _prezime << endl;;
	}
};

Klijent* Klijent_Napravi(char* ime, char* prezime)
{
	Klijent * k = new Klijent;
	strcpy_s(k->_ime, ime);
	strcpy_s(k->_prezime, prezime);
	return k;
}
