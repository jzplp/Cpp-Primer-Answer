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
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
} 

double Spec_quote::net_price(std::size_t cnt) const
{
		if(cnt <= min_qty)
		return cnt * (1 - discount) * price;
	else
		return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
}
