#include <iostream>
using namespace std;

int main() 
{
	int a, b;
	char opr;
	cout << "Please enter 2 integers";
	cin >> a >> b;
	cout << "Please enter an operator sign (+, -, *, -, or %)";
	cin >> opr;
	switch (opr) {
	case '+':
		cout << x + y << endl;
		break;
	case '-':
		cout << x - y << endl;
		break;
	case '*':
		cout << x * y << endl;
		break;
	case '/':
		cout << x / y << endl;
		break;
	case '%':
		cout << x % y << endl;
		break;
	}
	return 0;
}
