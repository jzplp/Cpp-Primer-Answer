#include <iostream>
#include <string>
#include<vector>
#include "Quote.h"

int main()
{
	std::vector<Quote> v;
	v.push_back(Quote("qwe", 10));
	v.push_back(Bulk_quote("wer", 10, 10, 0.2));
	double sum = 0;
	for(std::vector<Quote>::const_iterator ip = v.cbegin(); ip != v.cend(); ++ip)
	{
		std::cout << ip->net_price(20) << std::endl;
		sum += ip->net_price(20); 
	}
	std::cout << sum << std::endl;
	return 0;
} 

