#include <iostream>
#include <string>
#include "Quote.h"

int main()
{
	Quote q("qwe", 12);
	print_total(std::cout, q, 10);
	return 0;
}