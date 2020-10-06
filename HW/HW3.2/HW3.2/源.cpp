#include <iostream>
#include <iomanip>
using namespace std;

int calc_comb( int n, int k )
{
	int result = 1;
	int div = n - k;

	for (int i = n; i >=1; i--) {
		result *= i;
	}
	
	for (int i = k, j = div; i >=1 || j >= 1; i--, j--) {
		if (i >= 1) {
			result /= i;
		}
		if (j >= 1) {
			result /= j;
		}
	}

	return result;
}

void print_pascal_triangle( int n )
{
	for( int i = 0; i <= n; ++i )
	{
		int start_pos = n - i;
		for( int j = 0; j < start_pos; ++j )
			cout << setw(3) << " ";

		for( int j = 0; j <= i; ++j )
		{
			cout << setw(3) << calc_comb( i, j ) << setw(3) << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	print_pascal_triangle( n );
	return 0;
}