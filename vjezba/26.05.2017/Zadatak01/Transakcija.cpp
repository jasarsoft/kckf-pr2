#include "Datum.h"
#include "Transakcija.h"

void Transakcija::Ispis()
{
	if (_aktivna)
	{
		cout << "Vrsta transakcije: " << _vrstaTransakcije << endl;
		cout << "Iznos: " << _iznos << endl;
		cout << "To: " << _TO << endl;
	}
	else
	{
		cout << "Transakcija je obrisana" << endl;
	}
}

Transakcija Transakcija::NapraviUplatu(float iznos, const Datum& datum)
{
	Transakcija t;

	t._vrstaTransakcije = UPLATA;
	strcpy_s(t._TO, "-");
	t._iznos = iznos;
	t._aktivna = true;
	t._datumTransakcije = datum;

	return t;
}
	
Transakcija Transakcija::NapraviIsplatu(float iznos, char* to, Datum& datum)
{
	Transakcija t;

	t._vrstaTransakcije = ISPLATA;
	strcpy_s(t._TO, to);
	t._iznos = iznos;
	t._aktivna = true;
	t._datumTransakcije = datum;

	return t;
}