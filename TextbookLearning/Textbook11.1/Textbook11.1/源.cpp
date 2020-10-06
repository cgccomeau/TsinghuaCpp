#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
	double values[] = {1.23, 35.36, 653.7, 435118.24};
	string names[] = {"zoo", "jimmy", "al", "stan"};
	//cout.fill('a');
	for(int i = 0; i < 4; i++) {
		//cout.width(10);
		//cout << values[i] << endl;
		cout << setiosflags(ios_base::left) 
			<< setw(6) << names[i] 
		<< resetiosflags(ios_base::fixed) 
			<< setw(11) << values[i] << endl;
	}
	int array[2] = {99, 10};
	ofstream os("test.dat", ios_base::out|ios_base::binary);
	os.write(reinterpret_cast<char*>(array), sizeof(array));

	char ch;
	while ((ch = cin.get()) != EOF)
		cout.put(ch);


	return 0;
}