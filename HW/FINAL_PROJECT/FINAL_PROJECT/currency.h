#ifndef CURRENCY
#define CURRENCY

#include <iostream>
using namespace std;

enum Currency {
	USD = 1, // US Dollar
	CNY, // Chinese Yuan / Renminbi
	EUR, // Euro
	GBP, // British Pound
	nullCurrency // for error handling
};

ostream& operator<< (ostream &out, const Currency &c) {
	const int width = 3;
	out << left << setw(width);
	if (c == 1) {
		out << " USD";
	} else if (c == 2) {
		out << " CNY";
	} else if (c == 3) {
		out << " EUR";
	} else if (c == 4) {
		out << " GBP";
	} else {
		out << "INVALID INPUT, MUST BE AN INTEGER (1-4)";
	}
	
	/* Note that besides the dollar sign, none of the other currency symbols were
	able to be displayed (¥,€,£), thus each currency's 3 letter acronym is printed instead */
	return out;
}

/*
  Uses a string for error handling when input contains non-numbers
*/
istream& operator>>(istream& is, Currency& i )
{
	cout << "Please enter a valid currency number for your budget" << endl;
	cout << "1 = American Dollar (USD)" << endl;
	cout << "2 = Chinese Yuan (CNY) or Renminbi (RMB)" << endl;
	cout << "3 = Euro (EUR)" << endl;
	cout << "4 = British Pound (GBP)" << endl;
	string check = "";
	int tmp;
    if (is >> check && (check == "1" || check == "2" || check == "3" || check == "4")) {
		if (check == "1") {
			tmp = 1;
		} else if (check == "2") {
			tmp = 2;
		} else if (check == "3") {
			tmp = 3;
		} else if (check == "4") {
			tmp = 4;
		} else {
			tmp = 5;
		}
		
		i = static_cast<Currency>(tmp);
	} else {
		i = static_cast<Currency>(5);
	}
    return is;
}

#endif