#include <iostream>
struct Time
{
	int year;
	int month;
	int date;
	int hour;
	int min;
	int sec;

};

int main () {
	using namespace std;

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

	Time now = {year, month, date, hour, min, sec};

	cout << now.year << " year " << now.month << " month " << now.date << " date ";
	if (now.hour < 10) {
		cout << 0 << now.hour << ":";
	} else {
		cout << now.hour << ":";
	}
	if (min < 10) {
		cout << 0 << now.min << ":";
	} else {
		cout << now.min << ":";
	}
	if (sec < 10) {
		cout << 0 << now.sec;
	} else {
		cout << now.sec;
	}

	return 0;
}