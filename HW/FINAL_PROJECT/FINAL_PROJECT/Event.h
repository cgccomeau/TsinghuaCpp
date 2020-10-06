#include "spending_cat.h"
#include "currency.h"
#include "Date.h"
#include "Month.h"


#ifndef EVENT
#define EVENT

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

/*
  Used for cout printing, specifically for setprecision printing to the
  hundredth digit
*/
int numDigits(double a) {
	int b = a;
	int c = 0;
	while (b > 0) {
		b /= 10;
		c++;
	}
	return c;
}

/*
  Used for rounding user cin inputs and internal calculations to the
  nearest hundredth 
*/
double round(double r) {
	r *= 1000;
	int a = (int) r;
	if (a % 10 >= 5) {
		a -= (a % 10);
		a += 10;
	} else {
		a -= (a % 10);
	}
	return a / 1000.0;
}

class Event {
	friend ostream& operator<<(ostream&, const Event&);
	friend istream& operator>>(istream&, Event&);
private:
	Date dt;
	Currency curr;
	Spending_Cat type;
	double amount;
	string title;
	string note;
	bool done; // note for input purposes only for cin when user needs to re-input data
public:
	Event(Currency z = nullCurrency, Spending_Cat a = nullSpending, double b = -1
		, string c = "", string d = "", Month e = nullMonth, int f = -1): 
		curr(z), type(a), amount (round(b)), title(c), note(d) {
			done = false;
			dt.setDate(e, f);
	}

	/*
	Getters & setters for Event class's private data members
	*/
	void changeDate(Month a, int b) {
		dt.setDate(a, b);
	}

	void changeSpendingType(Spending_Cat a) {
		type = a;
	}

	void changeCurrency(Currency c) {
		curr = c;
	}

	void changeAmount(double a) {
		amount = round(a);
	}

	void changeTitle(string a) {
		title = a;
	}

	void changeNote(string a) {
		note = a;
	}

	Date getDate() {
		return dt;
	}
	Spending_Cat getSpendingType() { 
		return type; 
	}
	double getAmount() {
		return amount;
	}
	string getTitle() {
		return title;
	}
	string getNote() {
		return note;
	}
	Currency getCurrency() {
		return curr;
	}


	/*
	Used for cin when user decides to re-enter data
	*/
	void clear() {
		dt.setDate(dt.getMonth(), -1);
		curr = curr;
		type = nullSpending;
		amount = -1;
		title = "";
		note = "";
		done = false;
	}

};



ostream & operator << (ostream &out, const Event &a) {
	const int largeWidth = 50;
	const int medWidth = 20;
	const int smallWidth = 10;
	
	out << "DATE: " << a.dt
		<< "|NAME: " << setw(medWidth) << left << a.title 
		<< "|AMOUNT: " << setw(smallWidth) << right 
		<< setprecision(numDigits(a.amount) + 2) << a.amount << a.curr
		<< "|TYPE: " << a.type 
		<< "|NOTE: " << setw(largeWidth) << left << a.note << endl;
	return out;
}

istream& operator>>(istream& in, Event& a) {
	/*
	Input loop continues until user declares their input is correct
	*/
	while (!a.done) {
		
		in >> a.dt;

		in >> a.type;
		while (a.type == nullSpending) {
			cout << "INVALID SPENDING TYPE INPUT, MUST BE AN INTEGER (1-3)" << endl;
			in >> a.type;
		}
	

		/*
		Uses stringstream for error handling when monetary amount input contains non-numbers
		*/
		string pseudoAmount;
		cout << "Please enter in a positive amount. Note decimal values are rounded to the nearest hundredth" 
			<< ", and input that begins with non-numbers are interpreted as 0" << endl;
		in >> pseudoAmount;
		stringstream first(pseudoAmount);
		double realAmount = 0;
		first >> realAmount;
		while (realAmount < 0) {
			realAmount = 0;
			cout << "INVALID AMOUNT INPUT, MUST BE A NONNEGATIVE AMOUNT (X > 0)" << endl;
			string innerAmount;
			in >> innerAmount;
			stringstream next(innerAmount);
			next >> realAmount;
		}
		a.amount = round(realAmount);


		cout << "Please enter in a title" << endl;
		in.ignore();
		getline(in, a.title);
		
		cout << "If needed, please enter in a note" << endl;
		getline(in, a.note);

		/*
		Uses a string for error handling when "done" input is not an integer
		*/
		string checkDone = "";
		cout << "Please confirm if all the inputted data is correct (1 for yes, 0 for no). " 
			<< "Pressing 0 will prompt you re-enter all data" << endl << endl;
		cout << a;
		in >> checkDone;
		while (!(checkDone == "0" || checkDone == "1")) {
			cout << "INVALID INPUT, MUST BE EITHER 1 OR 0" << endl;
			cout << "Please retry to reconfirm" << endl;
			in >> checkDone;
		}
		a.done = (checkDone == "1") ? true: false;
		
		if (!a.done) {
			a.clear();
			cout << endl << "Data cleared, re-trying event input..." << endl;
		}
	}

	return in;
}

#endif