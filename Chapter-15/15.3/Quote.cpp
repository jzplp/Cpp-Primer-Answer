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
