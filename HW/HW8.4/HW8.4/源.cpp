#include <iostream>
#include <string>
using namespace std;
class Med
{
public:
	virtual void print() =0;
	virtual string id() =0;
protected:
	string title;
};

class Book : Med
{
public:
	Book(string a="", string t="", string p="", string i="") : author(a), pub(p), isbn(i)   
        {
                title = t; 
        }
	void print()  
	{ 
		cout << title << " , Author: " << author << ", Publisher: " << pub << ".\n";  
	}
	string id()  
	{
		return isbn;
	}
private:
	string author, pub, isbn;
};

// 定义 Mag 类 和 CD 类，继承 Med 类
//@你的代码
class Mag: Med {
public:
	Mag(string b = "", string c = "", int d = 0, int e = 0):issn(c), volume(d), number(e) {
		title = b;
	}
	void print() {
		cout << title << " , Magazine: Vol. " << volume << ", No. " << number << ".\n";
	}
	string id() {
		return issn;
	}
private:
	string issn, pub;
	int volume, number;

};

class CD: Med {
public:
	CD(string a = "", string b = "", string c = "", string d = ""): composer(b), make(c), number(d) {
		title = a;
	}
	void print() {
		cout << title << " , CD composer: " << composer << ".\n";
	}
	string id() {
		return make + number;
	}
private:
	string composer, make, number;


};


int main()
{
	Book book("张三", "C++ 语言程序设计", "清华大学出版社", "0-000-00000-1");
	Mag mag("辨析C/C++编程模式", "0000-000X", 020, 01);
	CD cd("C++源代码", "清华大学计算中心", "ARCHIV", "000001");
	book.print();
	cout << "\tid: " << book.id() << endl;
	mag.print();
	cout << "\tid: " << mag.id() << endl;
	cd.print();
	cout << "\tid: " << cd.id() << endl;
	return 0;
}
