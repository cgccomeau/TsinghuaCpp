#include <iostream>
using namespace std;

class Vehicle {
private:
	int maxSpeed;
	int weight;
public:
	Vehicle(int a, int b) {
		maxSpeed = a;
		weight = b;
		cout << "Vehicle has been constructed" << endl;
	}
	~Vehicle() {
		cout << "Vehicle has been destructed" << endl;
	}
	void setMaxSpeed(int a) {
		maxSpeed = a;
	}
	void setWeight(int a) {
		weight = a;
	}
	int getMaxSpeed() {
		return maxSpeed;
	}
	int getWeight() {
		return weight;
	}
	void Run() {
		cout << "Vehicle is running!" << endl;
	}
	void Stop() {
		cout << "Vehicle has stopped." << endl;
	}
};

class Bicycle: virtual public Vehicle {
private:
	int height;
public:
	Bicycle(int a, int b, int c): Vehicle(a, b) {
		height = c;
		cout << "Bike has been constructed" << endl;
	}
	~Bicycle() {
		cout << "Bicycle has been destructed" << endl;
	}
	void setHeight(int a) {
		height = a;
	}
	int getHeight() {
		return height;
	}
};

class Motorcar: virtual public Vehicle {
private:
	int seatNum;
public:
	Motorcar(int a, int b, int c): Vehicle(a, b) {
		seatNum = c;
		cout << "Motorcar has been constructed" << endl;
	}
	~Motorcar() {
		cout << "Motorcar has been destructed" << endl;
	}
	void setseatNum(int a) {
		seatNum = a;
	}
	int getseatNum() {
		return seatNum;
	}
};

class Motorcycle: public Motorcar, public Bicycle {
public:
	Motorcycle(int a, int b, int c): Vehicle(a, b), Motorcar(a, b, c), Bicycle(a, b, c) {
		cout << "Motorcycle has been constructed" << endl;
	}
	~Motorcycle() {
		cout << "Motorcycle has been destructed" << endl;
	}
};


int main() {
	Motorcycle a(1, 2, 3);

	//cout << "Height: " << a.getHeight() << endl;
	//cout << "MaxSpeed: " << a.getMaxSpeed() << endl;
	//cout << "SeatNum: " << a.getseatNum() << endl;
	//cout << "Weight: " << a.getWeight << endl;
	return 0;
}