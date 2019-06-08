#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include<string>

struct Sales_data
{
	std::string ISBN;
	double totalPrice;
	int amount;	
	std::string isbn() const
	{
		return ISBN;
	}
	Sales_data & combine(const Sales_data & sa);
	double avg_price() const; 
};

Sales_data add(const Sales_data & sa, const Sales_data & sb);

std::istream & read(std::istream & is, Sales_data & sa); 

std::ostream & print(std::ostream & os, const Sales_data & sa);

#endif

