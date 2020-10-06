#include <iostream>
using namespace std;

enum Flag { NORMAL, NAN, INF };

class Fraction
{
public:
	double convert( Flag & flag ) {
		double newNum = num;
		if (dem == 0 && num == 0) {
			flag = NAN;
		} else if (dem == 0) {
			flag = INF;
		} else {
			flag = NORMAL;
		}
		double mate = newNum / dem;
		if (mate == 0) {
			return 0;
		}
		return mate;
	}
	
	void assign(int a, int b) {
		if (a == 0 && b == 0) {
			num = a;
			dem = b;
		} else {
			int div = gcd(abs(a), abs(b));
			num = a / div;
			dem = b / div;
		}
		if (a == 0) {
			if (b > 0) {
				dem = 1;
			} else if (b < 0) {
				dem = -1;
			}
		} else if (b == 0) {
			if (a > 0) {
				num = 1;
			} else if (a < 0) {
				num = -1;
			}
		}

	}

	int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	void invert() {
		int temp = num;
		num = dem;
		dem = temp;
	}

	int abs(int a) {
		if (a < 0) {
			return -a;
		} else {
			return a;
		}
	}

	void print() {
		cout << num << "/" << dem;
	}
private:
	int num, dem;
};
int main()
{

	int num;    // 分子
    int den;    // 分母

    // 依次输入分子、分母
    cin >> num >> den;

    Fraction z;
    z.assign( num, den );
    cout << "z = ";
    z.print();
    Flag flag;
    double val = z.convert(flag);
    switch(flag)
    {
    case NORMAL:
        cout << " = " << val << endl;
        break;
    case NAN:
        cout << " = #NAN" << endl;
        break;
    case INF:
        cout << " = #INF" << endl;
        break;
    default:
        break;
    }

    z.invert();
    cout << "1/z = ";
    z.print();
    cout << endl;
    return 0;
}

 