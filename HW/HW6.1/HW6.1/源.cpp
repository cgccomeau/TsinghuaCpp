#include <cassert>
#include <iostream>
using namespace std;

void Disp(int a[], int n)
{
	for (int i=0; i<n-1; i++)
		cout << a[i] << ", ";
	cout << a[n-1] << endl;
}

void Add(int a[], int m, int b[], int n)
{
	for (int i = m, j = 0; i < m + n && j < n; i++, j++) {
		a[i] = b[j];
	}
}

int main()
{
	int* a = NULL;
	int* b = NULL;
	int i = 0;
	int m, n;
	cin >> m >> n;
	a = new int[m + n];
	b = new int[n];
	for(i = 0; i < m; i++)
		cin >> a[i];
	for(i = 0; i < n; i++)
		cin >> b[i];

	int m1, n1;
	cin >> m1 >> n1;

	Add(a, m1, b, n1);
	int max = 0;
	if (m1 + n1 > m) {
		max = m1 + n1;
	} else {
		max = m;
	}
	Disp(a, max);

	return 0;
}