#include <math.h>    
#include <iomanip>  
#include <iostream>
using namespace std;
double SolveRoot(double (*pf)(double t), double a, double b, int n)
{  
	double mid = (a + b) / 2;
	if (n == 1) {
		return mid;
	}
	if (pf(mid) < 0) {
		return SolveRoot(pf, mid, b, --n);
	} else {
		return SolveRoot(pf, a, mid, --n);
	}
	return mid;
}
 
double f(double x)
{
     return x*x - 2;
}
 
 
int main()
{
     cout << setprecision(10); 
     for (int n=1; n<10; n+=1)
         cout << "SolveRoot(f,1,2," << n << ") = " <<setprecision(10)<< SolveRoot(f,1,2,n) << endl;
     cout << "The exact SolveRoot = " <<setprecision(10)<<sqrt((double)2) << endl;

     return 0;
}