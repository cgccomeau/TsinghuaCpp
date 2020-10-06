#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1;
	string s2;
	string s3;
	//char a[] = "";
	//char b[] = "";
	//cin << a;
	cout << "Please type in 2 strings" << endl;
	getline(cin, s1);
	getline(cin, s2);
	cout << s1 << s2 << endl;
	s3 = s1 += s2;
	cout << "Together, that string is: " << s3 << endl;
	return 0;
}