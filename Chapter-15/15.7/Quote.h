#ifndef QUOTE_H
#define QUOTE_H

#include<iostream>
#include<string>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	
	virtual double net_price(std::size_t n) const;
	virtual ~Quote() = default;

private:
	std::string bookNo;

protected:
	double price = 0.0;
		
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string & book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
	
	double net_price(std::size_t ) const override;
	
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double print_total(std::ostream & os, const Quote & item, std::size_t cnt);

class Spec_quote : public Quote
{
public:
	Spec_quote() = default;
	Spec_quote(const std::string & book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
	
	double net_price(std::size_t ) const override;
	
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

#endif
