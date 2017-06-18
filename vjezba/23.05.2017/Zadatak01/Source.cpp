#include<iostream>

using namespace std;

int main()
{
	char* A = new char[20];
	cin.getline(A, 20);
	
	char B[20];
	cin >> B;

	char* C = new char[strlen(A) + strlen(B) + 2] {'\0'};
	//strcpy_s(C, strlen(A) + 1, A);
	strcat_s(C, strlen(A) + 1, A);
	strcat_s(C, strlen(A) + strlen(B) + 1, B);
	
	cout << C << endl;
	


	system("pause");
}