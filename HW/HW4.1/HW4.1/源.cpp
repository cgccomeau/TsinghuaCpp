#include <iostream>
#include <cmath>
using namespace std;


class Point
{
private:
	int x, y, z;
public:
	Point(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
	Point(const Point & old) {
		x = old.x;
		y = old.y;
		z = old.z;
	}

	~Point() {
		cout << "Stick them with the pointy end"; 
	}

	void negate() {
		x = -x;
		y = -y;
		z = -z;
	}

	double dist() {
		return pow(x*x + y*y + z*z, 0.5);
	}

	void print() const {
		cout << "(" << x << ", " << y << ", " << z << ")";
	}

};


int main()
{
    int x, y, z;     
	cin >> x >> y >> z;
	Point p( x, y, z );
    cout << "p = ";
    p.print();
    cout << ", p.dist() = " << p.dist() << endl;
	p.negate();
	cout << "p = ";
    p.print();
    cout << ", p.dist() = " << p.dist() << endl;
	return 0;
}