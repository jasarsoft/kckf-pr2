#include <iostream>
using namespace std;

void zamjeni(int* p1, int* p2)
{
	*p1 = *p1 - *p2;
	*p2 = *p1 + *p2;
	*p1 = *p2 - *p1;
}

void zamjeni2(int* p1, int* p2)
{
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}

void zamjeni3(int* p1, int* p2)
{
	for (int i = 0; i < 16; i++)
	{
		if ((*p1 & (1 << i)) ^ (*p2 & (1 << i)))
		{
			*p1 = *p1 ^ (1 << i);
			*p2 = *p2 ^ (1 << i);
		}
	}
}

void main(void)
{
	int a = -6;
	int b = -5;
	zamjeni(&a, &b);
	cout << a << endl << b << endl;

	int c = -5;
	int d = 5;
	zamjeni2(&c, &d);
	cout << c << endl << d << endl;

	cout << "----------------\n";
	int e = 2;
	int f = 3;
	cout << "Orignal:\n";
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;

	zamjeni3(&e, &f);
	cout << "Zamjenjeno:\n";
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;

	

	system("pause");
}