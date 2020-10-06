#include <iostream>
using namespace std;

class Account{
private:
	string id;
	double balance;
	static double total;
protected:
	Account (const string &id);
public:
	const string &getId() const { return id;}
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
};

class CreditAccount: public Account{
private:
	double credit;
	double rate;
	double fee;
	double getDebt() const;
public:
	CreditAccount (const string &id, double credit, double rate, double fee);
	double getCredit() const;
	double getRate() const;
	double getFee() const;
};

int main() {
	CreditAccount money("me", 100, 100, 100);
	cout << money.getBalance() << endl;

	return 0;
}