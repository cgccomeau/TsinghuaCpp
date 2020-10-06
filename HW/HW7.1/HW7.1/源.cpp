#include <iostream>
#include <string.h>
using namespace std;

class Person
{
char *Name;
public:
	//Person(){};
	Person( char *name );
	void PrintName();
};
Person::Person( char *name )
{
	Name = name;
}
void Person::PrintName()
{
	cout << "Name of Student: ";
	int i = 0;
	while (*(Name + i) != '\0') {
		cout << *(Name + i);
		i++;
	}
	cout << endl;
	//*Name << endl;
}
class Student : public Person
{
public:
	Student( char *name, long number );
	void PrintInfo();
private:
	long Number;
};

Student::Student(char* name, long number): Person(name) {
	Number = number; 
}

void Student::PrintInfo()
{
	Person::PrintName();
	cout << "Number of Student: " << Number << endl;
}

int main()
{
	Student b("ssh",100);
	b.PrintInfo();
	return 0;
}