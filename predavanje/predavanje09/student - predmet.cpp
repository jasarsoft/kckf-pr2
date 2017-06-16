#include <iostream>
using namespace std;

struct Predmet
{
	char * _naziv;
	int _ocjena;
	int _ects;

	void unos();
	void ispis();
	void dealociraj();
	void kopiraj(Predmet p);
};

struct Student
{
	char * _imePrezime;
	char * _brojIndeksa;
	Predmet *_predmeti[40];
	int _trenutno;

	void unos();
	void ispis();
	void dealociraj();
	//nije moguæe dodati dva predmeta sa istim nazivom
	bool dodajPredmet(Predmet p);
	//ukoliko student nema ocjena prosjek mu je 5
	float izracunajProsjek();
};
//funkcija treba da vrati studenta sa najboljim prosjekom
Student najboljiStudent(Student * studenti, int max);

void main()
{
	//napraviti niz od 3 studenta
	//dodati im po 2 predmeta
	//pronaæi najboljeg studenta 
}