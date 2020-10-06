#include <iostream>
using namespace std;
float* Map(float* p[], int n)
{
	if (n == 0) {
		return NULL;
	} else if(n == 1) {
		return p[0];
	} else {
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			int swap = *p[i];
			*p[i] = *p[j];
			*p[j] = swap;
		}
		return p[0];
	}
}
 
void Disp(float a[], int n)
{
     for (int i = 0; i < n; i++)
         cout << a[i] << " ";
     cout << endl;
}
 
void Disp(float* a[], int n)
{
     for (int i = 0; i < n; i++)
         cout << *a[i] << " ";
     cout << endl;
}
 
 
 
int main()
{
    
     int n;
     cin >> n;
     float* a = new float[n];
     for(int i = 0; i < n; i++)
         cin >> a[i];
     Disp(a, n);
     float** p = new float* [n];
     for (int i = 0; i < n; i++)
         p[i] = &a[i]; 
     Disp(p, n);
     float* const b = Map(p, n);
     Disp(b, n);
	 
	 //cout << "helloooooo" << *p[0]<< endl;

     return 0;
}