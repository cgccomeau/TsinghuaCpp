#include <iostream>
using namespace std;

int main() 
{
	int x, y;
	char opr;
	cin >> x >> y >> opr;
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
