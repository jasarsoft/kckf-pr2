#include <iostream>
using namespace std;

#include <memory>

void main(void)
{
	shared_ptr<int> x[5] = {
		make_shared<int>(5),
		make_shared<int>(5),
		make_shared<int>(5),
		make_shared<int>(5)
	};

	//a) deklari�	ite niz N tipa integer du�ine 15 u stati�koj memoriji
	int N[15];
	//b) deklari�ite pokaziva�e p1 i p2 na integer(e) u jednoj liniji koda
	int* p1, *p2;
	//c) alocirajte niz u dinami�kom memoriji du�ine 19, i neka p1 pokazuje taj niz
	p1 = new int[19];
	//d) alocirajte niz u dinami�kom memoriji du�ine 12, i neka p2 pokazuje taj niz
	p2 = new int[12];
	//e) zamijenite pokaziva�e, neka p1 pokazuje na niz du�ine 12, a p2 na niz du�ine 19
	int* p3 = p1;
	p1 = p2;
	p2 = p3;
	//f) reciklirajte niz du�ine 12 i u�inite da njegov pokaziva�(p1) bude null
	delete[] p1; p1 = nullptr;
	//g) neka p1 pokazuje na elemenat niza sa indeksom 5 na koji pokazuje p2, kao na slici :
	p1 = p2 + 5;
	//h) dodijelite neku(proizvoljnu) vrijednost elementu sa indeksom 5 dereferenciranjem p1(pomo�u operatora '*')
	*p1 = 2;
	//i) dodijelite neku vrijednost elementu sa indeksom 5 dereferenciranjem njegove izra�unate adrese izrazom p2 + 5 (pomo�u operatora '*')
	*(p2 + 5) = 3;
	//j) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izra�unate adrese preko p2(pomo�u operatora '*')
	*(p2 + 2) = 4;
	//k) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izra�unate adrese preko p1(pomo�u operatora '*')
	
	//l) ispi�ite vrijednost elementa sa indeksom 5 dereferenciranjem pokaziva�a p1(pomo�u operatora '[ ]')

	//m) ispi�ite vrijednost elementa sa indeksom 5 dereferenciranjem pokaziva�a p2(pomo�u operatora '[ ]')

	//n) ispi�ite vrijednost elementa sa indeksom 2 dereferenciranjem pokaziva�a p2(pomo�u operatora '[ ]')

	//o) ispi�ite vrijednost elementa sa indeksom 2 dereferenciranjem pokaziva�a p1(pomo�u operatora '[ ]')

	//p) reciklirajte dinami�ki niz du�ine 19

	//q) neka p1 pokazuje na prvi elemenat niza N(elemenat sa indeksom 0)

	//r) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izra�unate adrese preko p1(pomo�u operatora '*')

	//s) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izra�unate adrese preko N(pomo�u operatora '*')

	//t) ispi�ite vrijednost elementa sa indeksom 2 dereferenciranjem pokaziva�a p1(pomo�u operatora '[ ]')

	//u) ispi�ite vrijednost elementa sa indeksom 2 dereferenciranjem pokaziva�a N(pomo�u operatora '[ ]')


}