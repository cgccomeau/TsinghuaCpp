#ifndef MONTH
#define MONTH

#include <iomanip>
#include <iostream>
using namespace std;

enum Month {
	JAN = 1,
	FEB,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUG,
	SEPT,
	OCT,
	NOV,
	DEC,
	nullMonth // for error handling
};

/*
For printing output purposes in the header of the final budget
*/
void printFullName(Month m) {
	if (m == 1) {
		cout << "January";
	} else if (m == 2) {
		cout << "February";
	} else if (m == 3) {
		cout << "March";
	} else if (m == 4) {
		cout << "April";
	} else if (m == 5) {
		cout << "May";
	} else if (m == 6) {
		cout << "June";
	} else if (m == 7) {
		cout << "July";
	} else if (m == 8) {
		cout << "August";
	} else if (m == 9) {
		cout << "September";
	} else if (m == 10) {
		cout << "October";
	} else if (m == 11) {
		cout << "November";
	} else if (m == 12) {
		cout << "December";
	}
}

ostream& operator<< (ostream &out, const Month &c) {
	out << left;
	if (c == 1) {
		out << "JAN";
	} else if (c == 2) {
		out << "FEB";
	} else if (c == 3) {
		out << "MARCH";
	} else if (c == 4) {
		out << "APRIL";
	} else if (c == 5) {
		out << "MAY";
	} else if (c == 6) {
		out << "JUNE";
	} else if (c == 7) {
		out << "JULY";
	} else if (c == 8) {
		out << "AUG";
	} else if (c == 9) {
		out << "SEPT";
	} else if (c == 10) {
		out << "OCT";
	} else if (c == 11) {
		out << "NOV";
	} else if (c == 12) {
		out << "DEC";
	} else {
		out << "INVALID MONTH INPUT, MUST BE AN INTEGER (1-12)";
	}
	
	return out;
}

/*
  Uses a string for error handling when input contains non-numbers
*/
istream& operator>>(istream& is, Month& i)
{
	cout << "Please enter a valid month number between 1-12 (1 = Jan, 2 = Feb, ... 12 = Dec)" << endl;
	string check = ""; 
	int tmp;
    if (is >> check && (check == "1" || check == "2" || check == "3"
		|| check == "4" || check == "5" || check == "6" 
		|| check == "7" || check == "8" || check == "9" 
		|| check == "10" || check == "11" || check == "12")) {
		if (check == "1") {
			tmp = 1;
		} else if (check == "2") {
			tmp = 2;
		} else if (check == "3") {
			tmp = 3;
		} else if (check == "4") {
			tmp = 4;
		} else if (check == "5") {
			tmp = 5;
		} else if (check == "6") {
			tmp = 6;
		} else if (check == "7") {
			tmp = 7;
		} else if (check == "8") {
			tmp = 8;
		} else if (check == "9") {
			tmp = 9;
		} else if (check == "10") {
			tmp = 10;
		} else if (check == "11") {
			tmp = 11;
		} else if (check == "12") {
			tmp = 12;
		} else {
			tmp = 13;
		}
		
		i = static_cast<Month>(tmp);
	} else {
		i = static_cast<Month>(13);
	}
    return is;
}

#endif