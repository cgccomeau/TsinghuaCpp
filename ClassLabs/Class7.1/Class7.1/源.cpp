#include <iostream>
using namespace std;

class Animal {
public:
	int age;
};

class Dog: public Animal {
public:
	void setAge(int n) {
		age = n;
	}
};

int main() {
	Dog a;
	a.setAge(4);
	cout << a.age;
	return 0;
}