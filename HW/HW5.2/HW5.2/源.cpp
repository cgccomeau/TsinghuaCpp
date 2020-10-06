#include <iostream>
using namespace std;

class Width {
private:
	static int num;
public:
	static int numWidths() {
		return num;
	}
	Width() {
		num++;
	}
	~Width() {
		num--;
	}
};

int Width::num = 0;

int main( int argc, char * argv[] )
{
    Width w, x;
    cout << "#objects = " << w.numWidths() << endl;
    {
        Width w, x, y, z;
        cout << "#objects = " << w.numWidths() << endl;
    }
    cout << "#objects = " << w.numWidths() << endl;
    Width y;
    cout << "#objects = " << w.numWidths() << endl;
	return 0;
}