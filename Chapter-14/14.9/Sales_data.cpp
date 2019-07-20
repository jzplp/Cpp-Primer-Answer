#include <iostream>
#include <string>
#include "Sales_data.h"

Sales_data & Sales_data::operator+=(const Sales_data & sa)
{
	amount += sa.amount;
	totalPrice += sa.totalPrice;
	return *this;
}

inline double Sales_data::avg_price() const
{
	if(amount)
		return totalPrice / amount;
	return 0;
}

Sales_data operator+(const Sales_data & sa, const Sales_data & sb)
{
	Sales_data sum = sa;
	sum += sb;
	return sum;
}

std::istream & operator>>(std::istream & is, Sales_data & sa)
{
	double price = 0;
	is >> sa.ISBN >> sa.amount >> price;
	if(is)
		sa.totalPrice = price * sa.amount;
	else
		sa = Sales_data();
	return is;
}

std::ostream & operator<<(std::ostream & os, const Sales_data & sa)
{
	os << sa.isbn() << " " << sa.amount << " " << sa.totalPrice << " " << sa.avg_price();
	return os;
}

