#include <iostream>
using namespace std;

bool isTriangular( int n )
{
	int square = 8*n + 1;
	for (int i = 0; i <= 2*n + 1; i++)
		if (i*i == square) 
			return true;
	
	return false; 
	
}

int main() {
	int min_val, max_val;  
    cin >> min_val >> max_val;
    if( min_val > max_val )
    {
        int x = min_val; min_val = max_val; max_val = x;
    }
 
    for( int i = max( 0, min_val ); i <= max_val; ++i ) {
        if( isTriangular(i) )
            cout << i << " is a triangular number." << endl;
	}
	return 0;
}