#include <iostream>
using namespace std;

class Time {
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) {
		hour = h % 24;
		min = m;
		sec = s;

		if (sec < 0) {
			sec = 60 + s % 60;
			int subtractMin = (60 - s) / 60;
			min -= subtractMin;
		}
		if (min < 0) {
			min = 60 + min % 60;
			int subtractHr = (24 - m / 60) / 24;
			hour -= subtractHr;
		}
		if (hour < 0) {
			hour = 24 + hour % 24;
		}


		if (sec >= 60) {
			int addToMin = sec / 60;
			sec %= 60;
			min += addToMin;
		}
		if (min >= 60) {
			int addToHr = min / 60;
			min %= 60;
			hour += addToHr;
		}
		if (hour >= 24) {
			hour %= 24;
		}
	}

	void reset() {
		hour = 0;
		min = 0;
		sec = 0;
	}

	void adv(int addHour, int addMin, int addSec) {
		hour += addHour;
		min += addMin;
		sec += addSec;

		if (sec < 0) {
			int subtractMin = (60 - sec) / 60;
			sec = 60 + sec % 60;
			min -= subtractMin;
		}
		if (min < 0) {
			int subtractHr = (60 - min) / 60;
			min = 60 + min % 60;
			hour -= subtractHr;
		}
		if (hour < 0) {
			hour = 24 + hour % 24;
		}

		if (sec >= 60) {
			int addToMin = sec / 60;
			sec %= 60;
			min += addToMin;
		}
		if (min >= 60) {
			int addToHr = min / 60;
			min %= 60;
			hour += addToHr;
		}
		if (hour >= 24) {
			hour %= 24;
		}

	}

	void print() {
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
		cout << endl;
	}


};

int main() {
	int hour, minute, second;
	int incr_hr, incr_min, incr_sec;
	cin >> hour >> minute >> second >> incr_hr >> incr_min >> incr_sec;
	Time t(hour, minute, second);
	t.print();
	t.adv(incr_hr, incr_min, incr_sec);
	t.print();
	t.reset();
	t.print();

	return 0;
}