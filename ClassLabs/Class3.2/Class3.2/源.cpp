#include <iostream>
using namespace std;

int pow(int x, int y) {
	double val = 1.0;
	while (y--) {
		val *= x;
	}
	return val;
}

int main() {
	int base, exp, result;
	cout << "Please enter a base\n";
	cin >> base;
	cout << "Please enter an exponent \n";
	cin >> exp;
	result = pow(base, exp);
	cout << base << " ^ " << exp << " = " << result << endl;
	return 0;
}