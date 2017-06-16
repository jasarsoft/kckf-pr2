#include <iostream>
using namespace std;

enum Days {Mon=1,Tue, Wed, Thu, Fri , Sat, Sun};
void ispisDay(Days);

struct Alarm
{
	Days _alarmDay;
	int _hours;
	int _minutes;

	void initialize()
	{
		int intDay;
		do
		{
			cout << "1. Mon\n2. Tue\n3. Wed\n4. Thu\n5. Fri\n6." <<
				" Sat\n7. Sun\n";
			cin >> intDay;
		} while (intDay<1 || intDay>7);
		_alarmDay = (Days)intDay;
		cout << "hours: ";
		cin >> _hours;
		cout << "minutes: ";
		cin >> _minutes;
	}
	void showAlarm()
	{
		cout << this->_hours << ":" << _minutes << " - ";
		ispisDay(_alarmDay);
	}
};

//void Alarm::initialize()
//{
//	int intDay;
//	do
//	{
//		cout << "1. Mon\n2. Tue\n3. Wed\n4. Thu\n5. Fri\n6." <<
//			" Sat\n7. Sun\n";
//		cin >> intDay;
//	} while (intDay < 1 || intDay>7);
//	_alarmDay = (Days)intDay;
//	cout << "hours: ";
//	cin >> _hours;
//	cout << "minutes: ";
//	cin >> _minutes;
//}

void main()
{
	//Alarm * alarm =  new Alarm;
	//alarm->initialize();
	//system("cls");
	//alarm->showAlarm();
	//delete alarm; alarm = nullptr;
	Alarm  alarm;
	alarm.initialize();
	system("cls");
	alarm.showAlarm();
}

void ispisDay(Days day)
{
	switch (day)
	{
	case Mon: cout << "Mon" << endl;
		break;
	case Tue:cout << "Tue" << endl;
		break;
	case Wed:cout << "Wed" << endl;
		break;
	case Thu:cout << "Thu" << endl;
		break;
	case Fri:cout << "Fri" << endl;
		break;
	case Sat:cout << "Sat" << endl;
		break;
	case Sun:cout << "Sun" << endl;
		break;
	}
}

