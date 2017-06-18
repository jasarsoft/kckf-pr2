#include <iostream>
using namespace std;

struct radnik
{
	int ib;
	char ime[10];
	char prezime[10];
	double dohodak[12];
	int staz;
	char spol[10];
};

void unos_dohodka(radnik*);
void unos(radnik *, int);
void ispis(radnik *);
int prebroj_zene(radnik *, int);
void kopiraj_zene(radnik *, radnik *, int);
radnik* najduze_ime(radnik *, int);
void pretraga_po_imenu(radnik *, char *, int);
double prihodi(radnik *, int, int);

void main(void)
{
	int v;
	cout << "Unesite broj radnika: "; cin >> v;
	radnik* r = new radnik[v];

	radnik* r2 = new radnik[v];


	system("pause");
}

void unos_dohodka(radnik* r)
{
	for (int i = 0; i < 12; i++)
	{
		cout << "Dohodak za " << i + 1 << " mjesec: ";
		cin >> r->dohodak[i];
	}
}

void unos(radnik* r, int v)
{
	for (int i = 0; i < v; i++)
	{
		cout << "Unesite id za " << i + 1 << " radnika: "; cin >> (r + i)->ib;
		cout << "Unesite ime za " << i + 1 << " radnika: "; cin.getline((r + i)->ime, sizeof((r + i)->ime)); //cin >> (r + i)->ime;
		cout << "Unesite prezime za " << i + 1 << " radnika: "; cin.getline((r + i)->prezime, sizeof((r + i)->prezime)); //cin >> (r + i)->prezime;
		cout << "Unesite dohodak za " << i + 1 << " radnika: "; unos_dohodka((r + i));
		cout << "Unesite staz za " << i + 1 << " radnika: "; cin >> (r + i)->staz;
		cout << "Unesite spol za " << i + 1 << " radnika: "; cin.getline((r + i)->spol, 10); //cin >> (r + i)->spol;
	}
}

void ispis(radnik* r)
{
	cout << "IB radnika: " << r->ib << endl;
	cout << "Ime radnika: " << r->ime << endl;
	cout << "Prezime radnika: " << r->prezime << endl;
	for (int i = 0; i < 12; i++) cout << "Dohodak za " << i + 1 << " mjesec: " << (r + i)->dohodak << endl;
	cout << "Staz radnika: " << r->staz << endl;
	cout << "Spol radnika: " << r->spol << endl;
}

int prebroj_zene(radnik* r, int v)
{
	int num = 0;

	for (int i = 0; i < v; i++)
	{
		if (!strcmp((r + i)->spol, "zensko")) num++;
	}

	return num;
}

void kopiraj_zene(radnik* r1, radnik* r2, int v)
{
	for (int i = 0; i < v; i++)
	{
		if (!strcmp((r1 + i)->spol, "zensko"))
		{
			(r2 + i)->ib = (r1 + i)->ib;
			strcpy_s((r2 + i)->ime, sizeof((r1 + i)->ime), (r1 + i)->ime);
			strcpy_s((r2 + i)->prezime, sizeof((r1 + i)->prezime), (r1 + i)->ime);
			for (int j = 0; j < 12; j++) (r2 + i)->dohodak[j] = (r1 + i)->dohodak[j];
			(r2 + i)->staz = (r1 + i)->staz;
			strcpy_s((r2 + i)->spol, sizeof((r1 + i)->spol), (r1 + i)->spol);
		}
	}
}

radnik* najduze_ime(radnik *r, int v)
{
	int id, len = 0;
	
	for (int i = 0; i < v; i++)
	{
		int tmp = strlen((r + i)->prezime);
		if (tmp > len)
		{
			id = i;
			len = tmp;
		}
	}

	return r + id;
}

void pretraga_po_imenu(radnik* r, char* ime, int v)
{
	for (int i = 0; i < v; i++)
	{
		if (!strcmp((r + i)->ime, ime)) ispis(r + i);
	}
}

double prihodi(radnik* r, int ib, int v)
{
	double sum = 0;

	for (int i = 0; i < v; i++)
	{
		if ((r + i)->ib == ib)
		{
			for (int j = 0; j < 12; j++) sum += (r + i)->dohodak[j];
			sum += ((sum * 6.0) / 100) * (r + i)->staz;
		}
	}

	return sum;
}