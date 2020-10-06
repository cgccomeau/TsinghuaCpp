#include <iostream>
using namespace std;
int main()
{
	int year;
	int month;
	int date;
	int hour;
	int min;
	int sec;
	cout << "Please input the year, month, date, hour, min, and sec in that order\n";
	cin >> year;
	cin >> month;
	cin >> date;
	cin >> hour;
	cin >> min;
	cin >> sec;
	cout << year << " year " << month << " month " << date << " date ";
	if (hour < 10) {
		cout << 0 << hour << ":";
	} else {
		cout << hour << ":";
	}
	if (min < 10) {
		cout << 0 << min << ":";
	} else {
		cout << min << ":";
	}
	if (sec < 10) {
		cout << 0 << sec;
	} else {
		cout << sec;
	}

		
	return 0;
}