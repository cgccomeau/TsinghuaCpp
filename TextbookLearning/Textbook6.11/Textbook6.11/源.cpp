#include <iostream>
using namespace std;

void printStuff(float) {
	cout << "This is the print stuff function." << endl;
}

void printMessage(float data) {
	cout << "The data to be listed is " << data << endl;
}

void printFloat(float data) {
	cout << "The data to be printed is " << data << endl;
}

const float PI = 3.14159f;
const float TWO_PI = PI * 2.0f;

class Line;

class Point {
public:
	Line *l;
	Point (int x = 0, int y = 0): x(x), y(y) {}
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int x1) { x = x1; }
	void setY(int y1) { y = y1; }
	void print() {
		cout << x << " " << y << endl;
	}
private:
	int x, y;
};

class Line {
	Point p;
};

int main() {
	void (*functionPointer)(float);
	printStuff(PI);
	functionPointer = printStuff;
	functionPointer(PI);
	functionPointer = printMessage;
	functionPointer(TWO_PI);
	functionPointer(13.0);
	functionPointer = printFloat;
	functionPointer(PI);
	functionPointer(TWO_PI);
	cout << endl;

	Point a(4, 5);
	Point * p1 = &a;
	cout << p1 -> getX() << endl;
	cout << a.getX() << endl;
	cout << p1 -> getY() << endl;
	cout << a.getY() << endl << endl;

	int (Point:: * funcPtr) () const = &Point::getX;
	cout << (a.* funcPtr)() << endl;
	cout << (p1 ->*funcPtr)() << endl << endl;

	Point z[5], y[5];

	void (Point:: * XPtr)(int) = &Point::setX;
	void (Point:: * YPtr)(int) = &Point::setY;
	void (Point:: * PrintPtr)() = &Point::print;

	for (int i = 0; i < 5; i++) {
		(z[i].* XPtr)(i);
		(z[i].* YPtr)(5 - i);
		(z[i].* PrintPtr)();
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		Point * p10 = &y[i];
		(p1 ->* XPtr)(5 - i);
		(p1 ->* YPtr)(i);
		(p1 ->* PrintPtr)();
	}


	return 0;
}