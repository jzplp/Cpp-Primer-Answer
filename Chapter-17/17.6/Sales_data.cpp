#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <algorithm> 
#include <numeric>
#include <vector>
#include "Sales_data.h"

Sales_data & Sales_data::operator+=(const Sales_data & sa)
{
	amount += sa.amount;
	totalPrice += sa.totalPrice;
	return *this;
}

Sales_data & Sales_data::operator=(const std::string & s)
{
	ISBN = s;
	totalPrice = 0.0;
	amount = 0;
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

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && lhs.totalPrice == rhs.totalPrice && lhs.amount == rhs.amount;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

namespace std
{
	size_t hash<Sales_data>::operator()(const Sales_data & s) const
	{
		return hash<string>()(s.ISBN) ^ hash<double>()(s.totalPrice) ^ hash<int>()(s.amount);
	}
}

bool compareIsbn(const Sales_data & lhs, const Sales_data & rhs)
{
	return lhs.isbn() < rhs.isbn();
}

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files, const std::string & book)
{
	std::vector<matches> ret;
	matches m;
	for(std::vector<std::vector<Sales_data>>::const_iterator it = files.cbegin(); it != files.cend(); ++it)
	{
		std::pair<std::vector<Sales_data>::const_iterator, std::vector<Sales_data>::const_iterator> found = std::equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if(found.first != found.second)
		{
			matches m;
			m.first = it - files.cbegin();
			m.second = found.first;
			m.third = found.second;
			ret.push_back(m);
		}
	}
	return ret;
}

void reportResults(std::istream & in, std::ostream & os, const std::vector<std::vector<Sales_data>> &files)
{
	std::string s;
	while(in >> s)
	{
		std::vector<matches> trans = findBook(files, s);
		if(trans.empty())
		{
			std::cout << s << " not found in any stores" << std::endl;
			continue;
		}
		for(const matches & store : trans)
			os << "store " << store.first << " sales: " << std::accumulate(store.second, store.third, Sales_data(s)) << std::endl;
	}
}
