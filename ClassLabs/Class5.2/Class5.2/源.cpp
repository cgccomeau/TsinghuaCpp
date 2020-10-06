#include <iostream>
using namespace std;

#include "client.h"

int Client::ClientNum = 0;
char Client::ServerName = 'a';

int main() {
	cout << "Initial Client count: " << Client::getClientNum() << endl;
	Client a('a');
	Client b('a');
	cout << "ServerName before calling ChangeServerName(): " << Client::getClientName() << endl;
	a.ChangeServerName('b');
	cout << "Changing server name from a to b..." << endl;
	cout << "ServerName after calling ChangeServerName(): " << Client::getClientName() << endl;
	cout << "Final Client count: " << Client::getClientNum() << endl;
	return 0;
}