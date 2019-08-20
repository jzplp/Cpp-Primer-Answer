#include<iostream>
#include<vector>
#include<string>
#include "Sales_data.h"

int main()
{
	std::vector<std::vector<Sales_data>> file { 
		{Sales_data("1023", 4, 2), Sales_data("123", 4, 5), Sales_data("234", 4, 6), Sales_data("234", 4, 7), Sales_data("235", 4, 6)}, 
		{Sales_data("1023", 4, 2), Sales_data("123", 4, 5), Sales_data("234", 4, 5), Sales_data("235", 4, 5), Sales_data("235", 4, 5)} 
	};
	reportResults(std::cin, std::cout, file);
	
	return 0;
} 

