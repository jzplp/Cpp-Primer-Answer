#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
	Sales_data total(std::cin);
	if(std::cin)
	{
		Sales_data trans;
		while(std::cin >> trans)
		{
			if(total.isbn() == trans.isbn())
				total += trans;
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else
	{
		std::cerr << "No data?!" <<std::endl;
		return -1;
	}
	return 0;
} 
