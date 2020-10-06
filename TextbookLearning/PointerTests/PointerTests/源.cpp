#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
	void myMethod();
};

class A{
	public:
		static int a;
		void init() { a=1; }
		A(int a=2) { 
			init(); 
			a++; 
			cout << "inside a: " << a << endl;
		}
};

A obj;
int A::a=3;
A obj2[2]


int findOdd(int arr[], int n) 
{ 
    int res = 0, i;
    for (i = 0; i < n; i++) 
		res ^= arr[i];
    return res; 
} 

int funcA();
int funcB();

int main() {
	string food = "Pizza";
	string &meal = food;
	string* ptr = &food;

	cout << "food: " << food << endl;
	cout << "&food: " << &food << endl;
	cout << "&meal: "<< &meal << endl;
	cout << "meal: " << meal << endl;
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl << endl;

	*ptr = "Hamburgerrrrrr";
	cout << "Changing pizza to hamburger" << endl << endl;
	cout << "food: " << food << endl;
	cout << "&food: " << &food << endl;
	cout << "&meal: "<< &meal << endl;
	cout << "meal: " << meal << endl;
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl << endl;

	meal = "idk";
	cout << "food: " << food << endl;
	cout << "&food: " << &food << endl;
	cout << "&meal: "<< &meal << endl;
	cout << "meal: " << meal << endl;
	cout << "ptr: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl << endl;

	MyClass m;
	m.myMethod();

	unsigned char b = 9;
	printf("b << 1 = %d\n", b << 1);
	printf("b << 2 = %d\n", b << 2);
	printf("b >> 1 = %d\n", b >> 1);
	printf("b >> 2 = %d\n", b >> 2);
	cout << b << endl;
	printf("~b = %d\n", b = ~b);

	int arr[] = { 12, 12, 14, 1, 14, 14, 14 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
    printf("\nThe odd occurring element is %d \n", 
           findOdd(arr, n));  

	int arr2[] = {12, 13, 14, 13, 12};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	for (int i = 0; i < n2; i++) {
		cout << arr2[i] << " ";
	}
	printf("\nThe odd occurring element is %d \n", 
           findOdd(arr2, n2));  

	int a = (int) 10.9;
	cout << a << endl;
	cout << funcA() << endl;
	cout << "outside obj.a: " << obj.a << endl;
	cout << "outside obj2.a: " << obj2.a << endl;
	return 0;
}

void MyClass::myMethod() {
	cout << "Stinky butt" << endl;
}

int funcA() {
	return funcB();
	int a = 1;
}

int funcB() {
	return 1;
}