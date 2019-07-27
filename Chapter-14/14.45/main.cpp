#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data total(std::cin);
	std::cout << std::string(total) << std::endl;
	std::cout << double(total) << std::endl; 
	return 0;
}


