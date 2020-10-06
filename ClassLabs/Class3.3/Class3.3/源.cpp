#include <iostream>
using namespace std;

inline int fibonacci(int n) {
	return (n <= 1) ? 1: fibonacci(n - 1) + fibonacci(n-2);
}

int main() {
	int n;
	cout << "Please enter the desired Fibonacci number\n";
	cin >> n;
	while (n >= 0) {
		cout << "Fibonacci(" << n << "): " << fibonacci(n) << endl;
		n--;
	}
	return 0;
}