#include <iostream>
using namespace std;

void main(void)
{
	//h) unijeti dva broja(a i b tipa float).
	float a, b;
	//i) deklarisati pokaziva� p1 koji �e pokazivati na varijablu a
	float* p1 = &a;
	//j) deklarisati pokaziva� p2 koji �e pokazivati na varijablu b
	float* p2 = &b;
	//k) izra�unati sljede�e matemati�ke izraze koriste�i pokaziva�e p1 i p2(tj.bez kori�tenja varijable a i b).
	float c1 = *p1 - *p2;
	float c2 = sin(*p1) - cos(*p2);
	float c3 = *p2 * *p1;
	float c4 = *p1 / *p2;
	float c5 = pow(*p1, *p2);
	float c6 = pow(sqrt(*p1), *p2);
}