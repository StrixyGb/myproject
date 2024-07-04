#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include "Networks.h"
#include "User.h"
#include "UserLogining.h"
class Wallet : public Networks , User{
protected:
	
	double btcbalance;
	double trcbalance;
	double ethbalance;
	double totalbalance;
	double btcrate = 60918.01;
	double usdtrate = 0.9986;
	double ethrate = 3365.35;

	void logtransaction(const string& transaction) {
		ofstream outfile("transaction.txt", ios_base::app);
		if (outfile.is_open())
		{
			outfile << transaction << endl;
			outfile.close();
		}
		else
		{
			cerr << "Unaable to register a transaction!";
		}
	} 

	
public:
	Wallet() : btcbalance(0), trcbalance(0), ethbalance(0), totalbalance(0) {}
	void displayTransactionHistory() {
		ifstream infile("transaction.txt");
		if (infile.is_open()) {
			cout << "\n\n\tTransaction History (Last 4 transactions):\n\n";
			string line;
			vector<string> transactions;
			while (getline(infile, line)) {
				transactions.push_back(line);
			}
			infile.close();
			int start_index = max(0, static_cast<int>(transactions.size()) - 4);
			for (int i = start_index; i < transactions.size(); ++i) {
				cout << "\t" << transactions[i] << endl;
			}
			cout << "\n\n\tPress any key and enter to view all transactions...";
			cin.ignore();
			cin.get();  
			infile.open("transaction.txt");
			if (infile.is_open()) {
				cout << "\n\n\tAll Transactions:\n\n";
				while (getline(infile, line)) {
					cout << "\t" << line << endl;
				}
				infile.close();
			}
			else {
				cerr << "Unable to open transaction history file." << endl;
			}
		}
		else {
			cerr << "Unable to open transaction history file." << endl;
		}
	}
	void exchangeUSDTtoBTC(int amountUSDT) {
		if (trcbalance >= amountUSDT) {
			
			double btcAmount = amountUSDT * 0.000016; 
			trcbalance -= amountUSDT;
			btcbalance += btcAmount;   
			cout << "Successfully exchanged " << amountUSDT << " USDT to " << btcAmount << " BTC\n";
			logtransaction("Successfully exchanged USDT to BTC: " + to_string(amountUSDT) + "USDT" + "ON" + to_string(btcAmount) + "BTC");
		}
		else {
			cerr << "Insufficient USDT balance for exchange\n";
			logtransaction("Insufficient USDT balance for exchange BTC");
		}
	}
	void exchangeUSDTtoETH(int amountUSDT) {
		if (trcbalance >= amountUSDT) {

			double ethAmount = amountUSDT * 0.00029;
			trcbalance -= amountUSDT;
			ethbalance += ethAmount;
			cout << "Successfully exchanged " << amountUSDT << " USDT to " << ethAmount << " BTC\n";
			logtransaction("Successfully exchanged USDT to BTC: " + to_string(amountUSDT) + "USDT" + "ON" + to_string(ethAmount) + "ETH");
		}
		else {
			cerr << "Insufficient USDT balance for exchange\n";
			logtransaction("Insufficient USDT balance for exchange ETH");
		}
	}
	double gettotalbalance() const
	{
		return totalbalance;
	}
	double getbtcbalance() const {
		return btcbalance;
	}
	double gettrcbalance() const {
		return trcbalance;
	}
	double getethbalance() const {
		return ethbalance;
	}
	double findtotalbalance() {
		totalbalance = findbtcdollar() + findusdtdollar() + findethdollar();
		return totalbalance;
	}

	double findbtcdollar() {
		double btcdollar = btcbalance * btcrate;
		return btcdollar;
	}
	double findbtcsentdollarammount(double ammount) {
		double btcdollar = ammount * btcrate;
		return btcdollar;
	}
	double findusdtdollar() {
		double usdtdollar = trcbalance * usdtrate;
		return usdtdollar;
	}
	double findusdtsentdollarammount(double ammount) {
		double usdtdollar = ammount * usdtrate;
		return usdtdollar;
	}
	double findethdollar() {
		double ethdollar = ethbalance * ethrate;
		return ethdollar;
	}
	double findethsentdollarammount(double ammount) {
		double ethdollar = ammount * ethrate;
		return ethdollar;
	}
	//void displayBalances()  {
	//	double btcdollar = findbtcdollar();
	//	double usdtdollar = findusdtdollar();
	//	double ethdollar = findethdollar();
	//	cout << "TOTAL BALANCE: " << findtotalbalance() << "$" << endl;
	//	cout << "BTC Balance: " << btcbalance << " BTC (" << btcdollar << " $)" << endl;  //TEST
	//	cout << "USDT Balance: " << trcbalance << " USDT (" << usdtdollar << " $)" <<endl;
	//	cout << "ETH Balance: " << ethbalance << " ETH (" << ethdollar << " $)" << endl;
	//}
	void sendbtc(double ammount) {
		if (btcbalance <= ammount)
		{
			cerr << "Insufficient funds";
			logtransaction("Insufficient funds of BTC");
		}
		else
		{
			btcbalance -= ammount;
			double btctodollarrrr = findbtcsentdollarammount(ammount);
			cout << "Transaction succesfully sent";
			logtransaction("Transaction succesfull (sent) : " + to_string(ammount)+ "BTC" +"(" + to_string(btctodollarrrr) + ")$");
		}
		
	}
	void topupbtc(double ammount) {
		btcbalance += ammount;
		cout << "Succesfully top-uped your balance " << ammount << " BTC ";
		logtransaction("Wallet succesfully topuped by: " + to_string(ammount) + "BTC");
	}
	void sendtrc(double ammount) {
		if (trcbalance <= ammount)
		{
			cerr << "Insufficient funds";
			logtransaction("Insufficient funds of USDT");
		}
		else
		{
			trcbalance -= ammount;
			cout << "Transaction succesfully sent";
			logtransaction("Transaction succesfull (sent) : " + to_string(ammount) + "USDT");
		}
	}
	void topuptrc(double ammount) {
		trcbalance += ammount;
		cout << "Succesfully top-uped your balance " << ammount << " USDT ";
		logtransaction("Wallet succesfully topuped by: " + to_string(ammount) + "USDT");
	}
	void sendeth(double ammount) {
		if (ethbalance <= ammount)
		{
			cerr << "Insufficient funds";
			logtransaction("Insufficient funds of ETH");
			
		}
		else
		{
			ethbalance -= ammount;
			logtransaction("Transaction succesfull (sent) : " + to_string(ammount) + "ETH");
			
		}
		
	}
	void topupeth(double ammount) {
		ethbalance += ammount;
		cout << "Succesfully top-uped your balance " << ammount << " ETH ";
		logtransaction("Wallet succesfully topuped by: " + to_string(ammount) + "ETH");
	}



};


