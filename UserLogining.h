#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Networks.h"
#include "User.h"

class Userreglog {
private:
	vector<pair<string, string>> users;

	void saveToFile(const string& login, const string& password) const {
		ofstream outfile("users.txt", ios_base::app);
		if (outfile.is_open()) {
			outfile << login << " " << password << "\n"; 
			outfile.close();
		}
		else {
			cerr << "Unable to open users file.";
		}
	}

	void loadFromFile() {
		ifstream infile("users.txt");
		if (infile.is_open()) {
			string login, password;
			while (infile >> login >> password) {
				users.emplace_back(login, password);
			}
			infile.close();
		}
		else {
			cerr << "Cannot open file!";
		}
	}
public:
	Userreglog() {
		loadFromFile();
	}

	void registerUser(const string& login, const string& password1, const string& password2) {
		if (password1 != password2) {
			cerr << "Passwords didn't match!" << endl; 
			return; 
		}

		for (const auto& user : users) {
			if (user.first == login) {
				cerr << "User with this nickname already exists!" << endl;
				return; 
			}
		}

		users.emplace_back(login, password1);
		saveToFile(login, password1);
		cout << "\nUser Registered Successfully" << endl;
	}

	bool loginUser(const string& login, const string& password) const {
		for (const auto& user : users) {
			if (user.first == login && user.second == password) {
				cout << "Login Successful" << endl;
				return true;
			}
		}
		cerr << "Invalid login or password" << endl;
		return false;
	}
	void menureglog()const{
		cout << "\n============================" << endl;
		cout << "        WEB3 WALLET         " << endl;
		cout << "============================" <<endl;
		cout << "1. Register" << endl;
		cout << "2. Login" << "\n\n";
		cout << "3. Exit" << endl;
		cout << "============================" << endl;
	}
};