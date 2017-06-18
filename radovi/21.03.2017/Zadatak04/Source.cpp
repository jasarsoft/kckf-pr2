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
	int c;

	saberi(&a, &b, &c);
	cout << c << endl;

	system("pause");
}