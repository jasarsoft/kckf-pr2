#include <iostream>
using namespace std;


void main()
{
	int x;
	int min = 0;
	cout << "Unesite duzinu niza: ";
	cin >> x;
	int* N = new int[x];

	for (int i = 0; i < x; i++)
	{
		cout << "Niz[" << i << "]: ";
		cin >> *(N + i);
		if (*(N + i) < 0) min++;
	}

	int max = 0;
	int* M = new int[min];
	for (int i = 0; i < x; i++)
	{
		if (*(N + i) < 0)
		{
			*(M + max) = *(N + i);
			max++;
		}		
	}

	system("pause");
}