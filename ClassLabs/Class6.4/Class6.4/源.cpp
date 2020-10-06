#include <iostream>
using namespace std;

int main() {
	char a[100];
	char b[100];
	char c[200];

	cin.getline(a, 100);
	cin.getline(b, 100);

	int lengthA;
	int lengthB;

	for(int i = 0; i < 100; i++) {
		if (a[i] == 0) {
			lengthA = i;
			i = 101;
		}
		c[i] = a[i];
	}
	for(int i = 0; i < 100; i++) {
		if (b[i] == 0) {
			lengthB = i;
			i = 101;
		}
		c[i + lengthA] = b[i];
	}
	cout << c << endl;

	return 0;
}