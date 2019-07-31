#ifndef QUOTE_H
#define QUOTE_H

#include<iostream>
#include<string>
#include<utility> 

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
	std::string isbn() const { return bookNo; }
	
	virtual double net_price(std::size_t n) const;
	virtual ~Quote() { }
	virtual std::ostream & debug(std::ostream & os) const; 
	
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { std::cout << "Quote(const Quote &q)" << std::endl;  }
	Quote(Quote && q) : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "Quote(Quote && q)" << std::endl; }
	Quote & operator=(const Quote &);
	Quote & operator=(Quote &&);
	
private:
	std::string bookNo;

protected:
	double price = 0.0;
};

class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string & book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }
	
	std::ostream & debug(std::ostream & os) const override;
	double net_price(std::size_t) const = 0;
	
	Disc_quote(const Disc_quote &q) : Quote(q), quantity(q.quantity), discount(q.discount) { std::cout << "Disc_quote(const Disc_quote &q)" << std::endl; }
	Disc_quote(Disc_quote && q) : Quote(std::move(q)), quantity(std::move(q.quantity)), discount(std::move(q.discount)) { std::cout << "Disc_quote(Disc_quote && q)" << std::endl; }
	Disc_quote & operator=(const Disc_quote &);
	Disc_quote & operator=(Disc_quote &&);
	
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
}; 

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string & book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) { }
	
	double net_price(std::size_t) const override;
	
	Bulk_quote(const Bulk_quote &q) : Disc_quote(q) { std::cout << "Bulk_quote(const Bulk_quote &q)" << std::endl; }
	Bulk_quote(Bulk_quote && q) : Disc_quote(std::move(q)) { std::cout << "Bulk_quote(Bulk_quote && q)" << std::endl; }
	Bulk_quote & operator=(const Bulk_quote &);
	Bulk_quote & operator=(Bulk_quote &&);
	
};

double print_total(std::ostream & os, const Quote & item, std::size_t cnt);

#endif


