#include <iostream>
#include <cassert>
using namespace std;

class Point{
public:
	Point(int x = 0, int y = 0): x(x), y(y) {
		count++;
		cout << "Default constructor called" << endl;
	}
	Point(const Point &p): x(p.x), y(p.y) {
		count++;
		cout << "Copy constructor called" << endl;
	}
	~Point() { 
		count--;
		cout << "Destructor called" << endl;
	}
	int getX() const { return x;}
	int getY() const { return y;}
	//static int count;
	static void showCount() {
		cout << " Object count = " << count << endl;
	}
	void move(int newX, int newY) {
		x = newX;
		y = newY;
	}


private:
	int x, y;
	static int count;
};

class ArrayOfPoints {
public:
	ArrayOfPoints(int size): size(size) {
		points = new Point[size];
	}
	ArrayOfPoints(const ArrayOfPoints &v);
	~ArrayOfPoints() {
		cout << "Deleting..." << endl;
		delete[] points;
	}
	Point &element(int index) {
		assert(index >= 0 && index < size);
		return points[index];
	}
private:
	Point * points;
	int size;
};

ArrayOfPoints::ArrayOfPoints(const ArrayOfPoints &v) {
	size = v.size;
	points = new Point[size];
	for(int i = 0; i < size; i++) {
		points[i] = v.points[i];
	}
}

int Point:: count = 0;

int main() {
	//int * ptr = &Point::count;
	void (* ptr)() = Point::showCount;
	Point a(4, 5);
	cout << "Point A: " << a.getX() << ", " << a.getY();
	ptr();
	//cout << " Object count = " << *ptr << endl;

	Point b(a);
	cout << "Point B: " << b.getX() << ", " << b.getY();
	ptr();

	//cout << " Object count = " << *ptr << endl;

	int * p = new int[10];
	for(int i = 0; i < 10; i++) {
		cout << p[i]<< " ";
	}
	cout << endl;
	int * q = new int[10]();
	for(int i = 0; i < 10; i++) {
		cout << q[i]<< " ";
	}
	cout << endl;

	Point * PointPtr = new Point[2];
	for(int i = 0; i < 2; i++) {
		cout << PointPtr[i].getX()<< " ";
		cout << PointPtr[i].getY()<< " " << endl;
	}
	ptr();
	delete[] PointPtr;
	cout << "Array deletion done" << endl;
	ptr();

	//int arraycount;
	//cout << "Please enter the count of points: " << endl;
	//cin >> arraycount;
	//ArrayOfPoints points(arraycount);
	//points.element(0).move(5,0);
	//points.element(1).move(15, 20);

	float(* cp)[9][8]= new float[8][9][8];

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 9; j++) {
			for (int k = 0; k < 8; k++) {
				* ( * ( * (cp + i) + j ) + k) = static_cast<float>(i * 100 + j * 10 + k);
				cout << cp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << (cp + 0) << endl;
	cout << * ( * ( *(cp + 1) + 1) + 1);

	delete[]cp;

	ArrayOfPoints pointsArray1(2);
	pointsArray1.element(0).move(5, 10);
	pointsArray1.element(1).move(15, 20);
	ArrayOfPoints pointsArray2 = pointsArray1;
	cout << "Copy of pointsArray1: " << endl;
	cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "<< pointsArray2.element(0).getY() << endl;
	cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "<< pointsArray2.element(1).getY() << endl;

	pointsArray1.element(0).move(25, 30);
	pointsArray1.element(1).move(35, 40);
	cout << "After the moving of pointsArray1: " << endl;

	cout << "Point_0 of array2: " << pointsArray2.element(0).getX() << ", "<< pointsArray2.element(0).getY() << endl;
	cout << "Point_1 of array2: " << pointsArray2.element(1).getX() << ", "<< pointsArray2.element(1).getY() << endl;

	const char * STRING1 = "This is a string.";
	cout << STRING1<< endl;

	char str[8] = {'p','r','o','g','r','a','m','\0'};
	cout << str << endl;
	for (int i = 0; i < 8; i++) {
		cout << str[i] << " ";
	}
	char w[4]="abc";
	char *w1;
	w1 = w;
	cin >> w1;

	cout << str[7] << endl;
	return 0;
}