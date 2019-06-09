#include <iostream>
#include <string>
#include "Sales_data.h"

Sales_data & Sales_data::combine(const Sales_data & sa)
{
	amount += sa.amount;
	totalPrice += sa.totalPrice;
	return *this;
}

double Sales_data::avg_price() const
{
	if(amount)
		return totalPrice / amount;
	return 0;
}

Sales_data add(const Sales_data & sa, const Sales_data & sb)
{
	Sales_data sum = sa;
	sum.combine(sb);
	return sum;
}

std::istream & read(std::istream & is, Sales_data & sa)
{
	double price = 0;
	is >> sa.ISBN >> sa.amount >> price;
	sa.totalPrice = price * sa.amount;
	return is;
}

std::ostream & print(std::ostream & os, const Sales_data & sa)
{
	os << sa.isbn() << " " << sa.amount << " " << sa.totalPrice << " " << sa.avg_price();
	return os;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}
