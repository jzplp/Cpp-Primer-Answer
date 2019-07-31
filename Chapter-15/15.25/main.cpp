#include <iostream>
#include <string>
#include "Quote.h"

int main()
{
	Quote q("qwe", 12);
	q.debug(std::cout) << std::endl;
	Bulk_quote q2("qwe", 12, 10, 0.1);
	q2.debug(std::cout) << std::endl;
	print_total(std::cout, q, 20); 
	print_total(std::cout, q2, 20); 
	return 0;
} 
