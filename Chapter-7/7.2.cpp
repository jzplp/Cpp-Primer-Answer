#include<iostream>
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
};

Sales_data & Sales_data::combine(const Sales_data & sa)
{
	amount += sa.amount;
	totalPrice += sa.totalPrice;
	return *this;
}

