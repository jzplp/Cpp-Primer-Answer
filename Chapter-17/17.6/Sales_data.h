#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <utility>

struct Sales_data;

Sales_data operator+(const Sales_data & sa, const Sales_data & sb);
std::istream & operator>>(std::istream & is, Sales_data & sa); 
std::ostream & operator<<(std::ostream & os, const Sales_data & sa);
bool operator==(const Sales_data &lhs, const Sales_data &rhs); 
bool operator!=(const Sales_data &lhs, const Sales_data &rhs);
bool compareIsbn(const Sales_data & lhs, const Sales_data & rhs);

template <typename T> class std::hash;

class Sales_data
{
friend class std::hash<Sales_data>;
friend Sales_data operator+(const Sales_data & sa, const Sales_data & sb);
friend std::istream & operator>>(std::istream & is, Sales_data & sa); 
friend std::ostream & operator<<(std::ostream & os, const Sales_data & sa);
friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
public:
	
	Sales_data() = default;
	Sales_data(const std::string &s) : ISBN(s) { }
	Sales_data(const std::string &s, int a, double t) : ISBN(s), amount(a), totalPrice(t * a) { } 
	Sales_data(std::istream &is) { is >> *this; }
	
	std::string isbn() const { return ISBN; }
	Sales_data & operator+=(const Sales_data & sa);
	Sales_data & operator=(const std::string & s);
	
	explicit operator double() const { return totalPrice; }
	explicit operator std::string() const { return isbn(); }
	
private:
	
	std::string ISBN;
	double totalPrice = 0.0;
	int amount = 0;
	
	inline double avg_price() const; 
};

namespace std
{
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef	Sales_data argument_type;
		size_t operator()(const Sales_data & s) const;
	};
}

struct matches
{
	std::vector<Sales_data>::size_type first;
	std::vector<Sales_data>::const_iterator second;
	std::vector<Sales_data>::const_iterator third;
};

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string & book);
void reportResults(std::istream & in, std::ostream & os, const std::vector<std::vector<Sales_data>> &files);

#endif


