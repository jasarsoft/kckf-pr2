#include <iostream>
using namespace std;

struct kruznica
{	
	float x; 				
	float y; 				
	float poluprecik; 
};

void main()
{
	kruznica k1, k2, k3, k4;

	k1.x = 3; 
	k1.y = 4;
	cout << "Unesi r1: ";
	cin >> k1.poluprecik;

	k2.x = -4;
	k2.y = 6;
	k2.poluprecik = k1.poluprecik;

	k3.x = -9;
	k3.y = -20;
	k3.poluprecik = k1.poluprecik * 2;

	k4.x = 11;
	k4.y = -23;
	k4.poluprecik = k1.poluprecik + k2.poluprecik;

	cout << "Kružnica iz drugog kvadranta sa centrom O(";
	cout << k1.x << "," << k1.y << ") ima isti polupreènik kao \nkružnica O(";
	cout << k2.x << "," << k2.y << ") iz prvog kvadranta koji iznosi r = ";
	cout << k1.poluprecik ;
	//....
}
