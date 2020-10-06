#include <iostream>
using namespace std;

// converting Fahrenheit to Celsius

int main() {
	double fah;
	cout << "Please enter your temperature in Fahrenheit\n";
	cin >> fah;
	double cel = (fah - 32) * 5/9;
	cout << fah << " degrees Fahrenheit is " << cel << " degrees Celsius" << endl;
	return 0;
}