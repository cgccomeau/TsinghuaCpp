#include <iostream>
#include <new>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void transpose(int **p) {
	/*for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            int temp = *(p + i * 3 + j);
            *(p + i * 3 + j) = *(p + j * 3 + i);
            *(p + j * 3 + i) = temp;
        }
    }*/
	for(int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++) {
			int temp = *(p[i] + j);
			*(p[i] + j) = *(p[j] + i);
			*(p[j] + i) = temp;
		}
	}


}

int main() {
	int matrix[3][3];
	int *p = &matrix[0][0];

	int **ptr = new int*[3];
	for (int i = 0; i < 3; i++) {
		ptr[i] = new int[3];
		ptr[i] = matrix[i];
	}
	

	cout << "Please input 9 numbers" << endl;
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "This is your current matrix (before transposition) and addresses" << endl;
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << ": " << &matrix[i][j] << " ";
		}
		cout << endl;
	}
	transpose(ptr);

	cout << "This is your current matrix (after transposition) and addresses" << endl;
	for(int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j]; // << ": " << &matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}