#include <iostream>
using namespace std;

class CPU {
private:
	int a;
public:
	CPU(int b = 0) { 
		a = b;
		cout << "CPU created!" << endl; }
	~CPU() { cout << "CPU destructed" << endl; }
	void getA() { cout << a << endl;}
};

class RAM {
private:
	int a;
public:
	RAM(int b = 0) { 
		a = b;
		cout << "RAM created!" << endl; }
	~RAM() { cout << "RAM destructed" << endl; }
};

class CDROM {
private:
	int a;
public:
	CDROM(int b = 0) { 
		a = b;
		cout << "CDROM created!" << endl; }
	~CDROM() { cout << "CDROM destructed" << endl; }
};

class Computer {
private:
	CPU cpu;
	RAM ram;
	CDROM cdrom;
public:
	Computer(CPU cp, RAM r, CDROM cd) {
		cpu = cp;
		ram = r;
		cdrom = cd;
		cout << "computer created!" << endl;
	}
	~Computer() { cout << "computer destructed" << endl; }

	CPU getCPU() const { return cpu; }
	RAM getRAM() const { return ram; }
	CDROM getCDROM() const { return cdrom; }
	void setCPU(CPU a) { cpu = a; }
	void setRAM(RAM a) { ram = a; }
	void setCDROM(CDROM a) { cdrom = a; }
	void Run() { cout << "Computer running" << endl; }
	void Stop() { cout << "Computer stopped" << endl; }
};

int main() {
	//CPU a(0);
	//RAM b(0);
	//CDROM c(0);
	//a.getA();
	Computer apple(CPU(0), RAM(0), CDROM(0));
	apple.Run();
	apple.Stop();
	return 0;
}