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

	//a) deklariš	ite niz N tipa integer dužine 15 u statièkoj memoriji
	int N[15];
	//b) deklarišite pokazivaèe p1 i p2 na integer(e) u jednoj liniji koda
	int* p1, *p2;
	//c) alocirajte niz u dinamièkom memoriji dužine 19, i neka p1 pokazuje taj niz
	p1 = new int[19];
	//d) alocirajte niz u dinamièkom memoriji dužine 12, i neka p2 pokazuje taj niz
	p2 = new int[12];
	//e) zamijenite pokazivaèe, neka p1 pokazuje na niz dužine 12, a p2 na niz dužine 19
	int* p3 = p1;
	p1 = p2;
	p2 = p3;
	//f) reciklirajte niz dužine 12 i uèinite da njegov pokazivaè(p1) bude null
	delete[] p1; p1 = nullptr;
	//g) neka p1 pokazuje na elemenat niza sa indeksom 5 na koji pokazuje p2, kao na slici :
	p1 = p2 + 5;
	//h) dodijelite neku(proizvoljnu) vrijednost elementu sa indeksom 5 dereferenciranjem p1(pomoæu operatora '*')
	*p1 = 2;
	//i) dodijelite neku vrijednost elementu sa indeksom 5 dereferenciranjem njegove izraèunate adrese izrazom p2 + 5 (pomoæu operatora '*')
	*(p2 + 5) = 3;
	//j) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izraèunate adrese preko p2(pomoæu operatora '*')
	*(p2 + 2) = 4;
	//k) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izraèunate adrese preko p1(pomoæu operatora '*')
	
	//l) ispišite vrijednost elementa sa indeksom 5 dereferenciranjem pokazivaèa p1(pomoæu operatora '[ ]')

	//m) ispišite vrijednost elementa sa indeksom 5 dereferenciranjem pokazivaèa p2(pomoæu operatora '[ ]')

	//n) ispišite vrijednost elementa sa indeksom 2 dereferenciranjem pokazivaèa p2(pomoæu operatora '[ ]')

	//o) ispišite vrijednost elementa sa indeksom 2 dereferenciranjem pokazivaèa p1(pomoæu operatora '[ ]')

	//p) reciklirajte dinamièki niz dužine 19

	//q) neka p1 pokazuje na prvi elemenat niza N(elemenat sa indeksom 0)

	//r) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izraèunate adrese preko p1(pomoæu operatora '*')

	//s) dodijelite neku vrijednost elementu sa indeksom 2 dereferenciranjem njegove izraèunate adrese preko N(pomoæu operatora '*')

	//t) ispišite vrijednost elementa sa indeksom 2 dereferenciranjem pokazivaèa p1(pomoæu operatora '[ ]')

	//u) ispišite vrijednost elementa sa indeksom 2 dereferenciranjem pokazivaèa N(pomoæu operatora '[ ]')


}