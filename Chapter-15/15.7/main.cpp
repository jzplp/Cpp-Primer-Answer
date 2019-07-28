#include <iostream>
#include <string>
#include "Quote.h"

int main()
{
	Quote q("qwe", 12);
	Bulk_quote q2("qwe", 12, 10, 0.1);
	Spec_quote q3("qwe", 12, 10, 0.1);
	print_total(std::cout, q, 20); 
	print_total(std::cout, q2, 20);
	print_total(std::cout, q3, 20); 
	
	return 0;
} 
