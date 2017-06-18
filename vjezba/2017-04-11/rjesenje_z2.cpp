#include <iostream>
#include <functional>
using namespace std;


void main()
{
	int x;


	do
	{
		cout << "Unesite x: ";
		cin >> x;
	}
	while (x>20 || x<0);
	int niz[20];

	for (int i = 0; i < x; i++)
	{
		cout << i << ": " <<endl;
		cin >> niz[i];
	}
	cout << "==================";
	for (int i = x-1; i >=0; i--)
	{
		cout << i<<": "<< niz[i] << endl;
	}

}