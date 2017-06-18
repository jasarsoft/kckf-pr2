#include <iostream>
using namespace std;

void main(void)
{
	//h) unijeti dva broja(a i b tipa float).
	float a, b;
	//i) deklarisati pokazivaè p1 koji æe pokazivati na varijablu a
	float* p1 = &a;
	//j) deklarisati pokazivaè p2 koji æe pokazivati na varijablu b
	float* p2 = &b;
	//k) izraèunati sljedeæe matematièke izraze koristeæi pokazivaèe p1 i p2(tj.bez korištenja varijable a i b).
	float c1 = *p1 - *p2;
	float c2 = sin(*p1) - cos(*p2);
	float c3 = *p2 * *p1;
	float c4 = *p1 / *p2;
	float c5 = pow(*p1, *p2);
	float c6 = pow(sqrt(*p1), *p2);
}