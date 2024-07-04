#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include "Networks.h"

class User : public Networks{
private:
	string nickname;
	Networks adresses;
	
public:
	User() : nickname(),adresses(){}
	void setnickname(const string& nick)  {
		nickname = nick;
		
	}
	string getnickname() const {
		return nickname;
	}
	void displayadresses() const {
		cout << "User: " << nickname << endl;
		adresses.displayAddresses();
	}
	
};