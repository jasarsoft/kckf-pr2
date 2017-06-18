#include <iostream>
#include <functional>
using namespace std;


void main()
{
	int B[5];
	for(int i=0;i<5;i++) 
	{
		cin >> B[i];
	}
	float s = 0;
	for (int i = 0; i<5; i++)
	{
		cout << "Vrijednost za ovaj niz [" <<i<<"] "<< B[i] << endl;
		s += B[i];
	}
	int p = s / 5;
	cout << "prosjek = " << p << endl;


}