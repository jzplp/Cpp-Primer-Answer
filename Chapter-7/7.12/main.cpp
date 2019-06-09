#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data s1;
	Sales_data s2("123");
	Sales_data s3("123", 1, 2);
	Sales_data s4(std::cin);
	
	print(std::cout, s1) << std::endl;
	print(std::cout, s2) << std::endl;
	print(std::cout, s3) << std::endl;
	print(std::cout, s4) << std::endl;
	
	return 0;
} 

