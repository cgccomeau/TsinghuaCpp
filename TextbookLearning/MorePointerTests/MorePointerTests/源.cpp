#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass *a;
	MyClass(){ 
		cout << 1 << endl; 
	}
};

int fun1(int x) { return ++x; }
int fun2(int &x) { return ++x; }

/*class A {
public:
	static int test;
	void fun()
	{
		test = 1;
	}
	A(int test = 0)
	{
		fun();
		test++;
	}
};

A a;
int A::test = 3;*/

class A
{
public:
	int a;
	A(int b = 0){cout << 1;a = b;}
	A(const A &rhs){cout << 2;}
	~A(){cout << 3;}
};

class Z {};

void swap(int &x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {
	//MyClass a, b[2], *P[2], *A[4];
	//MyClass a;
	//MyClass b[2];
	//MyClass A[4];

	/*int x=1, y=2;
	y = fun1( fun2(x) );
	cout << x << ',' << y;*/

	int u = 3, w= 2, x = 1; 
	bool y = true, z = false;
	x = (w & x) && (z || y) ;
	y = (z || (x | u) );
	z = !x && y;
	cout << "xyz: " << x << y << z << endl;
	cout << !x << endl;
	cout << !w << endl;
	cout << !u << endl;
	cout << "true: " << true << endl;
	cout << "false: " << false << endl;

	//cout << a.test << ' ';
	//A c;
	//cout << c.test;

	A a(4), b(a);
	b = a;
	cout << a.a << b.a;

	//Z z();
	int p = 10;
	int q = 20;

	cout << "p, q:" << p << q << endl;
	swap(p,q);
	cout << "p, q:" << p << q << endl;
	//int &z = 3; illegal 
	return 0;
}