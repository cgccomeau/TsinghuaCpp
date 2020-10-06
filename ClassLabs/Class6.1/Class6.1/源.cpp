#include <iostream>
using namespace std;

int main() {
	int matrix[3][3];
	cout << "Please input 9 numbers" << endl;
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "This is your current matrix (before transposition)" << endl;
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "This is your matrix after transposition" << endl;
	for (int i = 0; i < 2; i++) {
		for(int j = 1; j <=2; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix [j][i];
			matrix[j][i] = temp;
		}
	}
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}