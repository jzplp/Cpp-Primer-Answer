#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data a(std::cin);
	Sales_data b(std::cin);
	std::cout << (a == b) << std::endl;
	return 0;
}