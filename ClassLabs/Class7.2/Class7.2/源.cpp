#include <iostream>
using namespace std;

class BaseClass {
public:
	int number;
	BaseClass(int i) {
		cout << "BaseClass constructor called" << endl;
		number = i;
	}
	~BaseClass() {
		cout << "BaseClass destructor called" << endl;
	}
};

class DerivedClass: public BaseClass {
public:
	DerivedClass(int i): BaseClass(i) {
		cout << "DerivedClass constructor called" << endl;
	}
	~DerivedClass() {
		cout << "DerivedClass destructor called" << endl;
	}
};



int main() {
	DerivedClass b(4);

	return 0;
}