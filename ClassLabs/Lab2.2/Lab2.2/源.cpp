#include <iostream>
using namespace std;

int main() {
	char answer;
	int a;
	int b;
	double area = 0;
	double r;
	cout << "Do you have a square, rectangle, or a circle? s for square, r for rectangle, c for circle\n";
	cin >> answer;
	switch (answer) {
	case 's':
		cout << "Please input the length of one side\n";
		cin >> a;
		area = a * a;
		break;
	case 'r':
		cout << "Please input the length and width of the rectangle\n";
		cin >> a;
		cin >> b;
		area = a * b;
		break;
	case 'c':
		cout << "Please input the length of the radius\n";
		cin >> r;
		area = r * r * 3.14;
		break;
	default: 
		cout << "That's not possible!\n";
	}

	cout << "The area is " << area << endl;
	return 0;
}