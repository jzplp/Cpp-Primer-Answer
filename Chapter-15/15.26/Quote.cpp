#include<utility> 
#include "Quote.h"

double Quote::net_price(std::size_t n) const
{
	return n * price;
}

double print_total(std::ostream & os, const Quote & item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

double Bulk_quote::net_price(std::size_t cnt) const
{
	if(cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
} 

std::ostream & Quote::debug(std::ostream & os) const
{
	os << bookNo << " " << price;
	return os;
}

std::ostream & Disc_quote::debug(std::ostream & os) const
{
	Quote::debug(os) << " " << quantity << " " << discount;
	return os;
}

Quote & Quote::operator=(const Quote & rhs)
{
	std::cout << "Quote & Quote::operator=(const Quote & rhs)" << std::endl;
	bookNo = rhs.bookNo;
	price = rhs.price;
	return *this;
}

Quote & Quote::operator=(Quote && rhs)
{
	std::cout << "Quote & Quote::operator=(Quote && rhs)" << std::endl;
	bookNo = std::move(rhs.bookNo);
	price = std::move(rhs.price);
	return *this;
}

Disc_quote & Disc_quote::operator=(const Disc_quote & rhs)
{
	Quote::operator=(rhs);
	std::cout << "Disc_quote & Disc_quote::operator=(const Disc_quote & rhs)" << std::endl;
	quantity = rhs.quantity;
	discount = rhs.discount;
	return *this; 
} 

Disc_quote & Disc_quote::operator=(Disc_quote && rhs)
{
	Quote::operator=(std::move(rhs));
	std::cout << "Disc_quote & Disc_quote::operator=(Disc_quote && rhs)" << std::endl;
	quantity = rhs.quantity;
	discount = rhs.discount;
	return *this; 
}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)
{
	Disc_quote::operator=(rhs);
	std::cout << "Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)" << std::endl;
	return *this; 
}

Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs)
{
	Disc_quote::operator=(std::move(rhs));
	std::cout << "Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs)" << std::endl;
	return *this;
}
