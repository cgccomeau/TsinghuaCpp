#ifndef SPENDING_CAT
#define SPENDING_CAT

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Spending_Cat {
	FIXED = 1,
	VARIABLE,
	SAVINGS,
	nullSpending // for error handling
};

ostream& operator<< (ostream &out, const Spending_Cat &c) {
	const int width = 10;
	out << left << setw(width);
	if (c == 1) {
		out << "FIXED ";
	} else if (c == 2) {
		out << "VARIABLE ";
	} else if (c == 3) {
		out << "SAVINGS ";
	} else {
		out << "INVALID INPUT, MUST BE AN INTEGER (1-3)";
	}
	
	return out;
}

/*
  Uses a string for error handling when input contains non-numbers
*/
istream& operator>>(istream& is, Spending_Cat& i)
{
	cout << "Please enter a valid spending category number (1 = FIXED, 2 = VARIABLE, 3 = SAVINGS)" << endl;
	string check = "";
	int tmp;
    if (is >> check && (check == "1" || check == "2" || check == "3")) {
		if (check == "1") {
			tmp = 1;
		} else if (check == "2") {
			tmp = 2;
		} else if (check == "3") {
			tmp = 3;
		} else {
			tmp = 4;
		}
		
		i = static_cast<Spending_Cat>(tmp);
	} else {
		i = static_cast<Spending_Cat>(4); 
	}
    return is;
}

#endif