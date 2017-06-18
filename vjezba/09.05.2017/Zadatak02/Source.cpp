#include <iostream>
using namespace std;


void main()
{
	//a)
	int A[5] = { 201, 202, 203, 204, 205 };
	for (int i = 0; i < 5; i++) cout << &A[i] << endl;

	//b)
	cout << A << endl;

	int* p[5];
	for (int i = 0; i < 5; i++)
	{
		p[i] = &A[i];
		cout << *p[i] << endl;
	}

	system("pause");
}