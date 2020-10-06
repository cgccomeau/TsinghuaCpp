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
	virtual void Run() {
		cout << "Vehicle is running!" << endl;
	}
	virtual void Stop() {
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
	virtual void Run() {
		cout << "Bicyle is running!" << endl;
	}
	virtual void Stop() {
		cout << "Bicyle has stopped." << endl;
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
	virtual void Run() {
		cout << "Motorcar is running!" << endl;
	}
	virtual void Stop() {
		cout << "Motocar has stopped." << endl;
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
	virtual void Run() {
		cout << "Motorcycle is running!" << endl;
	}
	virtual void Stop() {
		cout << "Motorcycle has stopped." << endl;
	}
};


int main() {
	Vehicle *d = new Vehicle(1,2);
	Vehicle *c = new Bicycle(1, 2, 3);
	Vehicle *b = new Motorcar(1, 2, 3);
	Vehicle *a = new Motorcycle(1, 2, 3);

	cout << "Vehicle call run & stop " << endl;
	d->Run();
	d->Stop();
	cout << endl << "Bicycle call run & stop " << endl;
	c->Run();
	c->Stop();
	cout << endl << "Motorcar call run & stop " << endl;
	b->Run();
	b->Stop();
	cout << endl << "Motorcycle call run & stop " << endl;
	a->Run();
	a->Stop();

	return 0;
}