#include <iostream>
using namespace std;

#include "employee.h"

int main() {
	Employee e("me", "home", "beijing", 000);
	e.display();
	e.change_Name("you");
	e.display();

	Employee a[5];
	for (int i = 0; i < 5; i++) {
		a[i].display();
	}
	return 0;
}