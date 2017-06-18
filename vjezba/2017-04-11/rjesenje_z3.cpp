#include <iostream>
using namespace std;


void main()
{
	int x;
	const int max = 20;

	do
	{
		cout << "Unesite x: ";
		cin >> x;
	}
	while (x>max || x<0);
	int niz[max];

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