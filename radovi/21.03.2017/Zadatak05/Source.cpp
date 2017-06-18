#include <iostream>
using namespace std;

void saberi(int* x, int* y, int* z)
{
	*z = *x + *y;

	//cout << *z << endl;
	//cout << *x + *y << endl;
}

void main(void)
{
	int a = 1;
	int b = 2;
	int* p;

	saberi(&a, &b, p);
	cout << *p << endl;

	system("pause");
}