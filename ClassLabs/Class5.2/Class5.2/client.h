#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>

class Client {
private:
	static int ClientNum;
	static char ServerName;
public:
	Client(char name) {
		cout << "constructor called" << endl;
		ServerName = name;
		ClientNum++;
	}

	static void ChangeServerName(char name) {
		ServerName = name;
	}
	static int getClientNum() {
		return ClientNum;
	}
	static char getClientName() {
		return ServerName;
	}
};

#endif