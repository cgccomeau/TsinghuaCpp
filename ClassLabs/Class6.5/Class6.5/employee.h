#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <iostream>


class Employee {
private:
	string name;
	string street_address;
	string city;
	int zipcode;
public:
	Employee(string n, string s, string c, int z) {
		name = n;
		street_address = s;
		city = c;
		zipcode = z;
	}

	Employee() {
		name = "";
		street_address = "";
		city = "";
		zipcode = 0;
	}

	void display() {
		cout << "name:" << name << endl;
		cout << "street address:" << street_address << endl;
		cout << "city:" << city << endl;
		cout << "zipcode:" << zipcode << "\n" <<endl;
	}

	void change_Name(string n) {
		name = n;
	}




};

#endif