#include "Month.h"

#ifndef DATE
#define DATE

#include <iostream>
#include <sstream>
using namespace std;

class Date {
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
private:
	Month m;
	int date;
public:
	Date(Month mon = nullMonth, int a = -1): m(mon), date(a) {}
	
	/*
	Getters & setters for Date class's private members
	*/
	Month getMonth() {
		return m;
	}
	int getDate() {
		return date;
	}

	void setMonth(Month mon) {
		m = mon;
	}

	/*
	Can simultaneously assign month & date and check whether the input 
	is a valid month & date combination. "Null" values are "nullMonth" for 
	month, and -1 for date
	*/
	void setDate(Month mon, int i) {
		if (mon == nullMonth && i == -1) {
			m = nullMonth;
			date = -1;
		} else if (mon == JAN && i >=1 && i <= 31) {
			m = JAN;
			date = i;
		} else if (mon == FEB && i >= 1 && i <= 28) {
			m = FEB;
			date = i;
		} else if (mon == MARCH && i >= 1 && i <= 31) {
			m = MARCH;
			date = i;
		} else if (mon == APRIL && i >= 1 && i <= 30) {
			m = APRIL;
			date = i;
		} else if (mon == MAY && i >= 1 && i <= 31) {
			m = MAY;
			date = i;
		} else if (mon == JUNE && i >= 1 && i <= 30) {
			m = JUNE;
			date = i;
		} else if (mon == JULY && i >= 1 && i <= 31) {
			m = JULY;
			date = i;
		} else if (mon == AUG && i >= 1 && i <= 31) {
			m = AUG;
			date = i;
		} else if (mon == SEPT && i >= 1 && i <= 30) {
			m = SEPT;
			date = i;
		} else if (mon == OCT && i >= 1 && i <= 31) {
			m = OCT;
			date = i;
		} else if (mon == NOV && i >= 1 && i <= 30) {
			m = NOV;
			date = i;
		} else if (mon == DEC && i >= 1 && i <= 31) {
			m = DEC;
			date = i;
		} else if (mon != nullMonth) {
			m = mon;
			date = -1;
		} 
	}
};

ostream& operator<<(ostream& out, const Date& a) {
	const int width = 2;
	out << a.m << " " << left << setw(width) << a.date;
	return out;
}

/*
  Uses a string for error handling when input is not an integer
*/
istream& operator>>(istream& in, Date& a) {

	while (a.m == nullMonth) {
		cout << "INVALID MONTH INPUT, MUST BE AN INTEGER (1-12)" << endl;
		in >> a.m;
	}

	cout << "Please enter a valid date for the month of ";
	if (a.m == JAN) {
		cout << "January (1-31)" << endl;
	} else if (a.m == FEB) {
		cout << "February (1-28)" << endl;
	} else if (a.m == MARCH) {
		cout << "March (1-31)" << endl;
	} else if (a.m == APRIL) {
		cout << "April (1-30)" << endl;
	} else if (a.m == MAY) {
		cout << "May (1-31)" << endl;
	} else if (a.m == JUNE) {
		cout << "June (1-30)" << endl;
	} else if (a.m == JULY) {
		cout << "July (1-31)" << endl;
	} else if (a.m == AUG) {
		cout << "August (1-31)" << endl;
	} else if (a.m == SEPT) {
		cout << "September (1-30)" << endl;
	} else if (a.m == OCT) {
		cout << "October (1-31)" << endl;
	} else if (a.m == NOV) {
		cout << "November (1-30)" << endl;
	} else if (a.m == DEC) {
		cout << "December (1-31)" << endl;
	}
	// Above is a way to personalize output based on previous month intput

	while(a.date == -1) {
		string check = "";
		int realDate;
		in >> check;
		if (check == "1") {
			realDate = 1;
		} else if (check == "2") {
			realDate = 2;
		} else if (check == "3") {
			realDate = 3;
		} else if (check == "4") {
			realDate = 4;
		} else if (check == "5") {
			realDate = 5;
		} else if (check == "6") {
			realDate = 6;
		} else if (check == "7") {
			realDate = 7;
		} else if (check == "8") {
			realDate = 8;
		} else if (check == "9") {
			realDate = 9;
		} else if (check == "10") {
			realDate = 10;
		} else if (check == "11") {
			realDate = 11;
		} else if (check == "12") {
			realDate = 12;
		} else if (check == "13") {
			realDate = 13;
		} else if (check == "14") {
			realDate = 14;
		} else if (check == "15") {
			realDate = 15;
		} else if (check == "16") {
			realDate = 16;
		} else if (check == "17") {
			realDate = 17;
		} else if (check == "18") {
			realDate = 18;
		} else if (check == "19") {
			realDate = 19;
		} else if (check == "20") {
			realDate = 20;
		} else if (check == "21") {
			realDate = 21;
		} else if (check == "22") {
			realDate = 22;
		} else if (check == "23") {
			realDate = 23;
		} else if (check == "24") {
			realDate = 24;
		} else if (check == "25") {
			realDate = 25;
		} else if (check == "26") {
			realDate = 26;
		} else if (check == "27") {
			realDate = 27;
		} else if (check == "28") {
			realDate = 28;
		} else if (check == "29") {
			realDate = 29;
		} else if (check == "30") {
			realDate = 30;
		} else if (check == "31") {
			realDate = 31;
		} else {
			realDate = -1;
		}
		a.setDate(a.m, realDate);

		if (a.date == -1) {
			if (a.m == JAN || a.m == MARCH || a.m == MAY || a.m == JULY || a.m == AUG || a.m == OCT || a.m == DEC) {
				cout << "INVALID DATE INPUT, MUST BE STRICTLY AN INTEGER (1-31)" << endl;
			} else if (a.m == FEB) {
				cout << "INVALID DATE INPUT, MUST BE STRICTLY AN INTEGER (1-28)" << endl;
			} else {
				cout << "INVALID DATE INPUT, MUST BE STRICTLY AN INTEGER (1-30)" << endl;
			}
		}
		// Above is a way to personalize output based on previous month intput
	}

	return in;
}

#endif