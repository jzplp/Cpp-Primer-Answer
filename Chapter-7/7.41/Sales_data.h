#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include<string>

struct Sales_data;

Sales_data add(const Sales_data & sa, const Sales_data & sb);

std::istream & read(std::istream & is, Sales_data & sa); 

std::ostream & print(std::ostream & os, const Sales_data & sa);

class Sales_data
{
	
friend Sales_data add(const Sales_data & sa, const Sales_data & sb);
friend std::istream & read(std::istream & is, Sales_data & sa); 
friend std::ostream & print(std::ostream & os, const Sales_data & sa);
public:
	
	Sales_data() : Sales_data("", 0.0, 0) { std::cout << "Sales_data()" << std::endl; }
	Sales_data(const std::string &s) : Sales_data(s, 0.0, 0) { std::cout << "Sales_data(const std::string &s)" << std::endl; }
	Sales_data(const std::string &s, int a, double t) : ISBN(s), amount(a), totalPrice(t * a) { std::cout << "Sales_data(const std::string &s, int a, double t)" << std::endl; } 
	Sales_data(std::istream &is) : Sales_data()
	{
		read(is, *this);
		std::cout << "Sales_data(std::istream &is) " << std::endl; 
	}
	
	std::string isbn() const
	{
		return ISBN;
	}
	Sales_data & combine(const Sales_data & sa);
	
private:
	
	std::string ISBN;
	double totalPrice = 0.0;
	int amount = 0;
	
	inline double avg_price() const; 
};

#endif

