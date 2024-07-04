#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <sstream>

using namespace std;
class Networks {
protected:
	string btcadress;
	string trcadress;
	string ethadress;

	string getraandomdigits() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<>dis(0, 15);
		const char hexChars[] = "123456789ABCDEF";
		return string(1, hexChars[dis(gen)]);
	}
	string getrandombtcadress() {
		stringstream ss;
		ss << "1KN";
		for (int i = 0; i < 40; i++)
		{
			ss << getraandomdigits();
		}
		return ss.str();
	}
	string getrandomethadress() {
		stringstream ss;
		ss << "0x";
		for (int i = 0; i < 40; i++)
		{
			ss << getraandomdigits();
		}
		return ss.str();
	}
	string getrandomtrcadress() {
		stringstream ss;
		ss << "TJW";
		for (int i = 0; i < 40; i++)
		{
			ss << getraandomdigits();
		}
		return ss.str();
	}


public:
	Networks() : btcadress(getrandombtcadress()), trcadress(getrandomtrcadress()), ethadress(getrandomethadress()) {}
	void displayAddresses() const {
		cout << "BTC Address: " << btcadress << std::endl;
		cout << "TRX Address: " << trcadress << std::endl;
		cout << "ETH Address: " << ethadress << std::endl;
	}
	string getbtcadress() const {
		return btcadress;
	}
	string gettrcadress() const {
		return trcadress;
	}
	string getethadress() {
		return ethadress;
	}
};


