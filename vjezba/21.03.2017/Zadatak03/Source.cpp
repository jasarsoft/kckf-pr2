#include <iostream>
using namespace std;

void f1(int* p)
{
	cout << *p << endl;
}


void main(void)
{
	int a;
	cout << "Unesite broj a: ";
	cin >> a;

	int* p1 = &a;
	//f1(p1);
	f1(&a);

	system("pause");
}