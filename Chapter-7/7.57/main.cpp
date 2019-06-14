#include<iostream>
#include<string>
#include "Account.h" 

int main()
{
	Account a1("qwe", 123);
	std::cout << a1.getOnwer() << " " << a1.getAccount() << " " << a1.rate() << std::endl;
	Account::rate(1.0);
	a1.calculate();
	std::cout << a1.getOnwer() << " " << a1.getAccount() << " " << a1.rate() << std::endl;
	return 0;
} 





