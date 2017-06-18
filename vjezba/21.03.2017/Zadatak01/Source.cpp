#include <iostream>
using namespace std;

void main(void)
{
	//a
	float broj1, broj2;
	//b
	broj1 = 7.3;
	//c
	float* p;
	//d
	p = &broj1;
	//e
	cout << *p << endl;
	//f
	p = &broj2;
	*p = 4.3;
	cout << *p << endl;
	//g
	cout << &broj1 << endl;

	system("pause");
}