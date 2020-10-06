#include <iostream>
using namespace std;

void rowSum(int a[][4], int nRow) {
	for (int i = 0; i < nRow; i++) {
		for (int j = 1; j < 4; j++) {
			a[i][0] += a[i][j];
		}
	}
}

void splitFloat(float x, int * intPart, float * fracPart) {
	* intPart = static_cast<int>(x);
	* fracPart = x - * intPart;
}

int main() {
	int table[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	rowSum(table, 3);
	for (int i = 0; i < 3; i++) {
		cout << "Sum of row " << i << " is " << table[i][0] << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(table[i] + j) << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(*(table + i) + j) << " ";
		}
		cout << endl;
	}

	unsigned short a, b;
	//int * const p2 = &a;
	a = 3, b = 5;
	cout << (a ^ b) << endl;

	int n;
	float f;
	splitFloat(4.7, &n, &f);

	cout << "Integer part n = " << n << " Fraction Part = " << f << endl;

	return 0;
}