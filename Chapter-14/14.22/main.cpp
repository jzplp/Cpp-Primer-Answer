#include <iostream>
#include "Sales_data.h"

int main()
{
	Sales_data a("123");
	a = std::string("12345");
	std::cout << a << std::endl;
	return 0;
} 
