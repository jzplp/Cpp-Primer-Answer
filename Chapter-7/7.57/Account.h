#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>

class Account
{
public:
	Account() = default;
	Account(double a) : amount(a) { }
	Account(std::string o, double a) : onwer(o), amount(a) { }
	void calculate() { amount += amount * interestRate; }
	double getAccount() { return amount; } 
	std::string getOnwer() { return onwer; }
	static double rate() { return interestRate; }
	static void rate(double r); 
private:
	std::string onwer;
	double amount = 0;
	static double interestRate;
	static double initRate();
}; 

#endif 
