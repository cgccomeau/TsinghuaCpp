#include <iostream>
using namespace std;

class Point {
public:
	Point(int a, int b): x(a), y(b){}
	int getX() const { return x; }
	int getY() const { return y; }
	Point& operator++() {
		x++;
		y++;
		return *this;
	}
	Point& operator--() {
		y--;
		x--;
		return *this;
	}
	Point operator ++(int) {
		Point old = * this;
		++(* this);
		return old;
	}
	Point operator --(int) {
		Point old = * this;
		--(* this);
		return old;
	}
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
private:
	int x, y;
};

int main() {
	Point p(0,0);
	p.print();
	++p;
	p.print();
	p++;
	p.print();
	p--;
	p.print();
	--p;
	p.print();
	return 0;
}